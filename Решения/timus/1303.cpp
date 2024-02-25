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


void solve(vector<pair<int, int>>a, int m)
{
    sort(a.begin(), a.end());
    int n = a.size();
    int cur_end = 0;
    int maxr = -1000000;
    vector<pair<int, int>>res;
    int maxi = 0;
    bool flag = false;
    int i = 0;
    while (i < n)
    {
        if (a[i].first <= cur_end)
        {
            i += 1;
            if (a[i - 1].second > maxr)
            {

                maxr = a[i - 1].second;
                maxi = i - 1;
                flag = true;
            }
        }
       
        else if(flag)
        {
            cur_end = maxr;
            res.push_back(a[maxi]);
            flag = false;
        }
        else 
            i += 1;

        if (cur_end >= m)
            break;
        
    }
        

    if (flag)
    {
        cur_end = maxr;
        res.push_back(a[maxi]);
    }
    if (cur_end < m)
        cout<<"No solution";
    else {
        cout<<res.size()<<'\n';
        for (int j = 0; j < res.size(); j++)
            cout << res[j].first<<' '<<res[j].second<<'\n';
    }
}


int main()
{
    int m;
    cin >> m;
    vector<pair<int, int>>a;
    int l, r;
    pair<int, int>stop = { 0, 0 };
    while (true) {
        cin >> l >> r;
        pair<int, int>p = { l, r };
        if (p == stop)
            break;
        a.push_back({l, r});
    }
    solve(a, m);
}