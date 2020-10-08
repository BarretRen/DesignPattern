class Application : public Library
{
protected:
    virtual bool Step2()
    {
        //... 子类重写方法
    }

    virtual void Step4()
    {
        //... 子类重写方法
    }
};

int main()
{
    Library *pLib = new Application();
    lib->Run();

    delete pLib;
}
}
