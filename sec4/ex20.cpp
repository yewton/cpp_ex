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
        string name;
        cout << "input name:" << endl;
        cin >> name;
        vector<string>::iterator i;
        if ((i = find(names.begin(), names.end(), name)) != names.end())
            cout << "score: " << scores[i - names.begin()] << endl;
        else
            cout << "name not found" << endl;
    }
    return 0;
}
