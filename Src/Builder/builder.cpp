class House
{
    //....
};

class HouseBuilder
{
public:
    House *GetResult() //返回一个House对象
    {
        return pHouse;
    }
    virtual ~HouseBuilder() {}

protected:
    House *pHouse;
    virtual void BuildPart1() = 0;
    virtual void BuildPart2() = 0;
    virtual void BuildPart3() = 0;
    virtual void BuildPart4() = 0;
    virtual void BuildPart5() = 0;
};

class StoneHouse : public House
{
};

class StoneHouseBuilder : public HouseBuilder
{
protected:
    virtual void BuildPart1()
    {
        //pHouse->Part1 = ...;
    }
    virtual void BuildPart2()
    {
    }
    virtual void BuildPart3()
    {
    }
    virtual void BuildPart4()
    {
    }
    virtual void BuildPart5()
    {
    }
};
//稳定的部分
class HouseDirector
{
public:
    HouseBuilder *pHouseBuilder;

    HouseDirector(HouseBuilder *pHouseBuilder) //注入实际的子类对象
    {
        this->pHouseBuilder = pHouseBuilder;
    }

    House *Construct()//按照确定的顺序执行构建过程
    {
        pHouseBuilder->BuildPart1();

        for (int i = 0; i < 4; i++)
        {
            pHouseBuilder->BuildPart2();
        }

        bool flag = pHouseBuilder->BuildPart3();

        if (flag)
        {
            pHouseBuilder->BuildPart4();
        }

        pHouseBuilder->BuildPart5();

        return pHouseBuilder->GetResult();
    }
};
