/*
 * This file is part of PowerDNS or dnsdist.
 * Copyright -- PowerDNS.COM B.V. and its contributors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * In addition, for the avoidance of any doubt, permission is granted to
 * link this program with OpenSSL and to (re)distribute the binaries
 * produced as the result of such linking.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef GRPCBACKEND_HH
#define GRPCBACKEND_HH

#include "pdns/arguments.hh"
#include "pdns/dns.hh"
#include "pdns/dnsbackend.hh"
#include "pdns/dnspacket.hh"
#include "pdns/logger.hh"
#include "pdns/namespaces.hh"
#include "pdns/pdnsexception.hh"
#include "pdns/sstuff.hh"
#include "pdns/ueberbackend.hh"
#include "pdns_backend.grpc.pb.h"

#include <grpc++/grpc++.h>
#include <string>

using grpc::Channel;
using pdnsbackend::BackEnd;

class GrpcBackend : public DNSBackend {
 public:
  GrpcBackend(const std::string& suffix = "");

  bool list( const DNSName& target, int domain_id, bool include_disabled=false );
  void lookup( const QType& qtype, const DNSName& qdomain, DNSPacket* p = 0, int zoneid = -1 );
  bool get( DNSResourceRecord& rr );

 private:
  int index_;
  std::unique_ptr<BackEnd::Stub> stub_;
  std::vector<DNSResourceRecord> rrs_;
};



#endif  // GRPCBACKEND_HH
