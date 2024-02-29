#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<any>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<cassert>

#define fori(it, a, b) for(int it = a; it < b; ++it)
#define all(x) (x).begin(),(x).end()
#define cn cout << '\n'
#define minel(v) *min_element(v.begin(), v.end());
#define maxel(v) *max_element(v.begin(), v.end());
#define sortv(v) sort(v.begin(), v.end());
#define forl(a, k, b) for(long long a = k; a < b; ++a)
#define useless ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

using ll = long long;
using str = string;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;

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


//Definition for singly - linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
 
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int perenos = 0;
		ListNode* head = new ListNode();
		ListNode* current;
		current = head;
		int summa, x, y;
		while (!(l1 == NULL && l2 == NULL && perenos == 0)) {

			if (l1 == NULL)
				x = 0;
			else x = l1->val;
			if (l2 == NULL)
				y = 0;
			else y = l2->val;

			summa = x + y + perenos;
			perenos = summa / 10;
			current->next = new ListNode(summa % 10);
			current = current->next;
			
			if (l1 != NULL)
				l1 = l1->next;
			if (l2 != NULL)
				l2 = l2->next;

		}
		return head->next;
	}
	void print(ListNode* head) {
		do
		{
			cout << head->val << ' ';
			head = head->next;
		} while (head != NULL);

	}
};


int main()
{
	useless;

	//freopen("input.in", "rt", stdin);
	//freopen("output.out", "wt", stdout);

	ListNode l1_3(3);
	ListNode l1_2(4, &l1_3);
	ListNode l1(2, &l1_2);

	ListNode l2_3(4);
	ListNode l2_2(6, &l2_3);
	ListNode l2(5, &l2_2);

	/*ListNode l1(0);
	ListNode l2(0);*/


	/*ListNode l2_2(9);
	ListNode l2(9, &l2_2);

	ListNode l1(9);*/


	Solution S;
	S.print(S.addTwoNumbers(&l1, &l2));
}