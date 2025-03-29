#include<iostream>
#include<deque>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    deque<pair<int, int>>dq;
    for (int i = 0, x; i < n; ++i) {
        if (!dq.empty() && dq.back().second == i - k) {
            dq.pop_back();
        }
        cin >> x;
        while (!dq.empty() && dq.front().first > x) {
            dq.pop_front();
        }
        dq.push_front({x, i});
        if (i >= k - 1) {
            cout << dq.back().first << '\n';
        }
    }
}