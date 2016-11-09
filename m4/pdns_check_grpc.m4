AC_DEFUN([PDNS_CHECK_GRPC],[
  PKG_CHECK_MODULES(GRPCPP, grpc++ >= 1.0.0, [], [AC_MSG_FAILURE(grpc++ not found. Plase install grpc or specify the path to the protobuf package in PKG_CONFIG_PATH variable if it was not installed on the default path.)])
  AC_SUBST([GRPCPP_LIBS])
  AC_SUBST([GRPCPP_CFLAGS])

  PKG_CHECK_MODULES(PROTOBUF, protobuf >= 3.0.0, [], [AC_MSG_FAILURE(libprotobuf not found. Plase install libprotobuf-dev or specify the path to the protobuf package in PKG_CONFIG_PATH variable if it was not installed on the default path.)])
  AC_SUBST([PROTOBUF_LIBS])
  AC_SUBST([PROTOBUF_CFLAGS])

  AC_CHECK_PROG([PROTOC], [protoc], [protoc])
  AS_IF([test x"$PROTOC" = "x"], [
      AC_MSG_ERROR([Protobuf requested but the protobuf compiler was not found])
  ])

  AC_ARG_WITH([grpc_cpp_plugin],
    [AS_HELP_STRING([--with-grpc_cpp_plugin=/path/of/grpc_cpp_plugin],
    [Location of the grpc cpp plugin. Defaults to looking on path.])],
    [GRPCCPPPLUGIN="$withval"],
    [AS_IF([test "x${GRPCCPPPLUGIN}" == "x"], [AC_PATH_PROG([GRPCCPPPLUGIN], [grpc_cpp_plugin], [no])])]
  )
  AC_CHECK_FILE("${GRPCCPPPLUGIN}", , [AC_MSG_ERROR([grpc cpp plugin not found. Please install it or specify the binary path using --with-grpc-cpp-plugin if it was not installed on the default path.])])
])
