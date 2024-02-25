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

#define minel(v) *min_element(v.begin(), v.end());
#define maxel(v) *max_element(v.begin(), v.end());
//#define summ(v) *accumulate(v.begin(), v.end());
#define sortv(v) sort(v.begin(), v.end());

using namespace std;

int main() {//aba aba  0-5,0-2,3-5 -> 2,3
	//        abba abba              0-3,2-5
	string s;
	cin >> s;
	int n = s.size();
	for (int i = 0; i <= (n-1)/4; i++)//ñòðîêà S.size() ÂÑÅÃÄÀ ×¨ÒÍÎÉ ÄËÈÍÛ
	{
		if (s[i] == s[n - 1 - i] && s[i] == s[(n - 1) / 2-i])//0-5,0-2 -> 2,5
		{
			s[n / 2+i] = s[i];
		}
		else if (s[i] == s[n - 1 - i] && s[i] == s[n / 2+i])//0-5,0-3 -> 2,5
		{
			s[(n-1)/ 2-i] = s[i];
		}
		else if (s[i] == s[(n - 1)/2-i] && s[i] == s[n / 2+i])//0-2,0-3 -> 2,3
		{
			s[n - 1 - i] = s[i];
		}
		else if (s[n-1-i] == s[(n - 1) / 2-i] && s[n-1-i] == s[n / 2+i])//3-5,2-5 -> 2,3
		{
			s[i] = s[n - 1 - i];
		}
		else if (s[i] == s[n - 1 - i])//0-5
		{
			s[(n - 1) / 2-i] = s[i];
			s[n / 2+i] = s[i];
		}
		else if (s[i] == s[(n - 1)/2-i])//0-2
		{
			s[n - 1 - i] = s[i];
			s[n / 2+i] = s[i];
		}
		else if (s[i] == s[n/2+i])//0-3
		{
			s[n - 1 - i] = s[i];
			s[(n-1)/ 2-i] = s[i];
		}
		else if (s[(n-1)/2-i] == s[n / 2+i])//2-3
		{
			s[(n - 1) - i] = s[n/2+i];
			s[i] = s[n/2+i];
		}
		else if (s[(n - 1) -i] == s[(n-1) / 2+i])//2-5
		{
			s[n/2+i] = s[(n-1) / 2-i];
			s[i] = s[(n-1) / 2-i];
		}
		else if (s[(n - 1) -i] == s[n / 2+i])//3-5
		{
			s[(n - 1) /2-i] = s[n / 2+i];
			s[i] = s[n / 2+i];
		}
		else {
			s[n - 1 - i] = s[i];
			s[(n - 1) / 2-i] = s[i];
			s[n / 2+i] = s[i];
		}
	}
	cout << s;
}