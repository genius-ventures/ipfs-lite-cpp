#include <cryptopp/sha.h>
#include <cryptopp/sha3.h>
#include <multihash/algorithm.h>
#include <multihash/code.h>
#include <multihash/detail/cryptopp_impl.h>
#include "detail/cryptopp_impl.h"

namespace multihash {

std::map<code_type, algorithm::factory*> algorithm::factories() {
  static auto result = std::map<code_type, algorithm::factory*>{
      {code::sha1, &detail::cryptopp_factory<CryptoPP::SHA1>::instance()},
      {code::sha2_256, &detail::cryptopp_factory<CryptoPP::SHA256>::instance()},
      {code::sha2_512, &detail::cryptopp_factory<CryptoPP::SHA512>::instance()},
      {code::sha3_256,
       &detail::cryptopp_factory<CryptoPP::SHA3_256>::instance()}};
  return result;
}

std::unique_ptr<algorithm> algorithm::create(code_type code) {
  auto factory = factories().at(code);
  assert(factory);
  return factory->create();
}

std::string algorithm::digest() {
  auto result = std::string(digest_size(), 0);
  auto span = string_span(result);
  digest(span);
  return result;
}

}  // namespace multihash
