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
    vector<int> nums, primes;

    for(int i = 2; i <= 100; ++i) {
        nums.push_back(i);
    }
    for(viit it = nums.begin(); it != nums.end();) {
        printvec(nums);
        cout << *it << endl;
        primes.push_back(*it);
        for(;;) {
            viit i = remove_if(nums.begin(), nums.end(), bind2nd(Sieve(), 2));
            if (i == nums.end()) {
            } else {
                nums.erase(i);
            }
        }
        if ((*(--nums.end())) < ((*it) * (*it))) break;
    }
    printvec(primes); printvec(nums);
    return 0;
}
