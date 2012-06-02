#include "../std_lib_facilities.h"
#include<algorithm>

pair<string, int> calc_mode(vector<string> &v) {
    vector<string> uv(v);
    sort(uv.begin(), uv.end());
    uv.erase(unique(uv.begin(), uv.end()), uv.end());
    string mode = "";
    int max_count = 0;
    for(vector<string>::iterator it = uv.begin(); it != uv.end(); ++it) {
        int c = count(v.begin(), v.end(), *it);
        if (max_count < c) {
            mode = *it;
            max_count = c;
        }
    }
    return pair<string, int>(mode, max_count);
}

int main(int argc, char *argv[])
{
    istream_iterator<string> sit(cin);
    istream_iterator<string> eos;

    vector<string> v;
    while(sit != eos) {
        v.push_back(*sit);
        ++sit;
    }
    pair<string, int> m = calc_mode(v);
    cout << "mode: " << m.first << "(" << m.second << ")" << endl;
    cout << "max: " << *max_element(v.begin(), v.end()) << endl;
    cout << "min: " << *min_element(v.begin(), v.end()) << endl;
    return 0;
}
