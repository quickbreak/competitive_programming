#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int l, r;
    if (n % 2 == 1) {
        cout << a[n / 2] << ' ';
        r = n / 2 + 1;
    }
    else {
        r = n / 2;
    }
    l = n / 2 - 1;
    while (l >= 0 && r < n) {
        cout << a[l] << ' ' << a[r] << ' ';
        --l;
        ++r;
    }
    assert(l == -1 && r == n);
}