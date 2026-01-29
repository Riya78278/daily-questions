// 217. Contains Duplicate

#include<iostream>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int n:nums){
            mp[n]++;
        }
        for(auto &p:mp){
            if(p.second>1){
                return true;
            }
        }
        return false;
    }
};
