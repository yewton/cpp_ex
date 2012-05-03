#include "../std_lib_facilities.h"

int square(int x) {
    int result = 0;
    for(int i = 1; i <= x; i++) {
        result += x;
    }
    return result;
}

int main() {
    for(int i = 0; i < 10; i++) {
        cout << square(i) << endl;
    }
    return 0;
}
