#include "../std_lib_facilities.h"

typedef pair<int, int> POI;

typedef enum {
    PERMUTATION,
    COMBINATION,
    DUMMY
} P_OR_C;

POI get_pair_of_int() {
    int a, b;
    cout << "Input total number: ";
    cin >> a;
    if (!cin) error("Invalid number.");

    cout << "Input select number: ";
    cin >> b;
    if (!cin) error("Invalid number.");
    if (a < b) {
        stringstream ss;
        ss << "Invalid input: (" << a << "," << b << ")";
        error(ss.str());
    }
    return POI(a, b);
}

P_OR_C ask_p_or_c() {
    cout << "Type 'P' for permitation or 'C' for combination: ";
    char ans;
    cin >> ans;
    if (!cin) error("Invaid Input:");
    switch(ans) {
    case 'P':
        return PERMUTATION;
    case 'C':
        return COMBINATION;
    default:
        error("Invalid input: " + string(1, ans));
    }
    return DUMMY;
}

double factorial(int n, double ans = 1.) {
    return ((n == 0) || (n == 1)) ? ans : factorial(n - 1., n * ans);
}

double calc_p(int a, int b) {
    return factorial(a) / factorial(a - b);
}

double calc_c(int a, int b) {
    return calc_p(a, b) / factorial(b);
}

int main() {
    POI n = get_pair_of_int();
    P_OR_C porc = ask_p_or_c();
    double result = 0.;
    switch(porc) {
    case PERMUTATION:
        result = calc_p(n.first, n.second);
        break;
    case COMBINATION:
        result = calc_c(n.first, n.second);
        break;
    default:
        break;
    }
    cout << "result: " << result << endl;
    return 0;
}
