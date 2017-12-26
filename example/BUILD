package(default_visibility = ["//visibility:public"])

# proto rules
load("@org_pubref_rules_protobuf//cpp:rules.bzl", "cc_proto_library")
load("@org_pubref_rules_protobuf//python:rules.bzl", "py_proto_library")

# docker image rules
load("@io_bazel_rules_docker//cc:image.bzl", "cc_image")
load("@io_bazel_rules_docker//python:image.bzl", "py_image")

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

cc_image(
    name = "echo_server_image",
    srcs = ["echo_server.cc"],
    deps = [
        ":cc_echo_proto",
    ],
)

cc_binary(
    name = "echo_client",
    srcs = ["echo_client.cc"],
    deps = [
        ":cc_echo_proto",
    ],
)

py_proto_library(
    name = "py_echo_proto",
    protos = ["echo.proto"],
    with_grpc = True,
)

py_binary(
    name = "py_echo_client",
    srcs = ["echo_client.py"],
    main = "echo_client.py",
    deps = [
        ":py_echo_proto"
    ]
)
