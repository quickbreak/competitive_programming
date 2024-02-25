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

#define fori(it, a, b) for(int it = a; it < b; it++)
#define all(x) (x).begin(),(x).end()
#define cn cout << '\n'
#define minel(v) *min_element(v.begin(), v.end());
#define maxel(v) *max_element(v.begin(), v.end());
#define sortv(v) sort(v.begin(), v.end());
#define forl(a, k, b) for(long long a = k; a < b; a++)
#define useless ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

using ll = long long;
using str = string;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* x;
        x = head;
        vector<int>a;
        while(true) {
            a.push_back(x->val);
            if (x->next == nullptr)
                break;
            
        }
        int n = a.size();
        for (int i = 0; i < n / 2; ++i) {
            if (a[i] != a[n - i - 1]) {
                return false;
            }
        }
        return true;

    }
};


int main()
{
    useless;

    ListNode El1;
    ListNode El2;
    El1.val = 3;
    El2.val = 6;
    //ListNode* p;
    //p = &El2;
    El1.next = &El2;
    cout << El1.next->val;

    int n;
    ListNode el;
    fori(i, 0, n)
    {
        cin >> el.val;
    }
}