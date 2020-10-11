class Font
{
private:
    //unique object key，用于查找指定对象
    string key;
    //object state
    //....

public:
    Font(const string &key)
    {
        //...
    }
};

class FontFactory
{
private:
    map<string, Font *> fontPool; //对象池

public:
    Font *GetFont(const string &key)
    {
        map<string, Font *>::iterator item = fontPool.find(key);

        if (item != footPool.end())
        {
            return fontPool[key];//对象池存在，直接返回
        }
        else
        {//找不到对象，创建新对象返回
            Font *font = new Font(key);
            fontPool[key] = font;
            return font;
        }
    }

    void clear()
    {
        //...
    }
};