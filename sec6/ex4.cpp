#include "../std_lib_facilities.h"

struct Name_value;
struct Name_value {
    string name;
    int value;
    typedef struct _name_eq {
        string s;
        _name_eq(string s) : s(s) {}
        bool operator()(const Name_value &nv) const {
            return s == nv.name;
        }
    } name_eq;
    Name_value() : name("NoName"), value(0) {}
    Name_value(string name) : name(name), value(0) {}
    Name_value(string name, int value) : name(name), value(value) {}
};

int main() {
    vector<Name_value> nv;
    {
        string name;
        int score;
        for(;;) {
            cout << "name: ";
            cin >> name;
            cout << "score: ";
            cin >> score;
            if ("NoName" == name && 0 == score) break;
            if (find_if(nv.begin(), nv.end(), Name_value::name_eq(name)) != nv.end()) {
                error("duplicate name: " + name);
            }
            nv.push_back(Name_value(name, score));
        }
    }
    {
        for(vector<Name_value>::iterator i = nv.begin(); i != nv.end(); ++i)
            cout << i->name << ", " << i->value << endl;
    }
    return 0;
}
