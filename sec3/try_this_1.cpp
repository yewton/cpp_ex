#include "../std_lib_facilities.h"

int main()
{
    cout << "Please enter your first name and age" << endl;
    string first_name = "???";          // 文字列変数
    double age = -1.;                    // 整数変数
    cin >> first_name;          // 文字列の読取
    cin >> age;                 // 整数の読取
    cout << "Hello, " << first_name << " (" << (age * 12) << " months)" << endl;
    return 0;
}
