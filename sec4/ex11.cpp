#include "../std_lib_facilities.h"

bool is_prime(int n, vector<int> &primes) {
    for(vector<int>::iterator it = primes.begin(); it != primes.end(); ++it) {
        if ((n % (*it)) == 0) return false;
    }
    return true;
}

int main() {
    int max;
    cout << "primes from 1 to : ";
    cin >> max;
    if (max < 1) error("should be larger than 0.");

    vector<int> primes_seeds;
    primes_seeds.push_back(2);
    primes_seeds.push_back(3);
    primes_seeds.push_back(5);

    vector<int> primes;
    for (vector<int>::iterator it = primes_seeds.begin(); it != primes_seeds.end(); ++it) {
        if (max < *it) break;
        primes.push_back(*it);
    }
    for(int i = 6; i <= max; ++i) {
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
