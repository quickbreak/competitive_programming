#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>
#include<vector>
#include<algorithm>
#include<stack>
#include<map>

using namespace std;

using ll = long long;
using str = string;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	map<char, int>mp;
	str s;
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++)
	{
		if (mp.find(s[i]) == mp.end())
		{
			mp.insert({ s[i], 1 });
		}
		else {
			mp.find(s[i])->second++;
		}
	}
	int m = mp.size();
	if (m > 4 or m<2)
	{
		cout << "No";
		return 0;
	}
	else {
		if (m == 2) 
		{
			if (mp.begin()->second > 1 and mp.rbegin()->second > 1)
				cout << "Yes";
			else cout << "No";
		}
		else if (m == 3)
		{
			while (mp.size() > 0)
			{
				if (mp.begin()->second > 1)
				{
					cout << "Yes";
					return 0;
				}
				mp.erase(mp.begin());
			}
			cout << "No";
		}
		else {
			cout << "Yes";
		}
	}
}