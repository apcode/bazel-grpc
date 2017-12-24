import grpc
import example.echo_pb2
import example.echo_pb2_grpc

def run():
    channel = grpc.insecure_channel('localhost:50051')
    stub = example.echo_pb2_grpc.EchoServiceStub(channel)
    while True:
        text = raw_input("Enter request: ")
        response = stub.echo(example.echo_pb2.EchoRequest(text=text))
        print("Received:", response.result)


if __name__ == '__main__':
    run()
