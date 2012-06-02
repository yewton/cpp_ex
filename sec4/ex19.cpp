#include "../std_lib_facilities.h"

int main() {
    vector<string> names;
    vector<int> scores;

    {
        string name;
        int score;
        for(;;) {
            cout << "name: ";
            cin >> name;
            cout << "score: ";
            cin >> score;
            if ("NoName" == name && 0 == score) break;
            if (find(names.begin(), names.end(), name) != names.end()) {
                error("duplicate name: " + name);
            }
            names.push_back(name);
            scores.push_back(score);
        }
    }
    {
        vector<string>::iterator i = names.begin();
        vector<int>::iterator j = scores.begin();
        for(; i != names.end() && j != scores.end(); ++i, ++j)
            cout << *i << ", " << *j << endl;
    }
    return 0;
}
