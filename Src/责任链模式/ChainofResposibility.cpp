#include <iostream>
#include <string>

using namespace std;

enum class RequestType
{
    REQ_HANDLER1,
    REQ_HANDLER2,
    REQ_HANDLER3
};
//消息请求类
class Reqest
{
private:
    string description;
    RequestType reqType;

public:
    Reqest(const string &desc, RequestType type) : description(desc), reqType(type) {}
    RequestType getReqType() const { return reqType; }
    const string &getDescription() const { return description; }
};

class ChainHandler
{
private:
    ChainHandler *nextChain;//处理请求的对象链表
    void sendReqestToNextHandler(const Reqest &req)
    {//发生请求到下一节点
        if (nextChain != nullptr)
            nextChain->handle(req);
    }

protected:
    //当前对象释放可以处理请求
    virtual bool canHandleRequest(const Reqest &req) = 0;
    virtual void processRequest(const Reqest &req) = 0;

public:
    ChainHandler() { nextChain = nullptr; }
    void setNextChain(ChainHandler *next) { nextChain = next; }

    void handle(const Reqest &req)
    {
        if (canHandleRequest(req))
            processRequest(req);
        else
            sendReqestToNextHandler(req);
    }
};
//子类实现两个虚函数
class Handler1 : public ChainHandler
{
protected:
    bool canHandleRequest(const Reqest &req) override
    {
        return req.getReqType() == RequestType::REQ_HANDLER1;
    }
    void processRequest(const Reqest &req) override
    {
        cout << "Handler1 is handle reqest: " << req.getDescription() << endl;
    }
};
class Handler2 : public ChainHandler
{
protected:
    bool canHandleRequest(const Reqest &req) override
    {
        return req.getReqType() == RequestType::REQ_HANDLER2;
    }
    void processRequest(const Reqest &req) override
    {
        cout << "Handler2 is handle reqest: " << req.getDescription() << endl;
    }
};
class Handler3 : public ChainHandler
{
protected:
    bool canHandleRequest(const Reqest &req) override
    {
        return req.getReqType() == RequestType::REQ_HANDLER3;
    }
    void processRequest(const Reqest &req) override
    {
        cout << "Handler3 is handle reqest: " << req.getDescription() << endl;
    }
};

int main()
{
    Handler1 h1;
    Handler2 h2;
    Handler3 h3;
    h1.setNextChain(&h2);
    h2.setNextChain(&h3);

    Reqest req("process task ... ", RequestType::REQ_HANDLER3);
    h1.handle(req);
    return 0;
}