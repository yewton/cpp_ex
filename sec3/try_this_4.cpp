#include "../std_lib_facilities.h"

int main()
{
    string previous = " ";
    string current;
    int n = 0;
    while ( cin >> current ) {
        if ( previous == current ) {
            cout << "repeated word: " << current << endl;
            n++;
        }
        previous = current;
    }
    cout << "duplicate words count: " << n << endl;
    return 0;
}
