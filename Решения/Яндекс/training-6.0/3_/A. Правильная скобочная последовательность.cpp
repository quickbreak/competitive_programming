#include<iostream>
#include<stack>

using namespace std;

int main() {
    stack<char>st;
    char ch;
    while (cin >> ch) {
        if (st.empty()) {
            st.push(ch);
            continue;
        }
        if (ch == ')' && st.top() == '(' || ch == '}' && st.top() == '{' || ch == ']' && st.top() == '[') {
            st.pop();
        } else {
            st.push(ch);
        }
    }
    std::cout << (st.empty() ? "yes" : "no");
}