# bazel-grpc

A simple bootstrap repo for projects wishing to build [GRPC](https://grpc.io) services.

You can build client and servers in a variety of languages pretty easily.

I'm also adding build rules and support to build [docker
images](https://github.com/bazelbuild/rules_docker) and [kubernetes
deployments](https://github.com/bazelbuild/rules_k8s).

So you should be able to easily create a cluster of GRPC services and
deploy these as a kunernetes cluster all from your bazel build system.
