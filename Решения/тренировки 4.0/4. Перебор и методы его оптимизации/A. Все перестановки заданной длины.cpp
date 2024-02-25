#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<any>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<cassert>

#define fori(it, a, b) for(int it = a; it < b; it++)
#define all(x) (x).begin(),(x).end()
#define cn cout << '\n'
#define minel(v) *min_element(v.begin(), v.end());
#define maxel(v) *max_element(v.begin(), v.end());
#define sortv(v) sort(v.begin(), v.end());
#define forl(a, k, b) for(long long a = k; a < b; a++)
#define useless ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

using ll = long long;
using str = string;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;


int n;
vector<int>used(10);
vector<char>a(10);
str s;


void gen(int pos)
{
    if (pos == n)
    {
        s = "";
        fori(i, 1, n + 1)
        {
            s += a[i];
        }
        cout << s;
        cn;
        return;
    }

    fori(x, 1, n + 1)
    {
        if (used[x] == 0)
        {
            a[pos + 1] = char(x + 48);
            used[x] = 1;
            gen(pos + 1);
            used[x] = 0;

        }
    }
}
    

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("INPUT.TXT", "r", stdin);
    //freopen("OUTPUT.TXT", "w", stdout);

    //cout << char(1 + 48);
    cin >> n;
    gen(0);
}

