#include<iostream>
#include<vector>


using namespace std;


int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int a = 1;
    vector<int>piramid;
    int prev = 0;
    int uk = 2;
    while (prev < 295240) {
        piramid.push_back(prev + (a));
        prev = prev + a;
        a = a + uk++;
    }

    //dp
    vector<vector<int>> d(300001, vector<int>(120, 3e5));
    for (int i = 0; i < 120; ++i)
        d[0][i] = 0;
    for (int i = 1; i < 300001; ++i) {

        for (int j = 0; piramid[j] <= i; ++j) {
            d[i][j] = min(d[i][j], d[i - piramid[j]][j] + 1);
        }
    }



    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> uk;
        ans = 1e9;
        for (int j = 0; j < 120; ++j) {
            ans = min(ans, d[uk][j]);
        }
        cout << ans << '\n';

    }

}