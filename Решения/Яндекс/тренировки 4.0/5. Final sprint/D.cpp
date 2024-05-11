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


vi p(31);
ll sum = 0;
int n, m;
bool flag = 0;
vi w(16);
vi used(16);
vector<string>res;
vector<int>ans;


void gen(int pos)
{
    if (sum == n)
    {
        //cout << pos + 1; cn;
        ans.push_back(pos + 1);
        string k;
        fori(i, 0, pos + 1)
        {
            k += to_string(p[i]);
            k += " ";
        }
        res.push_back(k);
        return;
    }
    if (sum > n)
        return;

    //else:
    fori(i, 0, m)
    {
        if (used[i] < 2)
        {
            used[i]++;
            p[pos + 1] = w[i];
            sum += w[i];
            gen(pos + 1);
            sum -= w[i];
            p[pos + 1] = 0;
            used[i]--;
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("INPUT.TXT", "r", stdin);
    //freopen("OUTPUT.TXT", "w", stdout);


    cin >> n >> m;
    fori(i, 0, m)
    {
        cin >> w[i];
        sum += w[i];
    }
    if (2 * sum < n)
    {
        cout << -1;
        return 0;
    }
    sort(w.begin(), w.end(), greater<>());
    sum = 0;
    gen(-1);
    int minans = 1e9, uk = -1;
    fori(i, 0, ans.size())
    {
        if (ans[i] < minans)
        {
            minans = ans[i];
            uk = i;
        }
    }
    if (minans == 1e9)
        cout << 0;
    else {
        cout << minans; cn;
        cout << res[uk];

    }
}

