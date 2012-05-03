#include "../std_lib_facilities.h"

bool isMatchMaskingWord(vector<string> masks, string word) {
    bool result = false;
    for(vector<string>::iterator it = masks.begin(); it != masks.end(); it++) {
        if (*it == word) {
            result = true;
            break;
        }
    }
    return result;
}

int main() {
    vector<string> masks;
    vector<string> words;
    string tmp;
    cout << "input mask words. type \"\\e\" to stop." << endl;

    while(cin >> tmp) {
        if (tmp == "\\e") break;
        masks.push_back(tmp);
    }

    cout << "input words." << endl;
    while(cin >> tmp) {
        if (isMatchMaskingWord(masks, tmp)) {
            size_t len = tmp.length();
            tmp = "";
            for(size_t i = 0; i < len; i++) {
                tmp += "*";
            }
        }
        words.push_back(tmp);
    }

    for(vector<string>::iterator it = words.begin(); it != words.end(); it++) {
        cout << *it << " ";
    }
    cout << "." << endl;
    return 0;
}
