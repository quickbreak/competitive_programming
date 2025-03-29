#include<iostream>
#include<cassert>
#include<string>
#include<vector>

using namespace std;
using ll = long long;

int main() {
    int t; cin >> t;
    string s;
    char oper;
    int num;
    ll summa = 0;
    vector<pair<int, ll>>a;
    int uk = -1; // индекс последнего существующего элемента
    while (t --> 0) {
        cin >> s;
        if (s[0] == '+') {
            num = stoi(s.substr(1));
            if (uk == a.size() - 1) { // почему помогло uk >= a.size() - 1  -->  uk == a.size() - 1   ????
                if (uk >= 0) {
                    summa = a[uk].second;
                } else {
                    summa = 0LL;
                }
                a.push_back({num, summa + num});
            } else {
                // assert(uk > a.size() - 1); // как добавление этой строки может провоцировать RE???
                if (uk >= 0) {
                    summa = a[uk].second;
                } else {
                    summa = 0LL;
                }
                a[uk + 1] = {num, summa + num};
            }
            ++uk;
        } else if (s[0] == '-') {
            cout << a[uk].first << '\n';
            a[uk] = {0, 0LL};
            --uk;
        } else if (s[0] == '?') {
            num = stoi(s.substr(1));
            if (num <= 0) {
                cout << 0 << '\n';
            }
            else {
                summa = a[uk].second - (uk - num >= 0 ? a[uk - num].second : 0LL);
                cout << summa << '\n';
            }
        } else {
            assert(false);
        }
    }
}

/*
7
+1
+2
+3
?2
-
-
?1

-- 
5
3
2
1
*/