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

#define fori(it, a, b) for(int it = a; it < b; ++it)
#define all(x) (x).begin(),(x).end()
#define cn cout << '\n'
#define minel(v) *min_element(v.begin(), v.end());
#define maxel(v) *max_element(v.begin(), v.end());
#define sortv(v) sort(v.begin(), v.end());
#define forl(a, k, b) for(long long a = k; a < b; ++a)
#define useless ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

using ll = long long;
using str = string;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;

const ll mod = ll(1e9 + 7);

//base ^ p
ll binpow(ll base, ll p)
{
	if (p == 0)
		return 1;
	if (p == 1)
		return base;
	if (p % 2 == 0)
	{
		ll polovina = binpow(base, p / 2);
		return polovina * polovina % mod;
	}
	else
	{
		ll pminus = binpow(base, (p - 1) / 2);
		ll res = pminus * pminus % mod;
		return res * base % mod;
	}
}


const int NMAX = 1e7 + 100;
int firstDiv[NMAX], powerA[NMAX], powerB[NMAX];
const int MAX = 1e7;
void precalc() {
    for (int i = 2; i * i < NMAX; i++)
        if (firstDiv[i] == 0)
            for (int j = i * i; j < NMAX; j += i)
                if (!firstDiv[j])
                    firstDiv[j] = i;
    for (int i = 1; i < NMAX; i++)
        if (firstDiv[i] == 0)
            firstDiv[i] = i;
}
void factor(int x, const auto& f) {
    while (x > 1) {
        int p = firstDiv[x];
        f(p);
        x /= p;
    }
}

int main()
{
	useless;

	//freopen("input.in", "rt", stdin);
	//freopen("output.out", "wt", stdout);

    

	int t; cin >> t;
	int a, b;
    precalc();
    /*int n, m; cin >> n >> m;
    vi a, b;
    while (n-- > 0) {
        int x; cin >> x;
        a.push_back(x);
        factor(x, [&](int p) {powerA[p]++; });
    }
    while (m-- > 0) {
        int x; cin >> x;
        b.push_back(x);
        factor(x, [&](int p) {powerB[p]++; });
    }*/
    
	while (t--) {
        fori(i, 0, NMAX)
        {
            powerA[i] = 0;
            powerB[i] = 0;
        }
		cin >> a >> b;
        factor(a, [&](int p) {powerA[p]++; });
        factor(b, [&](int p) {powerB[p]++; });
        for (int x = 1; x < NMAX; x++) {
            powerA[x] = max(powerA[x], powerB[x]);
            //powerB[x] = min(powerA[x], powerB[x]);
        }
        int uk = 1;
        ll p = 1;
        fori(i, 2, NMAX) {
            if (uk == 1)
                if (powerA[i] > 0)
                    uk = i;
            if (powerA[i] > 0)
            {
                p *= binpow(i, powerA[i]);
            }
        }
        if (p == b)
            p *= uk;
        cout << p; cn;
	}

}