#include "example/echo.grpc.pb.h"
#include <grpc++/channel.h>
#include <grpc++/client_context.h>
#include <grpc++/create_channel.h>
#include <grpc++/security/credentials.h>
#include <iostream>
#include <memory>
#include <string>

using grpc::Channel;
using grpc::ClientContext;
using grpc::CreateChannel;
using grpc::InsecureChannelCredentials;
using grpc::Status;
using echo::EchoRequest;
using echo::EchoResponse;
using echo::EchoService;

class EchoClient {
public:
  EchoClient(std::shared_ptr<Channel> channel)
      : stub_(EchoService::NewStub(channel)) {}

  std::string echo(const std::string &text) {
    EchoRequest req;
    req.set_text(text);
    EchoResponse res;
    ClientContext context;
    Status status = stub_->echo(&context, req, &res);
    if (status.ok()) {
      return res.result();
    } else {
      std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
      return "RPC failed";
    }
  }

private:
  std::unique_ptr<EchoService::Stub> stub_;
};

int main(int argc, char *argv[]) {
  EchoClient client(
      CreateChannel("localhost:50051", InsecureChannelCredentials()));
  std::string text;
  while (std::getline(std::cin, text)) {
    auto reply = client.echo(text);
    std::cout << "Received: " << reply << std::endl;
  }
  return 0;
}
