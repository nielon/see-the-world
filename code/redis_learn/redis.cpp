#include "redis.h"

int main(void)
{
    struct timeval timeout = {2, 0};    //2s的超时时间
    //redisContext是Redis操作对象
    redisContext *pRedisContext = (redisContext*)redisConnectWithTimeout("10.20.70.135", 6379, timeout);
    if ( (NULL == pRedisContext) || (pRedisContext->err) )
    {
        if (pRedisContext)
        {
            std::cout << "connect error:" << pRedisContext->errstr << std::endl;
        }
        else
        {
            std::cout << "connect error: can't allocate redis context." << std::endl;
        }
        return -1;
    }
    //redisReply是Redis命令回复对象 redis返回的信息保存在redisReply对象中
    redisReply *pRedisReply = (redisReply*)redisCommand(pRedisContext, "PING");  //执行INFO命令
    std::cout << pRedisReply->str << std::endl;
    //当多条Redis命令使用同一个redisReply对象时 
    //每一次执行完Redis命令后需要清空redisReply 以免对下一次的Redis操作造成影响
    freeReplyObject(pRedisReply);   

    msgpack::sbuffer sbufKey;
    {
      const std::string strKey = "RecvDetails:A.0001.0044.R011:51:2016082000";
      msgpack::type::v4raw_ref rr1Key(strKey.data(), strKey.size());
      msgpack::pack(sbufKey, rr1Key);
      std::cout << "sbufKey's size: " << sbufKey.size() << std::endl;
    }
    msgpack::sbuffer sbufField;
    {
      const std::string strField = "liyw";
      msgpack::type::v4raw_ref rr1Field(strField.data(), strField.size());
      msgpack::pack(sbufField, rr1Field);
    }
    msgpack::sbuffer sbufValue;
    {
      DetailInfoEx info;
      info.setDStatus(3);
      msgpack::pack(sbufValue, info);
      std::cout << "sbufValue's size: " << sbufValue.size() << std::endl;
      //std::cout << sbufValue.data() << std::endl; // 非二进制安全的
    }
   
    pRedisReply = (redisReply*)redisCommand(pRedisContext, "HSET %b %b %b", sbufKey.data(), sbufKey.size(), sbufField.data(), sbufField.size(), sbufValue.data(), sbufValue.size());
    {
      if(pRedisReply->type == REDIS_REPLY_INTEGER)
      {
        std::cout << "HSET @ pRedisReply->integer is: " << pRedisReply->integer << std::endl;
      }
      else
      {
	std::cerr << "err: ";
        std::cerr << "HSET @ pRedisReply->type is: " << pRedisReply->type << std::endl;
      }
    }
    freeReplyObject(pRedisReply);   
    
    msgpack::sbuffer sbufField2;
    {
      const std::string strField = "54511";
      msgpack::type::v4raw_ref rr1Field(strField.data(), strField.size());
      msgpack::pack(sbufField2, rr1Field);
    }
    pRedisReply = (redisReply*)redisCommand(pRedisContext, "HGET %b %b", sbufKey.data(), sbufKey.size(), sbufField.data(), sbufField.size());
    {
      if(pRedisReply->type == REDIS_REPLY_NIL)
      {
	std::cerr << "non exist" << std::endl;
      }
      else if(pRedisReply->type == REDIS_REPLY_STRING)
      {
        std::cout << "HGET @ pRedisReply->len is: " << pRedisReply->len << std::endl;
        if( pRedisReply->len > 0)
        {
          msgpack::object_handle oh =
            msgpack::unpack(pRedisReply->str, pRedisReply->len);
          msgpack::object obj = oh.get();
          std::cout << "HGET @ pRedisReply is: " << obj << std::endl;
          DetailInfoEx rInfo;
          obj.convert(rInfo);
        }
      }
      else
      {
	std::cerr << "err: ";
        std::cerr << "HGET @ pRedisReply->type is: " << pRedisReply->type << std::endl;
      }
    }
    freeReplyObject(pRedisReply);   

    redisFree(pRedisContext);
    return 0;
}
