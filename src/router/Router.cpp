#include "router/Router.hpp"
#include "http/Request.hpp"
#include "http/Response.hpp"
#include "filesystem/FileReader.hpp"


Router::Router() 
{
  routes_["/"] = 
    [](const Request&)
    {
      return Response(
          200,
          "OK",
          FileReader::read("public/index.html"), "text/html"
          );
    };
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
  if(request.method != "GET")
  {
    return Response(
        405,
        "Method Not Allowed",
        "Only GET is supported."
        );
  }

  auto it = routes_.find(request.path);
  if(it != routes_.end())
  {
    return it->second(request);
  }

  return Response(
      404,
      "Not Found",
      "404 Not Found"
      );
}
