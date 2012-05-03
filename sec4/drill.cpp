#include "../std_lib_facilities.h"
#include <algorithm>
#include <map>

#define ALMOST_EQUAL_BORDER (1.0 / 10000000)

#define CM_TO_M(x) (x / 100.)
#define INCH_TO_M(x) (CM_TO_M(x * 2.54))
#define FEET_TO_M(x) (INCH_TO_M(x * 12.))

enum Unit { uCentiMeter,
            uMeter,
            uInch,
            uFeet };

static std::map<string, Unit> mapStringUnit;

static void init() {
    mapStringUnit["cm"] = uCentiMeter;
    mapStringUnit["m"] = uMeter;
    mapStringUnit["in"] = uInch;
    mapStringUnit["ft"] = uFeet;
}

bool is_valid_unit(string unit) {
    return mapStringUnit.find(unit) != mapStringUnit.end();
}

double convert_to_meter(double x, string unit) {
    switch(mapStringUnit[unit]) {
    case uCentiMeter:
        return CM_TO_M(x);
    case uMeter:
        return x;
    case uInch:
        return INCH_TO_M(x);
    case uFeet:
        return FEET_TO_M(x);
    }
    return 0.;
}

int main() {
    double n = 0;
    double m = 0;
    double smallest = 0, largest = 0;
    double sum = 0;
    bool is_set_smallest = false;
    bool is_set_largest = false;
    string u = "";
    vector <double> v;
    init();
    while(cin >> m >> u) {
        if (is_valid_unit(u) == false) {
            cout << "invalid unit: " << u << endl;
            continue;
        }
        n = convert_to_meter(m, u);
        if (n < smallest) {
            if (!is_set_largest && is_set_smallest) {
                largest = smallest;
                is_set_largest = true;
            }
            smallest = n;
            is_set_smallest = true;
        } else if (largest < n) {
            if (!is_set_smallest && is_set_largest) {
                smallest = largest;
                is_set_smallest = true;
            }
            largest = n;
            is_set_largest = true;
        } else {
            if (!is_set_smallest) {
                smallest = n;
                is_set_smallest = true;
            } else if(!is_set_largest) {
                largest = n;
                is_set_largest = true;
            }
        }
        if (is_set_largest && is_set_smallest) {
            cout << m << " " << u;
            if (n == smallest) {
                cout << " is the smallest so far" << endl;
            } else if (n == largest) {
                cout << " is the largest so far" << endl;
            } else {
                cout << endl;
            }
        }
        sum += n;
        cout << "SUM: " << sum << "(m)" << endl;
        v.push_back(n);
    }
    cout << "INPUTS:" << endl;
    sort(v.begin(), v.end());
    for (vector<double>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << ", ";
    }
    cout << endl;
    return 0;
}


