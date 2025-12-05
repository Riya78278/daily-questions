// 3432. Count Partitions with Even Sum Difference
#include <iostream>
using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int sum=0;
        int count=0;
        for(int i=0;i<n-1;i++){
            ans +=nums[i];
            for(int j=i+1;j<n;j++){
                sum +=nums[j];

            }
            if((ans-sum)%2==0){
                count++;
            }
            sum=0;
        }
        return count;
    }
};