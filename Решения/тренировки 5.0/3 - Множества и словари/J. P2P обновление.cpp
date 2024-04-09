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
//#define int long long;

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

	int n, k; cin >> n >> k;

	vector<vector<long long>>cost(n + 1, vector<long long>(n + 1)); // cost[i][j] == ценность устройства j для устройства i

	vector<set<long long>>qin(n + 1); // qin[i] == список устройств, которые запрашивают часть у i-того устройства

	vector<set<long long>>parts(n + 1); // каких частей нет на устройстве i
	fori(i, 2, n + 1)
	{
		fori(j, 1, k + 1)
		{
			parts[i].insert(j);
		}
	}


	vl number(n + 1); // какому устройству я отправлю запрос
	vl cnt(k + 1, 1); // cnt[i] == сколько i-частей скачано на все устройства суммарно
	vl which(n + 1); // какую деталь я буду просить

	long long min_cnt = n + 2;
	long long max_cnt = -1;
	vl ans(n + 1); // сколько тайм-слотов потребовалось, чтобы меня заполнить
	long long slots = 0; // какой сейчас тайм-слот по счёту
	long long max_cost = -1; // максимальная ценность среди отправивших мне
	vi who(n + 1, 0); // кому я отправлю часть
	long long parts_cnt = k + 1;


	long long full_cnt = 1;
	long long to = -1;
	while (full_cnt < n) {
		++slots;

		fori(i, 2, n + 1) { // устройство, отправляющее запрос

			if (int(parts[i].size()) > 0) { // мне чего-то не хватает
				// просим редчайшую меньшую часть, которой у нас нет
				min_cnt = n + 2;
				for (int part : parts[i])
				{
					if (cnt[part] < min_cnt) { // ищем редчайшую
						min_cnt = cnt[part];
						which[i] = part;
					}
				}
				max_cnt = -1;
				fori(j, 1, n + 1) { // устройство, которому я мог отправить запрос
					if (parts[j].find(which[i]) == parts[j].end()) { // у j-устройства есть часть, которая мне нужна
						//long long y = parts[j].size();
						if (int(parts[j].size()) > max_cnt) { // у этого устройства меньше деталей, чем у остальных способных передать мне (ему недостаёт больше)
							max_cnt = int(parts[j].size());
							if (number[i] > 0 && number[i] <= n)
							{
								//cout << number[i];
								qin[number[i]].erase(i);
							}
							number[i] = j; // отправляю запрос этому устройству
							qin[j].insert(i);
						}
					}
				}

			}

		}

		//max_cost = -1;
		//parts_cnt = -1;
		fori(i, 1, n + 1) { // устройство, удовлетворяющее запрос
			who[i] = n + 2;
			max_cost = -1;
			parts_cnt = -1;

			for (int x : qin[i]) // среди тех, кто отправил мне запрос
			{
				if (cost[i][x] > max_cost)
				{
					max_cost = cost[i][x];
					who[i] = x;
					parts_cnt = int(parts[x].size());
				}
				else if (cost[i][x] == max_cost) // этого я ценю столько же
				{
					if (int(parts[x].size()) > parts_cnt) // но он беднее
					{
						who[i] = x;
						parts_cnt = int(parts[x].size());
					}
					else if (int(parts[x].size()) == parts_cnt) // или он столько же бедный
					{
						who[i] = min(who[i], x); // то поделюсь с тем, у кого меньший номер

						parts_cnt = int(parts[who[i]].size());

					}
				}
			}
			qin[i].clear(); // пока меня больше не просят

		}

		fori(i, 1, n + 1) // делящееся устройство
		{
			if (who[i] < 1 || who[i] > n) {
				continue;
			}
			to = who[i]; // с кем делюсь
			parts[to].erase(which[to]); // он больше не нуждается в этой детали
			++cnt[which[to]];
			if (int(parts[to].size()) == 0) { // если он полный
				ans[to] = slots; // запомним его время для ответа
				++full_cnt;
			}
			++cost[to][i];
			number[to] = -1;
			which[to] = -1;
			who[i] = -1;

		}

	}
	fori(i, 2, n + 1)
		cout << ans[i] << ' ';
}