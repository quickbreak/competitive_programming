#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<ctime>
#include<algorithm>
#include<string>
#include<random>


using namespace std;


string f(const vector<long long>a, int n, int k) {
    /*int n, k;
    cin >> n >> k;*/


    //vector<int> a(n);
    /*for (int i = 0; i < n; i++) {
        cin >> a[i];
    }*/
	string s1;
    int best_sum = -1e9;
    int left = -1, right = -1;

    for (int i = 0; i < n; i++) {
        //vector<int> cur;
        int cur_sum = 0;

        set<int> cur_distinct;

        for (int j = i; j < n; j++) {
            //cur.push_back(a[j]);
            cur_sum += a[j];
            cur_distinct.insert(a[j]);

            if (cur_distinct.size() >= k &&
                (cur_sum >= best_sum)) {
                best_sum = cur_sum;
                left = i;
                right = j;
            }
        }
    }
    if (left == -1) {
        s1 =  "IMPOSSIBLE";
        return s1;
    }
	s1 = to_string(best_sum);
	return s1;
}


int main() {
	//freopen("in.txt", "rt", stdin);
	//freopen("out.txt", "wt", stdout);

	for (int t = 0; t < 1000; ++t) {
		srand(time(0));
		//cout << t;
		int n, k;
		//n = rand() % (100 - 1 + 1) + 1;
		//k = rand() % (n - 1 + 1) + 1;
		random_device rd;   // non-deterministic generator
		mt19937 gen(rd());  // to seed mersenne twister.
		uniform_int_distribution<> distn(1, 10); // distribute results between 1 and 6 inclusive.
		n = distn(gen);
		uniform_int_distribution<> distk(1, n);
		k = distk(gen);
		uniform_int_distribution<> distai(-10, 10);
		vector<long long>a(n);
		for (int i = 0; i < n; ++i) {
			//a[i] = rand() % (5 - (-5) + 1) - 5;
			a[i] = distai(gen);

		}
		//int n, k; cin >> n >> k;
		//vector<int>a(n);
		vector<long long>prefs(n + 1); // prefs[i] == сумма первых i элементов
		prefs[0] = 0;
		vector<pair<int, int>>cnt(n); // cnt[i] == количество вхождений a[i] элемента в текущий подотрезок
		vector<long long>min_prefs(n + 1); // минимальная сумма подотрезка 0..uk из подотрезков отрезка 0..i
		min_prefs[0] = 0;
		int uk;
		for (int i = 0; i < n; ++i) {
			//cin >> a[i];
			prefs[i + 1] = (prefs[i] + a[i]);
			cnt[i] = { a[i], 0 };
			/*if (i == 0)
			{
				min_prefs[i + 1] = a[0];
				continue;
			}*/
			min_prefs[i + 1] = min(min_prefs[i], prefs[i + 1]);

		}
		sort(cnt.begin(), cnt.end());
		for (int i = 1; i < n; ++i) {
			if (cnt[i].first == cnt[i - 1].first)
				cnt[i].second = (int)1e9;
		}
		long long ans_sum = -1e18, curr_sum = 0;
		int l = 0, r = 0, ans_l = -1, ans_r = -1, curr_k = 0;
		while (r < n && curr_k < k) {
			uk = lower_bound(cnt.begin(), cnt.end(), pair(a[r], 0)) - cnt.begin();
			//assert(uk > -1 && uk < n);
			++cnt[uk].second;

			if (cnt[uk].second == 1)
				++curr_k;
			++r;
		}
		string s2;
		if (curr_k < k) {
			s2 = "IMPOSSIBLE";
			//cout << "IMPOSSIBLE";
			//return 0;
		}
		else {
			--r;
			curr_sum = prefs[r + 1];
			if (curr_sum > ans_sum) {
				ans_sum = curr_sum;
				ans_r = r - 1;
				// ans_l тут не узнаешь, потом за O(n) найдешь проходом по min_prefs
			}
			while (curr_k >= k) {
				++l; // когда это плохо? upd: вроде, никогда
				uk = lower_bound(cnt.begin(), cnt.end(), make_pair(a[l - 1], 0)) - cnt.begin();
				--cnt[uk].second;
				if (cnt[uk].second == 0)
					--curr_k;
				if (curr_k < k) {
					--l;
					++cnt[uk].second;
					++curr_k;
					break;
				}
				curr_sum = prefs[r + 1] - min(min_prefs[l + 1 - 1], 0LL);
				if (curr_sum > ans_sum) {
					ans_sum = curr_sum;
					ans_r = r;
					// ans_l тут не узнаешь, потом за O(n) найдешь проходом по min_prefs
				}
			}
			for (r = r + 1; r < n; ++r) {
				uk = lower_bound(cnt.begin(), cnt.end(), pair(a[r], 0)) - cnt.begin();
				//assert(uk > -1 && uk < n);
				++cnt[uk].second;
				curr_sum = prefs[r + 1] - min(min_prefs[l], 0LL);
				if (curr_sum > ans_sum) {
					ans_sum = curr_sum;
					ans_r = r;
					// ans_l тут не узнаешь, потом за O(n) найдешь проходом по min_prefs
				}
				if (cnt[uk].second == 1)
					++curr_k;
				while (curr_k >= k) {
					++l; // когда это плохо? upd: вроде, никогда
					uk = lower_bound(cnt.begin(), cnt.end(), make_pair(a[l - 1], 0)) - cnt.begin();
					--cnt[uk].second;
					if (cnt[uk].second == 0)
						--curr_k;
					if (curr_k < k) {
						--l;
						++cnt[uk].second;
						++curr_k;
						break;
					}
					curr_sum = prefs[r + 1] - min(min_prefs[l + 1 - 1], 0LL);
					if (curr_sum > ans_sum) {
						ans_sum = curr_sum;
						ans_r = r;
						// ans_l тут не узнаешь, потом за O(n) найдешь проходом по min_prefs
					}
				}

			}
			s2 = to_string(ans_sum);
		}

		
		

		string s1 = f(a, n, k);
		if (s1 != s2) {
			cout << n << ' ' << k << '\n';
			for (int i = 0; i < n; ++i)
				cout << a[i] << ' ';
			cout << '\n' << s1 << '\n' << s2;
			break;
		}
	}
	

}
