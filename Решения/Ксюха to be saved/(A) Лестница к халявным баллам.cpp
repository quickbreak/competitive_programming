#include<iostream>
#include<vector>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<int> d(n);
    d[0] = a[0];
    d[1] = max(d[0], 0) + a[1];
    for (int i = 2; i < n; ++i) {
        d[i] = max(d[i - 1], d[i - 2]) + a[i];

    }
    cout << d[n - 1];

}
