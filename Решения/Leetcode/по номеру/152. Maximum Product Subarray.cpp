#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minprefix = 1;
        int prefixproduct = 1, ans = nums[0];
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (prefixproduct == 0) {
                prefixproduct = 1;
                minprefix = 1;
            }
            prefixproduct *= nums[i];
            if (prefixproduct >= 0)
                ans = max(ans, prefixproduct);
            else {
                ans = max(ans, prefixproduct / minprefix);
                if (minprefix == 1)
                    minprefix = prefixproduct;
                minprefix = max(minprefix, prefixproduct);
            }
        }
        return ans;
    }
};

int main() {
    vector<int>a = { -1,0,-2,2 };
    Solution S;
    cout << S.maxProduct(a);
}