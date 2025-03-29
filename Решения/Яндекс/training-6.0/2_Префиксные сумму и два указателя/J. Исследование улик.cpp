#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define isz(x) (int)x.size()

int main() {
    int n; cin >> n;
    vector<int>a(n);
    for (int& x: a)
        cin >> x;
    vector<int>res(n + 1);
    int m, k; cin >> m >> k;
    int pos = 1;
    res[1] = pos;
    set<int>indexes;
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i-1]) {
            indexes.insert(i - 1 + 1);
            if (isz(indexes) > k) {
                pos = *indexes.begin() + 1;
                indexes.erase(indexes.begin());
            }
        }
        else if (a[i] < a[i - 1]) {
            pos = i + 1;
            indexes.clear();
        }
        else {
            // a[i] > a[i-1], ok
        }
        res[i + 1] = pos;
    }
    int ind;
    for (int i = 0; i < m; ++i) {
        cin >> ind;
        cout << res[ind] << ' ';
    }
    cerr << '\n';
}

/*
6
3 3 3 4 4 5
4 2
3 4 5 6

-- 1 1 2 2

7
1 5 7 2 10 10 6
7 0
1 2 3 4 5 6 7

-- 1 1 1 4 4 6 7

5
2 2 2 1 1
5 2
1 2 3 4 5

-- 1 1 1 4 4
1 1 1 4 2

17
1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9
1 2
17

--12
13
*/