#include "../std_lib_facilities.h"
#include <map>

typedef int (*func)(int, int);

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int divide(int a, int b) { return a / b; }
int mul(int a, int b) { return a * b; }

static map<string, int> str2num;

void init(map<char, pair<string, func> > &mapChar) {
    mapChar['+'] = pair<string, func>("sum", &add);
    mapChar['-'] = pair<string, func>("sub", &sub);
    mapChar['/'] = pair<string, func>("div", &divide);
    mapChar['*'] = pair<string, func>("mul", &mul);

    str2num["1"] = str2num["one"]   = 1;
    str2num["2"] = str2num["two"]   = 2;
    str2num["3"] = str2num["three"] = 3;
    str2num["4"] = str2num["four"]  = 4;
    str2num["5"] = str2num["five"]  = 5;
    str2num["6"] = str2num["six"]   = 6;
    str2num["7"] = str2num["seven"] = 7;
    str2num["8"] = str2num["eight"] = 8;
    str2num["9"] = str2num["nine"]  = 9;
}

int main() {
    string a, b;
    char op;
    map<char, pair<string, func> > mapChar;
    pair<string, func> sf;
    init(mapChar);

    cin >> a >> b >> op;

    if (mapChar.find(op) == mapChar.end()) {
        cout << "Invalid operator: " << op << endl;
        return 1;
    }
    sf = mapChar[op];
    if (str2num.find(a) == str2num.end() ||
        str2num.find(b) == str2num.end()) {
        cout << "Invalid operand: " << a << ", " << b << endl;
        return 1;
    }
    cout << "The " << sf.first << " of " << a << " and " << b << " is "
         << (*(sf.second))(str2num[a], str2num[b]) << endl;
    return 0;
}
