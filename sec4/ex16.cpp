#include "../std_lib_facilities.h"
#include<map>

int main(int argc, char *argv[])
{
    istream_iterator<int> iit(cin);
    istream_iterator<int> iit_eof;

    vector<int> v;
    while(iit != iit_eof) {
        v.push_back(*iit);
        ++iit;
    }
    vector<int> uv(v);
    sort(uv.begin(), uv.end());
    uv.erase(unique(uv.begin(), uv.end()), uv.end());
    int mode = 0;
    int max_count = 0;
    for(vector<int>::iterator it = uv.begin(); it != uv.end(); ++it) {
        int c = count(v.begin(), v.end(), *it);
        if (max_count < c) {
            mode = *it;
            max_count = c;
        }
    }
    cout << "mode: " << mode << "(" << max_count << ")" << endl;
    return 0;
}
