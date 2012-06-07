#include "../std_lib_facilities.h"
#include <time.h>

typedef vector<char> cv;
struct PrintChar : public unary_function<const char, void> {
    void operator()(const char c) const {
        cout << c << ", ";
    }
};

int count_bulls(vector<char> &rans, vector<char> &ans) {
    int result = 0;
    for(cv::iterator i = rans.begin(); i != rans.end(); ++i) {
        int idx = i - rans.begin();
        if (ans[idx] == *i) ++result;
    }
    return result;
}

int count_bulls_and_cows(vector<char> &rans, vector<char> &ans) {
    int result = 0;
    for(cv::iterator i = rans.begin(); i != rans.end(); ++i)
        if(find(ans.begin(), ans.end(), *i) != ans.end()) ++result;
    return result;
}

int main() {
    vector<char> rans;
    srand((unsigned) time(NULL));
    rans.reserve(4);
    rans.push_back('A' + randint(26));
    rans.push_back('A' + randint(26));
    rans.push_back('A' + randint(26));
    rans.push_back('A' + randint(26));

    for(;;) {
        vector<char> ans;
        ans.reserve(4);
        cout << "> ";
        while((ans.size() != 4)) {
            char c;
            cin >> c;
            if (!cin) break;
            ans.push_back(c);
        }
        if (!cin) break;
        int bulls = count_bulls(rans, ans);
        if (bulls == 4) {
            cout << "BINGO!" << endl;
            break;
        }
        int cows = count_bulls_and_cows(rans, ans) - bulls;
        cout << bulls << " bull(s) and " << cows << " cow(s)." << endl;
        ans.clear();
    }
    return 0;
}
