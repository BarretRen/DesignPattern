#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Command
{
public:
    virtual void execute() = 0;
};
//请求类，可以填充各种信息参数
class ConcreteCommand1 : public Command
{
private:
    string arg;

public:
    ConcreteCommand1(const string &a) : arg(a) {}
    void execute() override
    {
        cout << "#1 process..." << arg << endl;
    }
};

class ConcreteCommand2 : public Command
{
private:
    string arg;

public:
    ConcreteCommand2(const string &a) : arg(a) {}
    void execute() override
    {
        cout << "#2 process..." << arg << endl;
    }
};

class MacroCommand : public Command
{
private:
    vector<Command *> commands;//多个命令组合成宏

public:
    void addCommand(Command *c) { commands.push_back(c); }
    void execute() override
    {
        for (auto &c : commands)
        {
            c->execute();
        }
    }
};

int main()
{
    ConcreteCommand1 command1(receiver, "Arg ###");
    ConcreteCommand2 command2(receiver, "Arg $$$");

    MacroCommand macro;
    macro.addCommand(&command1);
    macro.addCommand(&command2);

    macro.execute();
}