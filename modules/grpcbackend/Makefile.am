AM_CPPFLAGS += $(GRPCPP_CFLAGS) $(PROTOBUF_CFLAGS)

pkglib_LTLIBRARIES = libgrpcbackend.la

EXTRA_DIST = OBJECTFILES OBJECTLIBS

libgrpcbackend_la_SOURCES = \
    grpcbackend.cc grpcbackend.hh \
	pdns_backend.pb.cc pdns_backend.pb.h \
	pdns_backend.grpc.pb.cc pdns_backend.grpc.pb.h

libgrpcbackend_la_LDFLAGS = -module -avoid-version
libgrpcbackend_la_LIBADD = $(GRPCPP_LIBS) $(PROTOBUF_LIBS)
