#include<iostream>
#include<stack>
// #include<cctype>
#include<cassert>
#include<string>

using namespace std;

int main() {
    char ch;
    stack<string>st;
    int x, y, res;
    while (cin >> ch && ch != ' ') {
        if (isdigit(ch)) {
            st.push(to_string(ch - '0'));
        } else {
            y = stoi(st.top());
            st.pop();
            x = stoi(st.top());
            st.pop();
            if (ch == '+') {
                res = x + y;
            } else if (ch == '-') {
                res = x - y;
            } else if (ch == '*') {
                res = x * y;
            } else {
                assert(false);
            }
            st.push(to_string(res));
        }
    }
    cout << stoi(st.top());
    cerr << '\n';
}