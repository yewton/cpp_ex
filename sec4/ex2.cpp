#include "../std_lib_facilities.h"

int main() {
    vector<double> temps;
    double temp;
    while(cin >> temp)
        temps.push_back(temp);
    if (temps.size() == 0) return 0;

    double sum = 0;
    for (size_t i = 0; i < temps.size(); i ++) sum += temps[i];
    cout << "Average temperature: " << sum / temps.size() << endl;

    double med = 0;
    size_t n = temps.size();
    sort(temps.begin(), temps.end());
    if(n % 2 == 0) {
        med = (temps[(n / 2) - 1] + temps[(n / 2)]) / 2;
    } else {
        med = (temps[((n + 1) / 2) - 1]);
    }

    cout << "Median temperature: " << med << endl;

    return 0;
}
