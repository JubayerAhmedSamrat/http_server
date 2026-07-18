#include "router/Router.hpp"
#include "http/Request.hpp"
#include "http/Response.hpp"

Response Router::route(const Request& request) const 
{
  if(request.path == "/")
  {
    return Response(
        200,
        "OK",
        "Welcome to my C++ HTTP server!"
        );
  }

  if(request.path == "/health")
  {
    return Response(
        200,
        "OK",
        "Sever is healthy."
        );
  }

  if(request.path == "/echo")
  {
    return Response(
        200, 
        "OK",
        "Echo endpoint."
        );
  }

  return Response(
      404,
      "Not Found",
      "404 Not Found"
      );
}
