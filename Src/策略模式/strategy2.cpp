class Context;

class TaxStrategy
{
public:
    virtual double Calculate(const Context &context) = 0;
    virtual ~TaxStrategy() {}
};

class CNTax : public TaxStrategy
{
public:
    virtual double Calculate(const Context &context)
    {
        //***********
    }
};

class USTax : public TaxStrategy
{
public:
    virtual double Calculate(const Context &context)
    {
        //***********
    }
};

class DETax : public TaxStrategy
{
public:
    virtual double Calculate(const Context &context)
    {
        //***********
    }
};

//扩展
//*********************************
class FRTax : public TaxStrategy
{
public:
    virtual double Calculate(const Context &context)
    {
        //.........
    }
};

class SalesOrder
{
private:
    TaxStrategy *strategy;//基类指针，用于多态调用

public:
    SalesOrder(StrategyFactory *strategyFactory)
    {//赋值具体的子类对象
        this->strategy = strategyFactory->NewStrategy();
    }
    ~SalesOrder()
    {
        delete this->strategy;
    }

public:
    double CalculateTax()
    {
        //...
        Context context();

        double val = strategy->Calculate(context); //多态调用
        //...
    }
};
