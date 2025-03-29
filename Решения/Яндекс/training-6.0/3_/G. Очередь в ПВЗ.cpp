#include<iostream>
#include<queue>

using namespace std;
using ll = long long;

int main() {
    int n, b; cin >> n >> b;
    ll ans = 0;
    deque<pair<ll, int>>q;
    ll k, cnt;
    pair<ll, int>p;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        q.push_back({x, i});
        k = b;
        while (k > 0 && !q.empty()) {
            p = q.front();
            q.pop_front();
            cnt = min(p.first, k);
            ans += cnt * (i - p.second + 1);
            p.first -= cnt;
            k -= cnt;
            if (p.first > 0)
                q.push_front(p);
        }
    }
    while (!q.empty()) {
        p = q.front();
        q.pop_front();
        ans += p.first * (n - p.second + 1);
    }
    cout << ans;
    cerr << '\n';
}

/*
3 4
1 5 9
-- 22

1 1
0
-- 0

2 1
0 0
-- 0

2 1
1 1
-- 2

2 1
1 5
-- 10

2 1
5 5
-- 1 + 2 + 3 * 3 + 5 * 2 = 22
*/