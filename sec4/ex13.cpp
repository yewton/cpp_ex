#include "../std_lib_facilities.h"

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
    vector<int> nums, primes;

    for(int i = 2; i <= 100; ++i) {
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
