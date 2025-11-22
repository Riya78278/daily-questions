// 3190. Find Minimum Operations to Make All Elements Divisible by Three
#include <iostream>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%3 != 0){
                operations++;
            }
        }
        return operations;
    }
};