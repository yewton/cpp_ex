#include "../std_lib_facilities.h"

int main()
{
    cout << "Enter the name of the person you want to write to: ";
    string name = "???";          // ������ϐ�
    cin >> name;          // ������̓ǎ�
    cout << "Dear " << name << ", " << endl;
    return 0;
}
