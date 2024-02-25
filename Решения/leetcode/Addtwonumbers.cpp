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
		ListNode curr(0);
		//curr = (0, nullptr);
		ListNode previous(0);
		//previous = (0, nullptr);
		int perehod = 0;
		//previous.val = (l1->val + l2->val + perehod) % 10;
		//perehod = ((l1->val + l2->val + perehod) / 10 != 0);
		//if (l1->next == nullptr && l2->next == nullptr) {
		//	previous.next = nullptr;
		//	return &previous;

		//}

		ListNode head;
		head.val = (l1->val + l2->val + perehod) % 10;
		int cnt = 0;
		
		do {
			cnt++;
			if (l1->next == nullptr) {
				l2 = l2->next;
				curr.val = (l2->val + perehod) % 10;
				perehod = ((l1->val + l2->val + perehod) / 10 != 0);
			}
			else if (l2->next == nullptr) {
				l1 = l1->next;
				curr.val = (l1->val + perehod) % 10;
				perehod = ((l1->val + l2->val + perehod) / 10 != 0);
			}
			else {
				l1 = l1->next;
				l2 = l2->next;
				curr.val = (l1->val + l2->val + perehod) % 10;
				perehod = ((l1->val + l2->val + perehod) / 10 != 0);
			}
			previous.next = &curr;
			if (cnt == 1)
				head.next = &curr;
			previous = curr;
		} while (l1->next != nullptr || l2->next != nullptr);
		
		return &head;

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

	Solution S;
	cout << S.addTwoNumbers(&l1, &l2);
}