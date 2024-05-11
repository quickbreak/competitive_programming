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
#include<bitset>

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

    int t, n, m; cin >> t;
    while (--t >= 0) {
        str s; cin >> s;
        n = s.size();
        /*
        1
        abfefgba
        */
        // abfefgba
        // 01234567
        // abfefba
        // суффикс с позиции j, который совпадает с префиксом, но не с 0, а с n-j позиции
        // типа для 5: fe

        int count = 0;
        while (count < n - count - 1) {
            if (s[count] == s[n - count - 1])
                ++count;
            else
                break;
        }
        vector<int>part(n);
        for (int i = n - 1 - count; i >= count; --i) { // start
            for (int j = count; j <= i - (j - count); ++j) {
                if (s[j] == s[i - j + count])
                    ++part[i];
                else 
                    break;
            }
        }

        str res1;
        int i = 0;
        while (i < count)
            res1 += s[i], ++i;
        auto len = max_element(all(part));
        while (i <= len - part.begin()) {
            res1 += s[i++];
        }
        for (int i = count - 1; i >= 0; --i)
            res1 += s[i];
        // cout << res1 << '\n';

        // ещё вариант с другой стороны

        part.assign(n, 0);
        for (int i = count; i <= n - 1 - count; ++i) { // start
            for (int j = i; j <= n - 1 - count - j + i; ++j) {
                if (s[j] == s[n - 1 - count - j + i])
                    ++part[i];
                else
                    break;
            }
        }

        str res2;
        i = n - 1;
        while (i > n - 1 - count)
            res2 += s[i], --i;
        len = max_element(all(part));
        while (i >= (len - part.begin())) {
            res2 += s[i--];
        }
        for (int i = count - 1; i >= 0; --i)
            res2 += s[i];
        cout << (res1.size() > res2.size() ? res1 : res2) << '\n';
    }

}