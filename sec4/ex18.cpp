#include "../std_lib_facilities.h"
#include<math.h>
#include<complex>

int main(int argc, char *argv[])
{
    double a, b, c;
    cout << "a * x^2 + b * x + c = 0." << endl;
    cout << "a = ? ";
    cin >> a;
    cout << "b = ? ";
    cin >> b;
    cout << "c = ? ";
    cin >> c;
    cout << "Problem: " << a << " * x^2 + " << b << " * x + " << c << endl;

    double d = (b * b) - (4 * a * c);
    cout << "d = " << d << endl;
    complex<double> r1, r2;
    if (0 < d) {
        r1 = complex<double>(((-b) + sqrt(d)) / (2. * a), 0.);
        r2 = complex<double>(((-b) - sqrt(d)) / (2. * a), 0.);
    } else if (0 == d) {
        r1 = complex<double>((-b) / (2. * a), 0.);
        r2 = r1;
    } else {
        r1 = complex<double>((-b) / (2. * a), sqrt(-d) / (2. * a));
        r2 = conj(r1);
    }
    cout << "result 1: " << r1 << ", result 2: " << r2 << endl;
    return 0;
}
