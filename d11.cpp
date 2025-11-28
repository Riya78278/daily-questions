// Binary Prefix Divisible By 5 (24.nov.2025)


#include <iostream>
using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n=nums.size();
        int remainder=0;
        vector<bool>ans;
        ans.reserve(n);
        for(int i=0;i<n;i++){
            remainder=(remainder*2 +nums[i])%5;
            ans.push_back(remainder==0);
        }
        return ans;
    }
};
