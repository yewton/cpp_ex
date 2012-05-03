#include "../std_lib_facilities.h"

// Try this 1 の siwtch 版
int main() {
    const double dollar_per_yen = 0.012509;
    const double dollar_per_euro = 1.3371;
    const double dollar_per_pond = 1.5741;

    double amount = 0.;
    char unit = ' ';

    double result = 0;

    cout << "Please enter an amount followed by a unit ('y' for yen, 'u' for euro or 'p' for pond): ";

    cin >> amount >> unit;

    switch(unit) {
    case 'y':
        result = dollar_per_yen * amount;
        break;
    case 'u':
        result = dollar_per_euro * amount;
        break;
    case 'p':
        result = dollar_per_pond * amount;
        break;
    default:
        cout << "Sorry, I don't know a unit called '" << unit << "'" << endl;
        return 1;
    }

    cout << result << " dollars." << endl;
    return 0;
}
