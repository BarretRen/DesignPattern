class MainForm : public Form, public IProgress
{
    TextBox *txtFilePath;
    TextBox *txtFileNumber;

    ProgressBar *progressBar;

public:
    void Button1_Click()
    {

        string filePath = txtFilePath->getText();
        int number = atoi(txtFileNumber->getText().c_str());

        ConsoleNotifier cn;

        FileSplitter splitter(filePath, number);

        splitter.addIProgress(this); //添加IProgress的子类对象
        splitter.addIProgress(&cn);  //添加IProgress的子类对象

        splitter.split();

        splitter.removeIProgress(this);
    }

    virtual void DoProgress(float value)
    {
        progressBar->setValue(value);
    }
};

class ConsoleNotifier : public IProgress
{
public:
    virtual void DoProgress(float value)
    {
        std::cout << ".";
    }
};
