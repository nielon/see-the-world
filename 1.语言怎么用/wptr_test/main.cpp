#include <memory>
#include <mutex>
#include <atomic>
#include <thread>
#include <functional>
#include <chrono>
#include <string>

using namespace std;

using CallbackT = function<void(const string & data)>;

class Mgr
{
public:
    void set_callback(const CallbackT& cb)
    {
        lock_guard<mutex> lkgd(_mt);
        _cb = cb;
    }
    void run()
    {
        _run.store(true);
        _th = std::thread([this] {
            int count = 0;
            while (_run)
            {
                {
                    lock_guard<mutex> lkgd(_mt);
                    if (_cb)
                        _cb(std::to_string(count));
                }
                ++count;
                this_thread::sleep_for(200ms);
            }
        });
    }
    void stop()
    {
        _run.store(false);
        if (_th.joinable())
        {
            _th.join();
        }
    }
    ~Mgr()
    {
        stop();
    }
private:
    atomic<bool> _run;
    CallbackT _cb;
    mutex _mt;
    thread _th;
};
class Test
{
public:
    Test(shared_ptr<Mgr> ptr): _xx(make_shared<int>())
    {
        weak_ptr<int> wptr = _xx;
        ptr->set_callback([wptr, this](const string& name) {
            if (wptr.expired()) // 引入弱指针避免崩溃
            {
                printf("null task\n");
                return;
            }
            lock_guard<mutex> lkgd(_mt);
            printf("%s \n", name.c_str());
        });
    }
    ~Test()
    {
        lock_guard<mutex> lkgd(_mt);
        printf("~Test\n");
    }
private:
    shared_ptr<int> _xx;
    mutex _mt;
};

int main()
{
    auto mgr = make_shared<Mgr>();
    mgr->run();
    this_thread::sleep_for(1s);
    {
        //Test tt(mgr);   // tt 的内存可能不会马上释放
        auto tt = make_shared<Test>(mgr);
        this_thread::sleep_for(3s);
        // 执行回调时，回调所用的对象已经释放，造成程序崩溃
    }
    getchar();
    return 0;
}