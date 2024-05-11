#include<algorithm>
#include<any>
#include<cassert>
#include<cmath>
#include<cstdio>
#include<deque>
#include<functional>
#include<iostream>
#include<map>
#include<queue>
#include<random>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<vector>

#define fori(it, a, b) for(int it = a; it < b; ++it)
#define all(x) (x).begin(),(x).end()
#define cn cout << '\n'
#define minel(v) *min_element(v.begin(), v.end());
#define maxel(v) *max_element(v.begin(), v.end());
#define sortv(v) sort(v.begin(), v.end());
#define forl(a, k, b) for(long long a = k; a < b; ++a)
#define useless ios_base::sync_with_stdio(false); cin.tie(NULL);
//define int long long;

using namespace std;

using ll = long long;
using str = string;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vector<int>>;

const ll mod = ll(1e9 + 7);

//base ^ p
ll binpow(ll base, ll p)
{
	if (p == 0)
		return 1;
	if (p == 1)
		return base;
	if (p % 2 == 0)
	{
		ll polovina = binpow(base, p / 2);
		return polovina * polovina % mod;
	}
	else
	{
		ll pminus = binpow(base, (p - 1) / 2);
		ll res = pminus * pminus % mod;
		return res * base % mod;
	}
}



//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int left, int right) {
		if (left == right)
			return head;
		ListNode* head_copy = head;
		ListNode* start; //изначально тут элемент, предшествующий left
		ListNode* stop;
		ListNode* x;
		x = head;
		int uk = 1;
		while (uk < left - 1) {
			x = x->next;
			++uk;
		}
		start = x;

		while (uk < right) {
			x = x->next;
			++uk;
		}
		stop = x;

		//stop->next = start;
		ListNode* previous;
		if (left == 1)
			previous = start;
		else {
			previous = start->next;
			start->next = x; // предшествующий левому указывает на правый
		}

		ListNode* current = previous->next;
		previous->next = stop->next;
		ListNode* following = current->next;
		int cnt = left;
		while (cnt < right) {
			if (current->next == nullptr)
			{
				current->next = previous;
				break;
			}
			following = current->next;
			current->next = previous;
			previous = current;
			current = following;
			++cnt;

		}
		if (left == 1)
			return stop;
		return head_copy;
		
	}
	void print(ListNode* head) {
		do
		{
			cout << head->val << ' ';
			head = head->next;
		} while (head != NULL);

	}
};



int32_t main()
{
	useless;
	//Test
	ListNode a_5(5);
	ListNode a_4(4, &a_5);
	ListNode a_3(3, &a_4);
	ListNode a_2(2, &a_3);
	ListNode a_1(1, &a_2);
	//Test 1
	ListNode b_1(2);
	//Test 2
	ListNode c_2(2);
	ListNode c_1(1, &c_2);
	//Test 3
	ListNode d_3(3);
	ListNode d_2(2, &d_3);
	ListNode d_1(1, &d_2);
	Solution s;
	s.print(s.reverseBetween(&d_1, 3, 3));
}