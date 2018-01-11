class Person
{
  private:
    int id;
    int age;
    static int count;
  public:
    Person():id(1), age(21){ ++count; };
    Person(int idt, int aget):id(idt), age(aget){};
    virtual void print();
    virtual void job();
    static void personCount();
    virtual ~Person();
};

