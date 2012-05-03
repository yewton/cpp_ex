#include "../std_lib_facilities.h"

// 円、ユーロ、ポンドをドルに変換するプログラム
int main() {
    const double dollar_per_yen = 0.012509;
    const double dollar_per_euro = 1.3371;
    const double dollar_per_pond = 1.5741;

    double amount = 0.;
    char unit = ' ';

    double result = 0;

    cout << "Please enter an amount followed by a unit ('y' for yen, 'u' for euro or 'p' for pond): ";

    cin >> amount >> unit;

    if (unit == 'y')
        result = dollar_per_yen * amount;
    else if (unit == 'u')
        result = dollar_per_euro * amount;
    else if (unit == 'p')
        result = dollar_per_pond * amount;
    else {
        cout << "Sorry, I don't know a unit called '" << unit << "'" << endl;
        return 1;
    }

    cout << result << " dollars." << endl;
    return 0;
}
