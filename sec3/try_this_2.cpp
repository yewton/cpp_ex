#include "../std_lib_facilities.h"

int main()
{
    cout << "Please enter a floating-point value: ";
    int n;
    cin >> n;
    cout << "n == " << n
         << "\nn+1 == " << n + 1
         << "\nthree times n == " << 3 * n
         << "\ntwice n == " << n + n
         << "\nn squared == " << n * n
         << "\nhalf of n == " << n / 2
         << "\nmodulo of n / 2 == " << n % 2
         << "\nsum of modulo of n / 2  and half of n times n == " << ((n / 2) * 2) + (n % 2)
         << "\nsquare root of n == " << sqrt((double)n)
         << endl;
    return 0;
}
