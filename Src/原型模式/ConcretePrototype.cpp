//具体类
class BinarySplitter : public ISplitter
{
public:
    virtual ISplitter *clone()
    {
        return new BinarySplitter(*this);//需要拷贝构造函数正确实现
    }
};

class TxtSplitter : public ISplitter
{
public:
    virtual ISplitter *clone()
    {
        return new TxtSplitter(*this);
    }
};

class PictureSplitter : public ISplitter
{
public:
    virtual ISplitter *clone()
    {
        return new PictureSplitter(*this);
    }
};

class VideoSplitter : public ISplitter
{
public:
    virtual ISplitter *clone()
    {
        return new VideoSplitter(*this);
    }
};
