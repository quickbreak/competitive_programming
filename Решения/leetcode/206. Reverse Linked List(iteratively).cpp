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


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head->val == NULL)
            return head;
        if (head->next == nullptr)
            return head;
        ListNode* curr = head->next;
        ListNode* fol;
        ListNode* prev = head;
        head->next = nullptr;
        while (true) {
            if (curr->next == nullptr) {
                curr->next = prev;
                break;
            }

            fol = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fol;
        }
        return curr;

    }
};


int main()
{
    useless;

    //Test:
    ListNode n_4(1);
    ListNode n_3(2);
    n_3.next = &n_4;
    ListNode n_2(2);
    ListNode n_1(5, &n_2);
    Solution s;
    cout << s.reverseList(&n_1)->next->val;
    //s.reverseList(&n);

    /* int x = 5;
     int* y = &x;*/

}