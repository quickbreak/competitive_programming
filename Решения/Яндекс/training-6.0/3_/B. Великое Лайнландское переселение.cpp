#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main() {
    int n; cin >> n;
    stack<pair<int, int>>st;
    vector<int>res(n);
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        while (!st.empty() && st.top().first > x) {
            res[st.top().second] = i;
            st.pop();
        }
        st.push({x, i});
    }
    while (!st.empty()) {
        res[st.top().second] = -1;
        st.pop();
    }
    for (int& g : res) {
        cout << g << ' ';
    }
}