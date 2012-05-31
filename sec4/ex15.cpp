#include "../std_lib_facilities.h"

bool is_prime(int n, vector<int> &primes) {
    for(vector<int>::iterator it = primes.begin(); it != primes.end(); ++it) {
        if ((n % (*it)) == 0) return false;
    }
    return true;
}

int main() {
    size_t n;
    cout << "number of primes: ";
    cin >> n;
    if (n < 1) error("should be larger than 0.");

    vector<int> primes;
    primes.reserve(3);
    primes.push_back(2);
    primes.push_back(3);
    primes.push_back(5);

    for(int i = 6; primes.size() < n; ++i) {
        if (is_prime(i, primes)) primes.push_back(i);
    }
    {
        int i = 1;
        for (vector<int>::iterator it = primes.begin(); it != primes.end(); ++it) {
            cout << *it << " ";
            if (i % 10 == 0) cout << endl;
            ++i;
        }
    }
    cout << endl;
    return 0;
}
