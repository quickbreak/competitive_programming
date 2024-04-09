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

    map<char, int> dict_s;
    map<char, int> dict_t;
    int k = 4;
    for (int i = 0; i < k; ++i)
        dict_t[int('a' + i)]++;
    string s = "abcdqwfenalenrinqwertyuioiasdfgjzvncb";
    for (int i = 0; i < s.size(); ++i) {
        if (dict_t.find(s[i]) != dict_t.end()) {
            dict_s[s[i]]++;
            if (i + 1 > k) {
                dict_s[s[i - k]]--;
            }

        }
        else cout << 1;
        
    }
}