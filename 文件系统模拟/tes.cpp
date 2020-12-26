#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
    map<string, string> comd;
    comd["mkdir"] = "Mkdir()";
    comd["dir"] = "Dir()";
    comd["cd"] = "Cd()";
    comd["create"] = "Create()";
    comd["read"] = "Read()";
    comd["write"] = "Write()";
    comd["del"] = "Del()";
    comd["help"] = "Help()";
    comd["exit"] = "Exit()";
    cout<<comd["exit"]<<endl;
    return 0;
}
