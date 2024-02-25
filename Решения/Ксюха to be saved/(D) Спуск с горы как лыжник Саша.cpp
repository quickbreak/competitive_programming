#include<iostream>
#include<vector>


using namespace std;


int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;
    vector<vector<long long>> a(n, vector<long long>(n + 1, -1e18));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (j <= i + 1)
                cin >> a[i][j];
        }
    }

    vector<vector<long long>> d(n, vector<long long>(n + 1, -1e18));
    d[0][1] = a[0][1];
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < i + 2; ++j)
        {
            d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + a[i][j];
        }
    }

    long long ans = -1e18;
    for (int j = 1; j <= n; ++j)
    {
        ans = max(ans, d[n - 1][j]);
    }
    cout << ans;
}
