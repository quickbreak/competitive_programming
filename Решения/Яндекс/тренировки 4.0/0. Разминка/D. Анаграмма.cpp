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


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("INPUT.TXT", "r", stdin);
    //freopen("OUTPUT.TXT", "w", stdout);

    str s1, s2;
    map<char,int>st1, st2;
    cin >> s1;
    int n = s1.size();
    fori(i, 0, n)
        st1[s1[i]]++;
    cin >> s2;
    n = s2.size();
    fori(i, 0, n)
        st2[s2[i]]++;
    if (st1.size() == st2.size())
    {
        fori(i, 0, n)
        {
            if (st1.find(s2[i]) == st1.end() || st1[s2[i]] != st2[s2[i]])
            {
                cout << "NO";
                return 0;
            }
        }
        cout << "YES";
    }
    else 
        cout << "NO";
}