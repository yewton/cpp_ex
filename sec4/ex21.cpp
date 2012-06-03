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
        int score;
        cout << "input score:" << endl;
        cin >> score;
        vector<int>::iterator i = find(scores.begin(), scores.end(), score);
        if (i != scores.end())
            for (; (i = find(i, scores.end(), score)) != scores.end(); ++i) {
                cout << "name: " << names[i - scores.begin()] << endl;
            }
        else
            cout << "score not found" << endl;
    }
    return 0;
}
