// Majority Element

#include <iostream>
using namespace std;

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        if(n==0){
            return -1;
            
        }
        if(n==1){
            return arr[0];
        }
        
        sort(arr.begin(),arr.end());
        int count=1;
        for(int i=0;i<n;i++){
            if(arr[i]==arr[i-1]){
                count++;
            }
            else{
                count=1;
            }
            if(count>n/2){
                return arr[i];
            }
        }
        return -1;
    }
};
