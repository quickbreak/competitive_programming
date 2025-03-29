#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    vector<long long>a(n);
    long long cnt_all = 0LL;
    for (long long& x : a) {
        cin >> x;
        cnt_all += x;
    }
    long long ans = 1'000'000'000'000'000'003; // 1e18+3
    long long res = 0;
    long long cnt_left = 0LL, cnt_right = 0LL;
    for(int i = n - 1; i >= 0; --i) {
        res += cnt_right;
        cnt_right += a[i];
    }
    cnt_right -= a[0];
    ans = res;
    if (n == 1) {
        cout << ans;
        return 0;
    }
    cnt_left = a[0];
    // cnt_right -= a[1]; // n > 1?
    for (int i = 1; i < n; ++i) {
        res += cnt_left;
        res -= cnt_right;
        ans = min(ans, res);
        cnt_left += a[i];
        cnt_right -= a[i];
    }
    cout << ans;
}