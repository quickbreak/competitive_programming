#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int>a(n);
    for(int prev = 0, i = 0; i < n; ++i) {
        cin >> a[i];
        prev += a[i];
        cout << prev << ' ';
    }
}