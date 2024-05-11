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


int32_t main()
{
	useless;

	int t, n; cin >> t;
	while (--t >= 0) {
		int m;
		cin >> n;
		vector<int>a(n);
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		sort(all(a));
		a.erase(unique(all(a)), a.end());
		n = a.size();
		string answer;
		// если a[0] != 1 {
		// и это единственная куча, Алиса возьмёт её всю и победит
		// иначе Алиса сразу возьмём a[0] - 1, и Бобу придётся взять один,
		// и Алиса будет повторять такие издёвки, пока не останется 1 куча, 
		// которую она возьмёт всю и победит }
		if (a[0] != 1) { 
			answer = "Alice\n";
		}
		else {
			int eventy = 1; // сколько стопок идут по порядку (1, 2, 3, 4,..)
			int i = 0;
			while (i < n - 1) {
				++i;
				if (a[i] == a[i - 1] + 1)
					eventy++;
				else break;
			}
			if (i == n - 1) { // если остановились/прервались на последней
				if (eventy == n) { // если все идут по порядку
					if (eventy % 2 == 0) // то, кто взял последнюю, тот и победил
						answer = "Bob\n";
					else
						answer = "Alice\n";
				}
				else { // если последняя не по порядку (в ней больше, чем в предыдущей, хотя бы на 2)
					if (eventy % 2 == 1) // то победит тот, кто окажется у этой последней стопки
						answer = "Bob\n";
					else
						answer = "Alice\n";
				}
			}
			else { // Если последовательные закончились на Алисе, Боб может сыграть с ней в издёвки и победить
				if (eventy % 2 == 1)
					answer = "Bob\n";
				else
					answer = "Alice\n";
			}
		}
		cout << answer;

	}
}

/*
7
1 3 9 7 4 2 100
--Alice

Алиса и Боб играют в игру с n кучками из камней. 
На каждом ходу игрок выбирает положительное целое число k, 
которое не превышает размера самой маленькой непустой кучки, 
и удаляет k камней из каждой непустой кучки одновременно. 
Первый игрок, который не может сделать ход (потому что все кучки пусты), проигрывает.

Учитывая, что Алиса ходит первой, кто выиграет игру, если оба игрока играют оптимально?
*/