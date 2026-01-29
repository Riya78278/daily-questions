// 3623. Count Number of Trapezoids I
#include <iostream>
using namespace std;

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int mod=1e9+7;
        unordered_map<int,int>mp;
        for(auto &point :points){
            int y=point[1];
            mp[y]++;
        }
        long long previousline=0;
        long long result=0;
        


        for(auto &it :mp){
            long long count=it.second;
            long long horizontalline = count *(count-1)/2;

            result += horizontalline*previousline;
            previousline +=horizontalline;

        }
        return result % mod;
    }
};
