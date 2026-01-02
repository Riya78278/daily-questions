// N-Repeated Element in Size 2N Array

#include<iostream>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;   // FIX 1
        }

        for (int i = 0; i < nums.size(); i++) {
            if (mp[nums[i]] > 1) {   // FIX 2
                return nums[i];     // FIX 3
            }
        }

        return -1; // safety
    }
};
