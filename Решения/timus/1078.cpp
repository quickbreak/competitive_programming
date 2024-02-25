#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<stack>

using namespace std;


int n;


void solve(vector<pair<pair<int, int>, int>>a)
{
    sort(a.begin(), a.end());
    vector<pair<int, int>>d(n, {1, -1}); //уровень вложенности и порядковый номер предыдущего по размеру
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j].first.first < a[i].first.first)
                if (a[j].first.second>a[i].first.second)
                    if (d[j].first + 1 > d[i].first)
                    {
                        d[i].first = d[j].first + 1;
                        d[i].second = j;
                    }
        }
    }
    int ans = 0;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (d[i].first > ans)
        {
            ans = d[i].first;
            index = i;
        }

    }

    cout << ans << '\n';
    cout << a[index].second + 1;
    while (d[index].first != 1)
    {
        index = d[index].second;
        cout << ' ' << a[index].second + 1;
    }

}


int main()
{
    cin >> n;
    vector<pair<pair<int, int>, int>>a;
    int l, r;
    for (int i = 0; i < n; i++)
    {
        cin >> l >> r;
        a.push_back({ { l, r}, i });
    }
    solve(a);
}