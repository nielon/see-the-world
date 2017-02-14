#include <iostream>
class Singleton
{
  private:
    static Singleton* _instance;
    class Garbo
    {
      public:
	~Garbo()
	{
	  if (_instance != 0) {
	    delete _instance;
	    _instance = 0;
	  }
	}
    };
    static Garbo _garbo;
  protected:
    Singleton() { std::cout << "singleton..." << std::endl; };
    //virtual ~Singleton() { std::cout << "~Singleton..." << std::endl; };
    ~Singleton() { std::cout << "~Singleton..." << std::endl; };
  public:
    static Singleton* Instance(char ch = 0);
  private:
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);
};


class SingletonA:public Singleton
{
  friend class Singleton;
  private:
    SingletonA() { std::cout << "SingletonA..." << std::endl; };
    ~SingletonA() { std::cout << "~SingletonA..." << std::endl; };
};

class SingletonB:public Singleton
{
  friend class Singleton;
  private:
    SingletonB() { std::cout << "SingletonB..." << std::endl; };
    ~SingletonB() { std::cout << "~SingletonB..." << std::endl; };
};

