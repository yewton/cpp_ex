#include "../std_lib_facilities.h"

int main()
{
    cout << "Please enter your first name and age" << endl;
    string first_name = "???";          // ������ϐ�
    double age = -1.;                    // �����ϐ�
    cin >> first_name;          // ������̓ǎ�
    cin >> age;                 // �����̓ǎ�
    cout << "Hello, " << first_name << " (" << (age * 12) << " months)" << endl;
    return 0;
}
