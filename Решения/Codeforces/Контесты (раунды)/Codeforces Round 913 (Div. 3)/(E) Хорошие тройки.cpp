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
        while (true) {
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
    //a + b + c = n и digsum(a) + digsum(b) + digsum(c) = digsum(n)
    //найти кол-во таких троек a,b,c

    //если при сложении не было переходов, то тройка подходит
    // 23 + 12 + 4 = (2+1)(3+2+4) = 39
    // 2 + 3 + 1 + 2 + 4 == 2 + 1 + 3 + 2 + 4
    int t, num, dig; cin >> t;
    ll ans = 1, res;
    while (t-- > 0) {
        cin >> num;
        ans = 1;
        while (num > 0) {
            dig = num % 10;
            res = 0;
            fori(i, 0, 10){

                fori(j, 0, 10) {
                    if (dig - i - j >= 0) {
                        res++;
                    }
                }
            }
            ans *= ((res == 0) ? 1 : res);
            num /= 10;

        }
        cout << ans; cn;
    }
}