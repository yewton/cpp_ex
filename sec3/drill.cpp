#include "../std_lib_facilities.h"

int main()
{
    // 1.
    cout << "Enter the name of the person you want to write to: ";
    string to_name = "???";          // •¶Žš—ñ•Ï”
    cin >> to_name;          // •¶Žš—ñ‚Ì“ÇŽæ
    // 3.
    cout << "Enter the name of your friend: ";
    string friend_name = "???";          // •¶Žš—ñ•Ï”
    cin >> friend_name;          // •¶Žš—ñ‚Ì“ÇŽæ
    // 4.
    cout << "Enter gender of your friend(m/f): ";
    char friend_gender = 0;
    cin >> friend_gender;
    // 5.
    cout << "Enter age of the person you want to write to: ";
    int age = 0;
    cin >> age;
    if ( ( age <= 0 ) || ( 110 <= age) ) {
        simple_error("you're kidding!");
    }
    // 7.
    cout << "Enter your name: ";
    string name = "???";          // •¶Žš—ñ•Ï”
    cin >> name;          // •¶Žš—ñ‚Ì“ÇŽæ

    // 1.
    cout << "Dear " << to_name << "," << endl;
    // 2.
    cout << "\tHow are you?" << endl << "I am fine. I miss you." << endl;
    // 3.
    cout << "Have you seen " << friend_name << " lately?" << endl;
    // 4.
    cout << "If you see " << friend_name << " please ask ";
    if ( friend_gender == 'm' ) {
        cout << "him";
    } else if ( friend_gender == 'f' ) {
        cout << "her";
    } else {
        cout << "it";
    }
    cout << " to call me" << endl;
    // 6.
    if ( age < 12 ) {
        cout << "Next year you will be " << age + 1 << endl;
    } else if ( age == 17 ) {
        cout << "Next year you will be able to vote" << endl;
    } else if ( 70 <= age ) {
        cout << "I hope you are enjoying retirement" << endl;
    }
    // 7.
    cout << "Yours sincerely" << endl << endl << endl << name << endl;

    return 0;
}
