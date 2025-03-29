#include <iostream>

using namespace std;

int main() {
    int n; 
    long long c;
    cin >> n >> c;
    string s; cin >> s;
    int a_cnt = 0, b_cnt = 0, ans = 0, l = 0;
    long long rudeness = 0;
    for (int r = 0; r < n; ++r) {
        // добавляем правую букву
        if (s[r] == 'a') {
            ++a_cnt;
        } else if (s[r] == 'b') {
            ++b_cnt;
            rudeness += a_cnt;
        }
        while (rudeness > c && l <= r) {
            // удаляем левую букву
            if (s[l] == 'a') {
                rudeness -= b_cnt;
                --a_cnt;
            } else if (s[l] == 'b') {
                --b_cnt;
            }
            ++l;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans;
}