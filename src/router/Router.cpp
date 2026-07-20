#include "router/Router.hpp"
#include "http/Request.hpp"
#include "http/Response.hpp"
#include "filesystem/FileReader.hpp"
#include "filesystem/StaticFileHandler.hpp"


Router::Router() 
{
  routes_["/health"] =
    [](const Request&)
    {
      return Response(
          200,
          "OK",
          "Server is healthy."
          );
    };
  routes_["/echo"] = 
    [](const Request& request)
    {
      return Response(
          200,
          "OK",
          request.body
          );
    };
}

Response Router::route(const Request& request) const 
{

  if(request.method != "GET" && 
      request.method != "POST")
  {
    return Response(
        405,
        "Method Not Allowed",
        "Only GET and POST are supported."
        );
  }
  auto it = routes_.find(request.path);
  if(it != routes_.end())
  {
    return it->second(request);
  }
  return StaticFileHandler::serve(request.path);

}
