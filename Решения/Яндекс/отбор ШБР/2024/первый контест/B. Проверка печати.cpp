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
	
	str Suneed, s = "";
	cin >> Suneed;
	str log; cin >> log;
	int i = -1, uk = 0; // uk - перед каким символом стоит курсор
	str command = "";
	str sleft = "", sright = "";
	while (++i < log.size()) {
		// если буква
		if (log[i] != '<') {
			// если её надо в конец добавить
			if (uk == s.size()) {
				s += log[i];
				++uk;
			}
			// иначе 
			else {
				sleft.clear();
				for (int j = 0; j < uk; ++j) {
					sleft += s[j];
				}
				sright.clear();
				for (int j = uk; j < s.size(); ++j) {
					sright += s[j];
				}
				
				// ПРОВЕРЬ, КАК СКЛАДЫВАЕТ ЛОГ[И] !!!!!!!!!!!!!!!!
				// вывод:
				// s = "misha" + 'i' не работает
				// но s = sleft + log[i] работает
				// надёжнее:
				// s = left;
				// s += log[i];

				s = sleft + log[i] + sright;
				++uk;
			}
		}
		// если команда
		else {
			command.clear();
			while (log[++i] != '>') {
				command += log[i];
			}
			// ++i;

			if (command == "left") {
				if (uk != 0)
					--uk;
			}
			else if (command == "right") {
				if (uk != s.size())
					++uk;
			}
			else if (command == "bspace"){
				// если сзади нечего удалять
				if (uk == 0)
					continue;

				sleft.clear();
				for (int j = 0; j < uk - 1; ++j) {
					sleft += s[j];
				}
				sright.clear();
				for (int j = uk; j < s.size(); ++j) {
					sright += s[j];
				}

				// ПРОВЕРЬ, КАК СКЛАДЫВАЕТ ЛОГ[И] !!!!!!!!!!!!!!!!
				s = sleft + sright;
				--uk;
			}
			else if (command == "delete") {
				// если спереди нечего удалять
				if (uk == s.size())
					continue;

				sleft.clear();
				for (int j = 0; j < uk; ++j) {
					sleft += s[j];
				}
				sright.clear();
				for (int j = uk + 1; j < s.size(); ++j) {
					sright += s[j];
				}

				// ПРОВЕРЬ, КАК СКЛАДЫВАЕТ ЛОГ[И] !!!!!!!!!!!!!!!!
				s = sleft + sright;
				// ++uk;
			}
				
		}

	}

	cout << ((s == Suneed) ? "Yes" : "No");
}

/*
Misha
mI<bspace><bspace>Miha<left><right><left><left>s
output:
Yes

Misha
mI<bspace><bspace>Miha<left><right><left><left><delete><delete>sha
output:
Yes

WRONG ONES:
fgr
<bspace>fgr
No
--bspace не работал, когда указатель перед началом
та же ошибка с left и right
*/
