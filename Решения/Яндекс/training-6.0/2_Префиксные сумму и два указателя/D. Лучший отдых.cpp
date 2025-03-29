#include <iostream>
#include <set>

using namespace std;

#define isz(x) (int)x.size()

int main() {
    int n, k; cin >> n >> k;
    multiset<int>st;
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        st.insert(x);
    }
    int ans = 0, val = 0;
    auto p = st.begin();
    while(isz(st) > 0) {
        ++ans;
        p = st.begin();
        while(p != st.end()) {
            val = *p;
            st.erase(p);
            p = st.lower_bound(val + k + 1);
        }
    }
    cout << ans;
}