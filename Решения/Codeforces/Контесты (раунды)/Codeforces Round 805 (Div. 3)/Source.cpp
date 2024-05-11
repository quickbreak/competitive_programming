#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>
#include<vector>
#include<algorithm>
#include<stack>
#include<map>

#define fori(it,a,b) for(int it=a;it<b;it++)
#define all(x) (x).begin(),(x).end()
#define cn cout << '\n'

using namespace std;

using ll = long long;
using str = string;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t, n, b, m, k;
    str s;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int cnt = 0;
        int a = 3, b = 5, c = 7;
        int op = 1;
        while (cnt < n)
        {
            cout << a << ' ';
            cnt++;
            if (cnt == n)
                break;
            cout << b << ' ';
            cnt++;
            if (cnt == n)
                break;
            cout << c << ' ';
            cnt++;
            if (cnt == n)
                break;
            a+=c+3; b+=c+5; c+=c+7;
        }
        cn;
    }
}