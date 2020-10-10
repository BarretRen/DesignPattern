//不同的变化方向，分成不同的类：Messager和MessagerImp
class Messager
{
protected:
    MessagerImp *messagerImp; //运行时再确定
public:
    virtual void Login(string username, string password) = 0;
    virtual void SendMessage(string message) = 0;
    virtual void SendPicture(Image image) = 0;

    virtual ~Messager() {}
};

class MessagerImp
{
public:
    virtual void PlaySound() = 0;
    virtual void DrawShape() = 0;
    virtual void WriteText() = 0;
    virtual void Connect() = 0;

    virtual ~MessagerImp() {}
};

//平台实现
class PCMessagerImp : public MessagerImp
{
public:
    virtual void PlaySound()
    {
        //**********
    }
    virtual void DrawShape()
    {
        //**********
    }
    virtual void WriteText()
    {
        //**********
    }
    virtual void Connect()
    {
        //**********
    }
};

class MobileMessagerImp : public MessagerImp
{
public:
    virtual void PlaySound()
    {
        //==========
    }
    virtual void DrawShape()
    {
        //==========
    }
    virtual void WriteText()
    {
        //==========
    }
    virtual void Connect()
    {
        //==========
    }
};

//业务抽象 m
//类的数目：1+n+m
class MessagerLite : public Messager
{
public:
    virtual void Login(string username, string password)
    {
        messagerImp->Connect();
        //........
    }
    virtual void SendMessage(string message)
    {
        messagerImp->WriteText();
        //........
    }
    virtual void SendPicture(Image image)
    {
        messagerImp->DrawShape();
        //........
    }
};

class MessagerPerfect : public Messager
{
public:
    virtual void Login(string username, string password)
    {
        messagerImp->PlaySound();
        //********
        messagerImp->Connect();
        //........
    }
    virtual void SendMessage(string message)
    {
        messagerImp->PlaySound();
        //********
        messagerImp->WriteText();
        //........
    }
    virtual void SendPicture(Image image)
    {
        messagerImp->PlaySound();
        //********
        messagerImp->DrawShape();
        //........
    }
};

void Process()
{
    //运行时装配
    MessagerImp *mImp = new PCMessagerImp();
    Messager *m = new Messager(mImp);
}
