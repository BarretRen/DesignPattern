class MainForm : public Form
{
    SplitterFactory *factory; //工厂

public:
    MainForm(SplitterFactory *factory)
    {
        this->factory = factory;
    }

    void Button1_Click()
    {
        ISplitter *splitter = factory->CreateSplitter(); //多态new

        splitter->split();
    }
};
