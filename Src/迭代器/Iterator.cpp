//这种实现已经过时了
template <typename T>
class Iterator
{
public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() const = 0;
    virtual T &current() = 0;
};

template <typename T>
class MyCollection
{
public:
    Iterator<T>* GetIterator()
    {
        return new CollectionIterator<T>(this);
    }
};

template <typename T>
class CollectionIterator : public Iterator<T>
{
private:
    MyCollection<T> mc;

public:
    CollectionIterator(const MyCollection<T> &c) : mc(c) {}

    void first() override
    {
    }
    void next() override
    {
    }
    bool isDone() const override
    {
    }
    T &current() override
    {
    }
};

int main()
{
    MyCollection<int> mc;

    Iterator<int>* iter = mc.GetIterator();
    //虚函数运行时多态，耗时
    for (*iter.first(); !*iter.isDone(); *iter.next())
    {
        cout << *iter.current() << endl;
    }
}
