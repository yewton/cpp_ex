#include "../std_lib_facilities.h"

int main() {
    int min = 0;
    int max = 100;
    string ans;
    bool s = true;
    for(int i = 0, cand = (min + max) / 2; i < 100; i++, cand = (min + max) / 2) {
        cout << i + 1 << ": Is the number " << cand << "?" << endl;
        cin >> ans;
        if (ans == "y") break;

        if (s) {
            cout << "Is the number smaller than " << cand << "?" << endl;
            cin >> ans;
            if (ans == "y") {
                max = cand;
                s = true;
            } else {
                min = cand;
                s = false;
            }
        } else {
            cout << "Is the number larger than " << cand << "?" << endl;
            cin >> ans;
            if (ans == "y") {
                min = cand;
                s = false;
            } else {
                max = cand;
                s = true;
            }
        }
    }
    return 0;
}
