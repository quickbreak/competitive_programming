#include <iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<iomanip>

using namespace std;
//cout << "swap " << i <<' '<< j << endl;
//fflush(stdout);
int main() {
	int n;
	cin >> n;
	set<int>zero;//0 poses
	set<int>one;//1 poses
	set<int>two;//2 poses
	int x;
	for (int i = 1; i <= n; i++)
	{
		cout << "get " << i << endl;
		fflush(stdout);
		cin >> x;
		if (x == 0)
		{
			zero.insert(i);
		}
		else if (x == 1)
		{
			one.insert(i);
		}
		else {
			two.insert(i);
		}
	}
	int n0 = zero.size();
	int n1 = one.size();
	int n2 = two.size();
	vector<pair<int, int>>ans;
	set<int>::iterator it;
	it = zero.begin();
	//int i = 0;
	for(int i=1;i<=n0;i++)
	{
		//i++;
		int j = *zero.begin();
		zero.erase(zero.begin());
		if (j !=i)
		{
			if (one.find(i) != one.end())
			{

			}
		}
	}

	cout << "Sorted!";
}