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
      return Response::ok(
          "Server is healthy."
          );
    };
  routes_["/echo"] = 
    [](const Request& request)
    {
      return Response::ok(request.body);
    };
  
  routes_["/api/health"] =
    [](const Request&)
    {
      return Response::ok(
          R"({

              "status": "ok",
              "server":"cpp-http",
              "version":"1.0"
          })",
          "application/json");
    };
}

Response Router::route(const Request& request) const 
{

  if(request.method != "GET" && 
      request.method != "POST")
  {
    return Response::method_not_allowed("Only GET and POST is supported.");
  }
  auto it = routes_.find(request.path);
  if(it != routes_.end())
  {
    return it->second(request);
  }
  return StaticFileHandler::serve(request.path);

}
