#include <msgpack.hpp>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class DetailInfoEx {
private:
  string staNum{""};  //站号
  string cronStr{""}; //cron
  string dTime{""};   //资料时次
  int dStatus{0};    //1  2  4  8  如果是0 那么需要根据sixtyRecord计算 资料时次 和 此时状态
  int onTime{0};     //相对dTime 延迟秒数
  int yuqiTime{0};   //相对dTime 延迟秒数
  string  sixtyRecord{""};//"000...0"
  string changeTime{""};  // 实际接收时间或实际发送时间
public:
  MSGPACK_DEFINE(staNum, cronStr, dTime, dStatus, onTime, yuqiTime, sixtyRecord, changeTime);
};

int main(void) {
        DetailInfoEx info;
        // add some elements into vec...

        // you can serialize myclass directly
        msgpack::sbuffer sbuf;
        msgpack::pack(sbuf, info);

        msgpack::object_handle oh =
            msgpack::unpack(sbuf.data(), sbuf.size());

        msgpack::object obj = oh.get();
        cout << obj << endl;  //=> ["Hello", "MessagePack"]

        // you can convert object to myclass directly
        DetailInfoEx rInfo;
        obj.convert(rInfo);
}
