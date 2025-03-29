#include <iostream>
#include <vector>

using namespace std;

const long long mod = (long long)1e9+7;

int main() {
    int n; cin >> n;
    vector<long long>a(n), prefsum(n+1), multip(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        prefsum[i+1] = prefsum[i] + a[i];
        // prefsum[i+1] %= mod;  // так разность неправильная получится
    }
    vector<long long>prefsum2(n+1);
    for(int i=0;i<n;++i) {
        multip[i] = a[i] * ((prefsum[n]-prefsum[i + 1])%mod);
        multip[i] %= mod;
        prefsum2[i+1] = prefsum2[i] + multip[i];
        // prefsum2[i+1] %= mod;  // так разность неправильная получится
    }
    long long ans = 0LL;
    for(int i=0;i<n;++i) {
        ans += a[i] * ((prefsum2[n] - prefsum2[i + 1])%mod);
        ans %= mod;
    }
    
    cout << ans;
}