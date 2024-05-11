#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

int gethighestbit(int tennumber) {
	int highestbit = 0; // a[i] >= 1
	int bitnumber = 0;
	while (tennumber > 0) {
		if (tennumber % 2) // == 1
			highestbit = bitnumber;
		tennumber /= 2;
		++bitnumber;
	}
	return highestbit;
}

int getbit(int tennumber, int number) {
	int bitnumber = 0;
	while (tennumber > 0) {
		if (bitnumber == number)
		{
			return tennumber % 2;
		}
		tennumber /= 2;
		++bitnumber;
	}
	return 0;
}

void clearvvl(vector<vector<long long>>& a) {
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < a[i].size(); ++j)
			a[i][j] = 0;
	}
}

string ten_to_bin(int tennumber) {
	string res = "";
	int bitnumber = 0;
	while (tennumber > 0) {
		res = to_string(tennumber % 2) + res;
		tennumber /= 2;
		++bitnumber;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n; cin >> t;
	while (--t >= 0) {
		cin >> n;
		vector<int>a(n);
		for (int& x : a) {
			cin >> x;
			// cout << bitset<3>(x) << '\n';
		}
		if (n == 1)
		{
			cout << 0 << '\n';
			continue;
		}

		vector<int>highestbit(n);
		for (int i = 0; i < n; ++i) {
			highestbit[i] = gethighestbit(a[i]);
		}

		// найти количество троек x, y, z, таких что
		// f(x,y) ^ f(y,z) > f(x,z), f(l,r) = a[l] ^  a[l+1] ^ ... ^ a[r]
		// ЗАМЕТИМ: это то же самое, что f(x, z) ^ a[y] (на примерах наглядно видно)
		// ксор с a[y] может увеличить ксор, если в той позиции, где старший единичный бит a[y],
		// у ксора x..z стоит 0 (опять же, достаточно рассмотреть примеры)
		// . . .
		// хочу знать, сколько подотрезков a: xor подотрезка имеет бит 0 на позиции bitnumber
		// для этого понадобится
		// cnt[bitnumber][0/1] - сколько ВСЕГО подотрезков a: xor подотрезка имеет бит 0/1 на позиции bitnumber
		// xor a[l..r] = xor a[0..r] ^ xor a[0..l - 1] <=> prefxor[r] ^ prefxor[l-1] (+-1)
		// xor a[l..r] == 0: xor a[0..r] == xor a[0..l-1]
		// xor a[l..r] == 1: xor a[0..r] != xor a[0..l-1]
		// получится, что на очередной итерации мы прибавляем к ОБЩЕМУ количеству 
		// количество подотрезков, оканчивающихся элементом a[r] и имеющих 0 на bitnumber.
		// чтобы сказать, сколько подотрезков, оканчивающихся элементом a[r], имеют 0 на bitnumber,
		// мне надо знать, сколько префксоров, заканчивающихся раньше (элементом a[j]: j < r) 
		// имеют на bitnumber такой же бит, как prefxor[r].
		// соответственно, чтобы сказать, сколько подотрезков, оканчивающихся элементом a[r], имеют 1 на bitnumber,
		// мне надо знать, сколько префксоров, заканчивающихся раньше (элементом a[j]: j < r) 
		// имеют на bitnumber бит, противоположный prefxor[r]

		// так я узнаю, сколько ВСЕГО подотрезков имеют бит 0 на bitnumber
		// среди тех, у кого 0 на highestbit[i] мне надо выбрать те, которым принадлежит элемент a[i] 
		// чтобы для каждого элемента a[i] ответить, сколько подотрезков он увеличивает ксором с ними
		// сумма таких количеств и будет ответом

		// как узнать, сколько подотрезков, содержащих a[i], имеют бит 0 в своём ксоре?
		// cntEnding[i][bitnumber] - сколько подотрезков, оканчивающихся раньше элемента a[i], имеют 0 на bitnumber
		// этот массив мы при заполнении prefxor заполним
		// cntStarting[i][bitnumber] - сколько подотрезков, начинающихся позже элемента a[i], имеют 0 на bitnumber
		// Как собрать ответ:
		// (сколько всего подотрезков имеют бит 0 на highestbit[i]) - (сколько тех, которые кончаются раньше) - 
		// - (сколько тех, которые начинаются позже) !!!


		// префикс-ксор до i элемента - prefxor[i]
		vector<long long>prefxor(n + 1);
		// суффикс-ксор от i элемента - suffxor[i]
		vector<long long>suffxor(n + 1);

		// cnt[bitnumber][0/1] - сколько ВСЕГО подотрезков в бите bitnumber имеют 0/1
		vector<vector<long long>>cnt(32, vector<long long>(2));
		// сколько префиксов имеют 0/1 на bitnumber?
		vector<vector<long long>>prefcnt(32, vector<long long>(2));


		// сколько подотрезков, оканчивающихся ДО i (EXCLUDING), имеют в бите bitnumber 0
		vector<vector<long long>>cntEnding(n, vector<long long>(32));
		// сколько подотрезков, начинающихся ПОСЛЕ i (EXCLUDING), имеют в бите bitnumber 0
		vector<vector<long long>>cntStarting(n, vector<long long>(32));

		int mybit;

		for (int r = 0; r < n; ++r) {
			prefxor[r + 1] = prefxor[r] ^ a[r]; // считаем префикс-ксор от начала до r
			for (int bitnumber = 0; bitnumber <= 31; ++bitnumber) { // пройдём по битам
				// mybit = getbit(prefxor[r + 1], bitnumber);
				mybit = int((prefxor[r + 1] & (1LL << bitnumber)) != 0LL);


				// сколько подотрезков с 0 на bitnumber, оканчивающихся до r?
				cntEnding[r][bitnumber] = cnt[bitnumber][0];

				// прибавляем то, сколько можно образовать нулевых (имеющих 0 на bitnumber) 
				// подотрезков, оканчивающихся в a[r]
				cnt[bitnumber][0] += prefcnt[bitnumber][mybit];

				// прибавляем то, сколько можно образовать единичных (имеющих 1 на bitnumber) 
				// подотрезков, оканчивающихся в a[r]
				cnt[bitnumber][1] += prefcnt[bitnumber][(1 + mybit) % 2];

				// у ещё одного префикса в бите bitnumber стоит mybit
				++prefcnt[bitnumber][mybit];

				// не забываем учесть подотрезок-суффикс
				// как бы xor с пустым множеством до массива
				if (mybit == 0)
					++cnt[bitnumber][0];
			}
		}


		// сколько суффиксов имеют 0/1 на bitnumber?
		vector<vector<long long>>suffcnt(32, vector<long long>(2));
		clearvvl(cnt);
		for (int r = n - 1; r >= 0; --r) {
			suffxor[r] = suffxor[r + 1] ^ a[r]; // считаем суффикс-ксор от r до конца
			for (int bitnumber = 0; bitnumber <= 31; ++bitnumber) { // пройдём по битам
				// mybit = getbit(suffxor[r], bitnumber);
				mybit = int((suffxor[r] & (1LL << bitnumber)) != 0LL);


				// сколько подотрезков с 0 на bitnumber, начинающихся после r?
				cntStarting[r][bitnumber] = cnt[bitnumber][0];

				// прибавляем то, сколько можно образовать нулевых (имеющих 0 на bitnumber) 
				// подотрезков, начинающихся в a[r]
				cnt[bitnumber][0] += suffcnt[bitnumber][mybit];

				// прибавляем то, сколько можно образовать единичных (имеющих 1 на bitnumber) 
				// подотрезков, начинающихся в a[r]
				cnt[bitnumber][1] += suffcnt[bitnumber][(1 + mybit) % 2];

				// у ещё одного префикса в бите bitnumber стоит mybit
				++suffcnt[bitnumber][mybit];

				// не забываем учесть подотрезок-суффикс
				// как бы xor с пустым множеством после массива
				if (mybit == 0)
					++cnt[bitnumber][0];

			}
		}

		long long answer = 0;
		for (int i = 0; i < n; ++i) {
			// cout << a[i] << ": " << highestbit[i] << ' ' << cnt[highestbit[i]][0] << ' ' << cntEnding[i][highestbit[i]] << ' ' << cntStarting[i][highestbit[i]] << '\n';
			answer += cnt[highestbit[i]][0] - cntEnding[i][highestbit[i]] - cntStarting[i][highestbit[i]];
		}
		cout << answer << '\n';

	}
}

/*
3
3
6 2 4
1
3
5
7 3 7 2 1

*/