#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<stack>

using namespace std;


int n;


void solve(vector<long long>b)
{
    n = b.size() - 1;
    int q;
    cin >> q;
    int l, r;
    while (q--)
    {
        cin >> l >> r;
        cout << b[r] - b[l-1] << '\n';
    }
}


int main()
{
    cin >> n;
    int x;
    vector<long long>b(n + 1);
    b[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        b[i + 1] = b[i] + x;
    }
    solve(b);
}