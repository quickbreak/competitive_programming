#include<iostream>
#include<set>


using namespace std;


int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m, u, v; cin >> n >> m;
    set<pair<int, int>>st;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        if (st.find({ v,u }) != st.end() || u == v)
            continue;
        st.insert({ u, v });

    }
    cout << n << ' ' << st.size() << '\n';
    while (st.size() > 0) {
        cout << st.begin()->first << ' ' << st.begin()->second << '\n';
        st.erase(st.begin());

    }

}
