#include "../std_lib_facilities.h"
#include <stack>
#include <queue>

int main() {
    stack<int> d;
    queue<int> q;
    for(int i = 0; i < 4; ++i) {
        char c = cin.get();
        int n = c - '0';
        if (0 <= n && n < 10) {
            d.push(n);
            q.push(n);
        }
        else break;
    }
    int r = 0;
    vector<string> m(4);
    m[0] = "one";
    m[1] = "ten";
    m[2] = "hundred";
    m[3] = "thousand";
    stack<string> s;
    for(int n = 1, i = 0; !d.empty(); n *= 10, ++i, d.pop()) {
        r += d.top() * n;
        s.push(m[i]);
    }
    cout << r << " is ";
    for(int i = 0; !q.empty(); ++i, q.pop(), s.pop()) {
        cout << q.front() << " " << s.top();
        if (1 < q.front()) cout << "s";
        if (1 < q.size()) cout << " and ";
    }
    cout << endl;
    return 0;
}
