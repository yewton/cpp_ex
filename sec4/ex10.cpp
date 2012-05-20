#include "../std_lib_facilities.h"

class XORShift {
    unsigned long x;
    unsigned long y;
    unsigned long z;
    unsigned long w;
public:
    XORShift() : x(123456789),
                 y(362436069),
                 z(521288629),
                 w(88675123) {}
    XORShift(unsigned long x,
             unsigned long y,
             unsigned long z,
             unsigned long w) : x(x), y(y), z(z), w(w) {}
    unsigned long get();
    unsigned long get(int min, int max);
};

unsigned long XORShift::get() {
    unsigned long t = (x^(x<<11));
    x = y; y = z; z = w;
    return w = (w^(w>>19))^(t^(t >> 8));
}

unsigned long XORShift::get(int min, int max) {
    return (get() % ((max + 1) - min)) + min;
}

class Janken {
private:
    enum Hand {GU = 0, CHOKI = 1, PA = 2};
public:
    Hand hand;
    Janken(Hand h = GU) : hand(h) {}
    Janken(int n) {
        switch(n % 3) {
        case 0: hand = GU; break;
        case 1: hand = CHOKI; break;
        default: hand = PA;
        }
    }
    bool operator==(const Janken &o) {
        return hand == o.hand;
    }
    bool operator<(const Janken &o) {
        switch(hand) {
        case GU: return (o.hand == PA);
        case CHOKI: return (o.hand == GU);
        case PA: return (o.hand == CHOKI);
        }
        return false;
    }
    friend ostream& operator<<(ostream& os, const Janken &j) {
        switch(j.hand) {
        case GU: os << "GU"; break;
        case CHOKI: os << "CHOKI"; break;
        case PA: os << "PA"; break;
        }
        return os;
    }
};

int main() {
    int seeds[4] = {0, 0, 0, 0};
    string s;

    cout << "Put random string and enter:" << endl;
    cin >> s;
    cout << endl;

    int n = 0;
    for(string::iterator i = s.begin(); i != s.end(); i++, n++) {
        seeds[n % 4] += *i;
    }
    XORShift xors(seeds[0], seeds[1], seeds[2], seeds[3]);

    int wn = 0;
    for(int i = 0; i < 10; i++) {
        int x;
        cout << "Put 0 for GU, 1 for CHOKI, 2 for PA: ";
        cin >> x;
        Janken my(xors.get(0, 2));
        Janken ur(x);
        cout << "Your hand: " << ur << endl;
        cout << "My hand: " << my << endl;
        if (my == ur) {
            cout << "Draw..." << endl;
        } else if (my < ur) {
            ++wn;
            cout << "You Win!" << endl;
        } else {
            cout << "You Lose..." << endl;
        }
        cout << "Score: (" << wn << "/" << (i + 1) << ")" << endl;
    }

    return 0;
}
