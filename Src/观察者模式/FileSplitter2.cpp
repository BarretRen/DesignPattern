class IProgress
{
public:
    virtual void DoProgress(float value) = 0;
    virtual ~IProgress() {}
};

class FileSplitter
{
    string m_filePath;
    int m_fileNumber;

    List<IProgress *> m_iprogressList; // ����֪ͨ���ƣ�֧�ֶ���۲���

public:
    FileSplitter(const string &filePath, int fileNumber) : m_filePath(filePath),
                                                           m_fileNumber(fileNumber)
    {
    }

    void split()
    {

        //1.��ȡ���ļ�

        //2.��������С�ļ���д��
        for (int i = 0; i < m_fileNumber; i++)
        {
            //...

            float progressValue = m_fileNumber;
            progressValue = (i + 1) / progressValue;
            onProgress(progressValue); //����֪ͨ
        }
    }

    void addIProgress(IProgress *iprogress)
    {
        m_iprogressList.push_back(iprogress);
    }

    void removeIProgress(IProgress *iprogress)
    {
        m_iprogressList.remove(iprogress);
    }

protected:
    virtual void onProgress(float value)
    {

        List<IProgress *>::iterator itor = m_iprogressList.begin();

        while (itor != m_iprogressList.end())
            (*itor)->DoProgress(value); //���½�����
        itor++;
    }
}
}
;