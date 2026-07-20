#include "server/Server.hpp"
#include "server/Connection.hpp"
#include "http/Parser.hpp"
#include "http/Response.hpp"
#include "router/Router.hpp"
#include "server/Middleware.hpp"
#include "logger/Logger.hpp"

#include <iostream>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cerrno>
#include <cstring>
#include <sys/socket.h>


Server::Server(std::uint16_t port)
  :port_{port}
{

}

void Server::start()
{
  create_socket();
  bind_socket();
  start_listening();
  
  while(true)
  {
    try 
    {
      accept_connection();
    }
    catch(const std::exception& exception)
    {
      Logger::error(
          "Connection Error: " +
          std::string(exception.what())
          );
    }
  }
}

void Server::create_socket()
{
  listen_fd_ = ::socket(AF_INET, SOCK_STREAM, 0);
  
  int opt = 1;
  if(::setsockopt(
        listen_fd_,
        SOL_SOCKET,
        SO_REUSEADDR,
        &opt,
        sizeof(opt)
        ) == -1)
  {
    throw std::runtime_error("Failed to set SO_REUSEADDR.");
  }
  if(listen_fd_ == -1)
  {
    throw std::runtime_error("Failed to create socket.");
  }

  Logger::info("Socket created");
}

void Server::bind_socket()
{
  sockaddr_in address{};

  address.sin_family = AF_INET;

  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(port_);

  if(::bind(
        listen_fd_,
        reinterpret_cast<sockaddr*>(&address),
        sizeof(address)) == -1)
  {
    throw std::runtime_error(
        std::string("bind() failed: ") + std::strerror(errno)
        );
  }
  Logger::info(
      "Socket bound to port " + 
      std::to_string(port_)
      );
}

void Server::start_listening()
{
  constexpr int BACKLOG = 10;

  if(::listen(listen_fd_, BACKLOG) == -1)
  {
    throw std::runtime_error("Faield to listen on socket.");
  }

  Logger::info(
      "Listening on port " + 
      std::to_string(port_)
      );
}

void Server::accept_connection()
{
  Logger::info(
      "Waiting for a client..."
      );

  int client_fd = ::accept(listen_fd_, nullptr, nullptr);

  if(client_fd == -1)
  {
    throw std::runtime_error("Failed to accept client.");
  }

  Logger::info(
      "Client connected."
      ) ;

  Connection connection{client_fd};
  std::string raw_request = connection.receive();
  Parser parser;

  Request request = parser.parse(raw_request); 

  Middleware middleware;
  middleware.log_request(request);

  Router router;
  Response response = router.route(request);
  connection.send_response(response.to_string());

  std::cout << "\n========= Parsed Request ==========\n";
  std::cout << "Method  : " << request.method << '\n';
  std::cout << "Path  : " << request.path << '\n';
  std::cout << "Version  : " << request.version << '\n';
  
  std::cout << "\nHeaders\n";

  for(const auto& [key, value] : request.headers)
  {
    std::cout 
      << key 
      << ": "
      << value 
      << '\n';
  }
  std::cout << "=================================\n";

  std::cout<< "\nQuery Parameters\n";

  for(const auto& [key, value] : request.query_params)
  {
    std::cout 
      << key 
      << " = "
      << value 
      << '\n';
  }
  std::cout << "===============================";

  std::cout << "\nBody\n";
  std::cout << request.body << '\n';

  Logger::info(
      "Client disconnected."
      );
}

Server::~Server()
{
  if(listen_fd_ != -1)
  {
    Logger::info(
        "Closing listening socket."
        );
    ::close(listen_fd_);
  }
}
