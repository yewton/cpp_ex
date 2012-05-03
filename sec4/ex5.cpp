#include "../std_lib_facilities.h"
#include <map>

typedef double (*func)(double, double);

double add(double a, double b) { return a + b; }
double sub(double a, double b) { return a - b; }
double div(double a, double b) { return a / b; }
double mul(double a, double b) { return a * b; }

void init(map<char, pair<string, func> > &mapChar) {
    mapChar['+'] = pair<string, func>("add", &add);
    mapChar['-'] = pair<string, func>("sub", &sub);
    mapChar['/'] = pair<string, func>("div", &div);
    mapChar['*'] = pair<string, func>("mul", &mul);
}

int main() {
    double a, b;
    char op;
    map<char, pair<string, func> > mapChar;
    pair<string, func> sf;
    init(mapChar);

    cin >> a >> b >> op;

    sf = mapChar[op];
    cout << "The " << sf.first << " of " << a << " and " << b << " is "
         << (*(sf.second))(a, b) << endl;
    return 0;
}
