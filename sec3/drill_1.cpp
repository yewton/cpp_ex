#include "../std_lib_facilities.h"

int main()
{
    cout << "Enter the name of the person you want to write to: ";
    string name = "???";          // 文字列変数
    cin >> name;          // 文字列の読取
    cout << "Dear " << name << ", " << endl;
    return 0;
}
