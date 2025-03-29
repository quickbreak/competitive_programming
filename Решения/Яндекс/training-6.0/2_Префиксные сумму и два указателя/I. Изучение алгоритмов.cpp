#include <iostream>
#include <vector>
#include <set>

using namespace std;

namespace miha
{
    bool more(const pair<int, pair<int, int>>&p1, const pair<int, pair<int, int>>&p2) {
    if (p1.first > p2.first) {
        return true;
    }
    else if (p1.first == p2.first) {
        if (p1.second.first > p2.second.first) {
            return true;
        } 
        else if (p1.second.first == p2.second.first) {
            if (p1.second.second < p2.second.second) {
                return true;
            }
            else { // p1.second.second > p2.second.second
                return false;
            }
        }
        else { // p1.second.first < p2.second.first
            return false;
        }
    }
    else { // p1.first < p2.first
        return false;
    }
}
} // namespace miha

int main() {
    int n; cin >> n;
    set<pair<int, pair<int, int>>>fun, use;
    vector<int>a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        fun.insert({a[i], {x, i}});
        use.insert({x, {a[i], i}});
    }
    int mood;
    auto p1 = fun.begin();
    auto p2 = fun.rbegin();
    for (int i = 0; i < n; ++i) {
        cin >> mood;
        if (mood == 0) {
            p2 = fun.rbegin();
            // cerr << "\n" << p2->first << ", (" << p2->second.first << ", " << p2->second.second << ")\n";
            p1 = fun.lower_bound({ p2->first, {p2->second.first, 0LL} });
            if (miha::more(*p1, *p2)) {
                cout << p1->second.second + 1 << ' ';
                use.erase({ p1->second.first, {p1->first, p1->second.second} });
                fun.erase(p1);
            }
            else {
                cout << p2->second.second + 1 << ' ';
                use.erase({ p2->second.first, {p2->first, p2->second.second} });
                fun.erase(*p2);
            }
        }
        else {
            p2 = use.rbegin();
            p1 = use.lower_bound({ p2->first, {p2->second.first, 0LL} });
            if (miha::more(*p1, *p2)) {
                cout << p1->second.second + 1 << ' ';
                fun.erase({ p1->second.first, {p1->first, p1->second.second} });
                use.erase(p1);
            }
            else {
                cout << p2->second.second + 1 << ' ';
                fun.erase({ p2->second.first, {p2->first, p2->second.second} });
                use.erase(*p2);
            }
        }
    }
}

/*
5
1 2 3 4 5
5 4 3 2 1
1 0 1 0 0

-- 1 5 2 4 3 

6
3 10 6 2 10 1
3 5 10 7 5 9
0 0 1 1 0 1

-- 2 5 3 6 1 4 

1
2
5
0

-- 1

1
2
5
1

-- 1
*/