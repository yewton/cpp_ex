#include "../std_lib_facilities.h"

int main()
{
    cout << "Please enter your first name and age" << endl;
    string first_name = "???";          // •¶š—ñ•Ï”
    double age = -1.;                    // ®”•Ï”
    cin >> first_name;          // •¶š—ñ‚Ì“Çæ
    cin >> age;                 // ®”‚Ì“Çæ
    cout << "Hello, " << first_name << " (" << (age * 12) << " months)" << endl;
    return 0;
}
