#include "../std_lib_facilities.h"

int main() {
    vector<double> dists;
    double dist;
    while(cin >> dist) {
        dists.push_back(dist);
    }
    if (dists.size() == 0) return 0;

    double sum = 0;
    for (size_t i = 0; i < dists.size(); i ++) sum += dists[i];
    sort(dists.begin(), dists.end());
    cout << "Total distance: " << sum << endl;
    cout << "Min: " << dists[0] << ", MAX: " << dists[dists.size() - 1] << endl;
    cout << "Average distance: " << sum / dists.size() << endl;

    return 0;
}
