#include<iostream>
#include<unordered_map>


using namespace std;


int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL);

    
    unordered_map<string, long long>mp;
    string s;
    int x;
    while (cin >> s) {
        cin >> x;
        if (!mp.contains(s))
            mp[s] = 0;
        mp[s] += x;
        cout << mp[s] << '\n';
    }
}