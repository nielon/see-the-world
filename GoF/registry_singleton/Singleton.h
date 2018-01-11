#include <string>
#include <map>
class Singleton {
  public:
    static void Register(const std::string& name, Singleton*);
    static Singleton* Instance();
  protected:
    static Singleton* Lookup(const std::string name);
  private:
    static Singleton* _instance;
    static std::map<std::string, Singleton*> _registry;
};
