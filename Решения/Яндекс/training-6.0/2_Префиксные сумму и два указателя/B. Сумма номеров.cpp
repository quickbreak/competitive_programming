#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int>a(n), prefsum(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        prefsum[i + 1] = prefsum[i] + a[i];
    }
    long long ans = 0;
    for (int l = 0, r = 0; l < n; ++l) {
        while(r < n && (prefsum[r + 1] - prefsum[l] < k)) {
            ++r;
        }
        if (r == n)
            break;
        // prefsum[r + 1] - prefsum[l] >= k
        if (prefsum[r + 1] - prefsum[l] == k) {
            ++ans;
        }
    }
    cout << ans;
}