#include <msgpack.hpp>
#include <hiredis/hiredis.h>
#include <string>
#include <iostream>

class DetailInfoEx {
private:
  std::string staNum{"54511"};  //站号
  std::string cronStr{"0 * * * * ? *"}; //cron
  std::string dTime{"1991090214"};   //资料时次
  int dStatus{0};    //1  2  4  8  如果是0 那么需要根据sixtyRecord计算 资料时次 和 此时状态
  int onTime{0};     //相对dTime 延迟秒数
  int yuqiTime{0};   //相对dTime 延迟秒数
  std::string  sixtyRecord{"0123456789012345678901234567890123"};//"000...0"
  std::string changeTime{""};  // 实际接收时间或实际发送时间
public:
  void setDStatus(int validity) { dStatus = validity; };
  MSGPACK_DEFINE(staNum, cronStr, dTime, dStatus, onTime, yuqiTime, sixtyRecord, changeTime);
};

/*int main(void) {*/
        //DetailInfoEx info;
        //// you can serialize myclass directly
        //msgpack::sbuffer sbuf;
        //msgpack::pack(sbuf, info);

        //msgpack::object_handle oh =
            //msgpack::unpack(sbuf.data(), sbuf.size());

        //msgpack::object obj = oh.get();
        //cout << obj << endl;

        //// you can convert object to myclass directly
        //DetailInfoEx rInfo;
        //obj.convert(rInfo);
/*}*/
