#include "../std_lib_facilities.h"
#include <map>

/*
 * チェスを発明したものに褒美を与えようと考えた皇帝が、
 * 望みは何かと尋ねたという昔話がある。
 * チェス盤の一つ目のマス目に１グレーンの米、
 * ２つ目のマス目に２グレーン、
 * ３爪のマス目に４グレーンといったように、
 * ６４のマス目ごとに２倍の量の米を所望した。
 * 謙虚な申し出のように思えたが、帝国にはそれだけの米がなかった。
 * 少なくとも1,000グレーン、少なくとも１００万グレーン、
 * そして少なくとも１０億グレーンの米を褒美として与えるのに必要な
 * マス目の数を計算するプログラムを作成せよ
 */

int main() {
    double sum = 0;
    bool a = true,
        b = true,
        c = true;
    for (int n = 1, i = 1; i <= 32; ++i, n*=2)
    {
        sum += n;
        if (a && 1000 <= sum) {
            a = false;
            cout << "1000 over: " << i << "masu(" << sum << " grane)" << endl;
        }
        if (b && 1000000 <= sum) {
            b = false;
            cout << "1000000 over: " << i << "masu(" << sum << " grane)" << endl;
        }
        if (c && 1000000000 <= sum) {
            c = false;
            cout << "1000000000 over: " << i << "masu(" << sum << " grane)" << endl;
        }
    }
    return 0;
}
