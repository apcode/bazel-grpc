package(default_visibility = ["//visibility:public"])

load("@org_pubref_rules_protobuf//cpp:rules.bzl", "cc_proto_library")

cc_proto_library(
    name = "cc_echo_proto",
    protos = ["echo.proto"],
    with_grpc = True,
)

cc_binary(
    name = "echo_server",
    srcs = ["echo_server.cc"],
    deps = [
        ":cc_echo_proto",
    ],
)
