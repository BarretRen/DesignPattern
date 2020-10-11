class Singleton
{
private:
    //构造函数和拷贝构造函数私有，或C++11 =delete
    Singleton();
    Singleton(const Singleton &other);
    static Singleton *m_instance;

public:
    static Singleton *getInstance();
};
Singleton *Singleton::m_instance = nullptr;

//线程非安全版本
Singleton *Singleton::getInstance()
{
    if (m_instance == nullptr)
    {
        m_instance = new Singleton();
    }
    return m_instance;
}

//线程安全版本，但读操作太多，锁的代价过高
Singleton *Singleton::getInstance()
{
    //lock加锁
    if (m_instance == nullptr)
    {
        m_instance = new Singleton();
    }
    //unlock解锁
    return m_instance;
}
//双检查锁，但由于编译乱序会导致双检查锁失效
Singleton *Singleton::getInstance()
{
    if (m_instance == nullptr)
    {
        //lock加锁
        if (m_instance == nullptr)
        {
            m_instance = new Singleton();
        }
        //unlock解锁
    }
    return m_instance;
}

//C++ 11版本之后的跨平台实现，内存栅栏
std::atomic<Singleton *> Singleton::m_instance;
std::mutex Singleton::m_mutex;
Singleton *Singleton::getInstance()
{
    Singleton *tmp = m_instance.load(std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_acquire); //获取内存fence
    if (tmp == nullptr)
    {
        std::lock_guard<std::mutex> lock(m_mutex); //加锁，lock_guard会自动解锁
        tmp = m_instance.load(std::memory_order_relaxed);
        if (tmp == nullptr)
        {
            tmp = new Singleton;
            std::atomic_thread_fence(std::memory_order_release); //释放内存fence
            m_instance.store(tmp, std::memory_order_relaxed);    //保存到m_instance中
        }
    }
    return tmp;
}
