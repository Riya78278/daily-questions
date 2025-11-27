// 3381. Maximum Subarray Sum With Length Divisible by K
#include <iostream>
using namespace std;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        // using kadane algorithm

        vector<long long> prefixsum(nums.size());
        prefixsum[0] = nums[0];


        for(int i=1;i<nums.size();i++){
            prefixsum[i]=prefixsum[i-1]+nums[i];
        }

        long long result = LLONG_MIN;
        for(int start=0;start <k ;start++){
            int i=start;
            long long currsum=0;
            while(i<nums.size() && i+k-1 < nums.size()){
                int j=i+k-1;
                long long subsum = prefixsum[j] - (i > 0 ? prefixsum[i-1] : 0);

                currsum=max(subsum , currsum+subsum);
                result = max(result ,currsum);
                i=i+k;


            }
        }
        return result;

    }
};