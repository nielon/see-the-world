class MeyersSingleton
{
  protected:
    MeyersSingleton();
  public:
    static MeyersSingleton& Instance();
    //MeyersSingleton(const MeyersSingleton&) = delete;
    //MeyersSingleton& operator=(const MeyersSingleton&) = delete;
    
    //MeyersSingleton(const MeyersSingleton&&) = delete;
    //MeyersSingleton& operator=(const MeyersSingleton&&) = delete;
};
