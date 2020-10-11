class ISubject
{
public:
    virtual void process();
};

//Proxy的设计
class SubjectProxy : public ISubject
{
public:
    virtual void process()
    {
        //对RealSubject的一种间接访问
        //....很多操作
    }
};

class ClientApp
{
private:
    ISubject *subject;

public:
    ClientApp()
    {
        subject = new SubjectProxy();
    }

    void DoTask()
    {
        //...
        subject->process();
        //....
    }
};