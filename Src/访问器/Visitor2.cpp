#include <iostream>
using namespace std;

class Visitor;

class Element
{
public:
    virtual void accept(Visitor &visitor) = 0; //第一次多态辨析

    virtual ~Element() {}
};

class ElementA : public Element
{
public:
    void accept(Visitor &visitor) override
    {
        visitor.visitElementA(*this);
    }
};

class ElementB : public Element
{
public:
    void accept(Visitor &visitor) override
    {
        visitor.visitElementB(*this); //第二次多态辨析
    }
};
//=======上面的基类和子类不改变，由Visitor来添加新的处理===
class Visitor
{
public:
    virtual void visitElementA(ElementA &element) = 0;
    virtual void visitElementB(ElementB &element) = 0;

    virtual ~Visitor() {}
};
//扩展1，添加新的处理
class Visitor1 : public Visitor
{
public:
    void visitElementA(ElementA &element) override
    {
        cout << "Visitor1 is processing ElementA" << endl;
    }

    void visitElementB(ElementB &element) override
    {
        cout << "Visitor1 is processing ElementB" << endl;
    }
};
//扩展2，添加新的处理
class Visitor2 : public Visitor
{
public:
    void visitElementA(ElementA &element) override
    {
        cout << "Visitor2 is processing ElementA" << endl;
    }

    void visitElementB(ElementB &element) override
    {
        cout << "Visitor2 is processing ElementB" << endl;
    }
};

int main()
{
    Visitor2 visitor;
    ElementB elementB;
    elementB.accept(visitor); //两次多态辨析

    ElementA elementA;
    elementA.accept(visitor);//两次多态辨析

    return 0;
}