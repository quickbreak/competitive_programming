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
vector<int>used(11);
vector<int>a(11);
int ans = 0;


void gen(int pos)
{
    if (pos == n)
    {
        fori(i, 1, n + 1)
        {
            fori(j, 1, n + 1)
            {
                if (i == j)
                    continue;
                if ((a[i] + i == a[j] + j) || (a[i] - i == a[j] - j)) //think bout indexes
                {
                    return;
                }
            }
        }
        ans++;
        return;
    }

    fori(x, 1, n + 1)
    {
        if (used[x] == 0)
        {
            a[pos + 1] = x;
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
    

    cin >> n;
    /*a[1] = 2;
    a[2] = 4;
    a[3] = 1;
    a[4] = 3;*/
    gen(0);
    cout << ans;
}

