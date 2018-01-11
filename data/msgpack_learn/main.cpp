#include <msgpack.hpp>
#include <vector>
#include <string>
#include <iostream>

int main(void) {
  // serializes this object.
  std::string str{"ABC"};
  msgpack::type::v4raw_ref rr1(str.data(), str.size());
  // serialize it into simple buffer.
  msgpack::sbuffer sbuf;
  msgpack::pack(sbuf, rr1);
  
  // deserialize it.
  msgpack::object_handle oh =
    msgpack::unpack(sbuf.data(), sbuf.size());
  
  // print the deserialized object.
  msgpack::type::v4raw_ref obj = oh.get().as<msgpack::type::v4raw_ref>();
  std::cout << obj.str() << std::endl;  //=> ["Hello", "MessagePack"]
  
  // convert it into statically typed object.
  //std::vector<std::string> rvec;
  //obj.convert(rvec);
}
