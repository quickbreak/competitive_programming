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


//str alf = "0([)]";
int n;
vector<char>p(17);
int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
stack<char>st;
str s;


void gen(int pos)
{
    if (pos == n)
    {
        s = "";
        fori(i, 1, n + 1)
        {
            s += p[i];
        }
        cout << s;
        cn;
        return;
    }
    fori(i, 1, 4 + 1)
    {
        if (i == 1)
        {
            if (c1 + c2 < n / 2)
            {
                st.push('(');
                c1++;
                p[pos + 1] = '(';
                gen(pos + 1);
                c1--;
                st.pop();
            }
        }
        else if (i == 2)
        {
            if (c1 + c2 < n / 2)
            {
                st.push('[');
                c2++;
                p[pos + 1] = '[';
                gen(pos + 1);
                c2--;
                st.pop();
            }
        }
        else if (i == 3)
        {
            if (p[pos] != '[' && c1 > c3)
            {
                if (st.size() > 0 && st.top() == '(')
                {
                    st.pop();
                    c3++;
                    p[pos + 1] = ')';
                    gen(pos + 1);
                    c3--;
                    st.push('(');
                }
            }
        }
        else if (i == 4)
        {
            if (p[pos] != '(' && c2 > c4)
            {
                if (st.size() > 0 && st.top() == '[')
                {
                    st.pop();
                    c4++;
                    p[pos + 1] = ']';
                    gen(pos + 1);
                    c4--;
                    st.push('[');
                }
            }
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
    if (n == 0 || n % 2 != 0)
        cn;
    else
        gen(0);
}
/*
6
...
7 -- ([())]  !
*/