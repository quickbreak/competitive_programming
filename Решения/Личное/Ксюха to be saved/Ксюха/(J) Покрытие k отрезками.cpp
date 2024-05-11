#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


int check(const vector<long long>& a, long long m) {
    int n = a.size();
    int ukl = 0, ukr = 0;
    int res = 0;
    while (ukr < n) {
        while (ukr < n && a[ukr] - a[ukl] <= m) {
            ukr++;

        }
        ukl = ukr;
        res++;

    }
    return res;

}


int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, k; cin >> n >> k;
    vector<long long>a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    long long l = -1, r = 2e9 + 1, m;
    while (r - l > 1) {
        m = (r + l) / 2;
        if (check(a, m) <= k) {
            r = m;

        }
        else
            l = m;

    }
    cout << r;
    
}
//1000000000
