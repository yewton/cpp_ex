#include "../std_lib_facilities.h"

vector<string> nouns;
vector<string> conjs;
vector<string> verbs;

void init() {
    nouns.push_back("birds");
    nouns.push_back("fish");
    nouns.push_back("C++");
    conjs.push_back("and");
    conjs.push_back("or");
    conjs.push_back("but");
    verbs.push_back("rules");
    verbs.push_back("fly");
    verbs.push_back("swim");
}

bool verb() {
    string word;
    cin >> word;
    if (find(verbs.begin(), verbs.end(), word) != verbs.end()) return true;
    return false;
}

bool noun() {
    string word;
    cin >> word;
    if (find(nouns.begin(), nouns.end(), word) != nouns.end()) {
        return true;
    }
    if (word == "the") return noun();
    return false;
}

bool conj() {
    string word;
    cin >> word;
    if (find(conjs.begin(), conjs.end(), word) != conjs.end()) return true;
    return false;
}

bool sentence();
bool sentence() {
    if (noun() && verb()) {
        char ch;
        cin >> ch;
        if (ch == '.') return true;
        cin.putback(ch);
        if (conj() && sentence()) return true;
    }
    return false;
}

int main() {
    init();
    vector<string> words;
    while(cin) {
        if (sentence()) cout << "OK";
        else cout << "not OK";
        cout << endl;
    }
    return 0;
}
