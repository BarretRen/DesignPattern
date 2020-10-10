//抽象类
class ISplitter
{
public:
    virtual void split() = 0;
    virtual ~ISplitter() {}
};

//工厂基类
class SplitterFactory
{
public:
    virtual ISplitter *CreateSplitter() = 0;
    virtual ~SplitterFactory() {}
};

//具体类
class BinarySplitter : public ISplitter
{
};

class TxtSplitter : public ISplitter
{
};

class PictureSplitter : public ISplitter
{
};

class VideoSplitter : public ISplitter
{
};

//具体工厂
class BinarySplitterFactory : public SplitterFactory
{
public:
    virtual ISplitter *CreateSplitter()
    {
        return new BinarySplitter();
    }
};

class TxtSplitterFactory : public SplitterFactory
{
public:
    virtual ISplitter *CreateSplitter()
    {
        return new TxtSplitter();
    }
};

class PictureSplitterFactory : public SplitterFactory
{
public:
    virtual ISplitter *CreateSplitter()
    {
        return new PictureSplitter();
    }
};

class VideoSplitterFactory : public SplitterFactory
{
public:
    virtual ISplitter *CreateSplitter()
    {
        return new VideoSplitter();
    }
};
