#include <iostream>
class Singleton
{
  private:
    static Singleton* _instance;
    int m_value;
    ~Singleton() { std::cout << "~Singleton..." << std::endl; };
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
    Singleton();
  public:
    static Singleton* Instance();
    static void DestoryInstance();
    void Print() { std::cout << "m_value is: " << m_value << std::endl; }
    //Singleton(const Singleton&) = delete;
    //Singleton& operator=(const Singleton&) = delete;
    //Singleton(const Singleton&&) = delete;
    //Singleton& operator=(const Singleton&&) = delete;
  private:
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);

};
