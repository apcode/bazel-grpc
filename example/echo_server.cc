#include "example/echo.grpc.pb.h"
#include <grpc++/security/server_credentials.h>
#include <grpc++/server.h>
#include <grpc++/server_builder.h>
#include <grpc++/server_context.h>
#include <grpc/grpc.h>
#include <iostream>
#include <memory>
#include <string>

using echo::EchoRequest;
using echo::EchoResponse;
using echo::EchoService;
using grpc::InsecureServerCredentials;
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

class EchoServiceImpl final : public EchoService::Service {
public:
  Status echo(ServerContext *context, const EchoRequest *request,
              EchoResponse *response) override {
    response->set_result(request->text());
    return Status::OK;
  }
};

void RunServer() {
  std::string address("0.0.0.0:50051");
  EchoServiceImpl service;
  ServerBuilder builder;
  builder.AddListeningPort(address, InsecureServerCredentials());
  builder.RegisterService(&service);
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << address << std::endl;
  server->Wait();
}

int main(int argc, char *argv[]) {
  RunServer();
  return 0;
}
