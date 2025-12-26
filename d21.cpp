// Find triplets with zero sum
#include <iostream>
using namespace std;

class Solution {
  public:
    bool findTriplets(vector<int> &arr) {
        // code here
        int n=arr.size();
        
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            int j=i+1;
            int k=arr.size()-1;
            
            while(j<k){
                int sum=arr[i]+arr[j]+arr[k];
                
                if(sum==0){
                    return true;
                }
                else if(sum>0){
                    k--;
                }else{
                    j++;
                }
            }
        }
        return false;
    }
};