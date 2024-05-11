#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	int n; cin >> n;
	char ch;
	vector a(n, vector(n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> ch;
			a[i][j] = (ch == '1');
		}
	}
	vector<int>opponents;
	int x;
	for (int i = 0; i < 5; ++i) {
		cin >> x;
		opponents.push_back(--x);
	}
	vector<int>candidates;
	bool weak = false;
	// наберём кандидатов в нашу команду
	for (int i = 0; i < n; ++i) {
		weak = false;
		// кандидата не должен контрить ни один из соперников
		for (int opponent : opponents) {
			if (i == opponent || a[opponent][i] == 1)
				weak = true;
		}
		if (weak)
			continue;
		// кандидат должен контрить хоть кого-то из соперников
		for (int opponent : opponents) {
			if (a[i][opponent] == 1) {
				candidates.push_back(i);
				break;
			}
		}
	}
	set<int>team;
	int freecnt = 5; // сколько не законтрено?
	// теперь попробуем набрать команду
	for (int candidate : candidates) {
		if (freecnt == 0) {
			if (team.size() == 5)
				break;
			team.insert(candidate);
			continue;
		}
		for (int& opponent : opponents) {
			// если этот оппонент его не законтрен
			if (opponent != -1) {
				// и я могу его законтрить
				if (a[candidate][opponent] == 1) {
					// то гг вп ему
					team.insert(candidate);
					opponent = -1;
					--freecnt;
				}
			}
		}
	}
	if (team.size() == 5) {
		cout << "YES\n";
		for (int member : team)
			cout << member + 1 << ' ';
	}
	else cout << "NO\n";
}