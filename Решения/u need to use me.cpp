#include<algorithm>
#include<any>
#include<cassert>
#include<cmath>
#include<cstdio>
#include<deque>
#include<functional>
#include<iostream>
#include<map>
#include<queue>
#include<random>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<vector>

#define fori(it, a, b) for(int it = a; it < b; ++it)
#define all(x) (x).begin(),(x).end()
#define cn cout << '\n'
#define minel(v) *min_element(v.begin(), v.end());
#define maxel(v) *max_element(v.begin(), v.end());
#define sortv(v) sort(v.begin(), v.end());
#define forl(a, k, b) for(long long a = k; a < b; ++a)
#define useless ios_base::sync_with_stdio(false); cin.tie(NULL);
//define int long long;

using namespace std;

using ll = long long;
using str = string;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;

const ll mod = ll(1e9+7);

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


int32_t main()
{
	useless;
	cout << 5;
	// freopen("input.in", "rt", stdin);
	// freopen("output.out", "wt", stdout);

	// int n = 2;
	// vi a;
	// vi b(n);
	// cout << a.size() << b.size();
	// cout<<precision<<fixed;

	// str s = "asvkdxbjc";
	// vi a(10);
	// a[0] = -2; a[9] = -3;
	// for (char ch : s)
	// 	cout << ch;
	// cout << endl;
	// for (int x : a)
	// 	cout << x;
	// cout << '\n';

	// int p = (5 > 2 ? 1 : 0);
	// cout << p << '\n';


	// double y = -52.67675;
	// cout.precision(3);
	// cout << y << '\n';

	// // sort(all(powers));
	// // powers.erase(unique(all(powers)), powers.end());


	// // ll res = upper_bound(all(powers), R) - powers.begin();
	// // 	res += (ll)sqrtl(R);

	// // ll c =	(ll)sqrtl(R);

	// // freopen("input.txt", "rt", stdin);
	// // freopen("output.txt", "wt", stdout);
	
	// any x = 15;
	// int n = any_cast<int>(x);
	// cout << n; cn;
	
	// cout << binpow(2, 1000000000000000000); //2^18 без проблем

	/*
	function<void(int)>dfs = [&](int(u)) {
		used[u] = 1;
		for (int v : adj[u])
		{
			if (!used[v])
				dfs(v);
		}
		timeout[u] = { ++ttime, u };
		};
	*/
	
}