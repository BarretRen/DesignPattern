//目标接口（新接口）
class ITarget
{
public:
    virtual void process() = 0;
};

//遗留接口（老接口）
class IAdaptee
{
public:
    virtual void foo(int data) = 0;
    virtual int bar() = 0;
};

//遗留类
class OldClass : public IAdaptee
{
    //....
};

//对象适配器
class Adapter : public ITarget //继承目标类
{
protected:
    IAdaptee *pAdaptee; //组合遗留不兼容类

public:
    Adapter(IAdaptee *pAdaptee)
    {
        this->pAdaptee = pAdaptee;
    }

    virtual void process()
    { //兼容转换代码部分
        int data = pAdaptee->bar();
        pAdaptee->foo(data);
    }
};

int main()
{
    IAdaptee *pAdaptee = new OldClass();

    ITarget *pTarget = new Adapter(pAdaptee);
    pTarget->process();
}

//另一种：类适配器
class Adapter : public ITarget,
                protected OldClass
{
    //多继承，重载类方法
};
