#include "../std_lib_facilities.h"

struct Sieve : binary_function<int,int,bool> {
    bool operator()(int m, int n) const {
        if (m % n == 0) return true;
        return false;
    }
};

typedef vector<int>::iterator viit;

template <class T>
void printvec(vector<T> &vec) {
    int i = 1;
    for (viit it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
        if (i % 10 == 0) cout << endl;
        ++i;
    }
    cout << endl;
}

int main() {
    int max;
    cout << "primes from 1 to : ";
    cin >> max;
    if (max < 1) error("should be larger than 0.");

    vector<int> nums, primes;

    for(int i = 2; i <= max; ++i) {
        nums.push_back(i);
    }
    for(;;) {
        int p = nums.front();
        primes.push_back(p);
        nums.erase(remove_if(nums.begin(), nums.end(), bind2nd(not2(modulus<int>()), p)), nums.end());
        if (nums.back() < (p * p)) break;
    }
    primes.insert(primes.end(), nums.begin(), nums.end());
    printvec(primes);
    return 0;
}
