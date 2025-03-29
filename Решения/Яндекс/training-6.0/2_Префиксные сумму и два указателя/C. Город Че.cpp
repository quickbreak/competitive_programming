#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int>a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long ans = 0;
    for (int l = 0, r = 1; l < n; ++l) {
        while(r < n && (a[r] - a[l] <= k)) {
            ++r;
        }
        if (r == n)
            break;
        
        ans +=  n - r;
    }
    cout << ans;
}