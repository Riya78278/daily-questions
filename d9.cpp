// Equilibrium Point
#include <iostream>
using namespace std;
class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
        int n=arr.size();
        int left=0;
        int right=0;
        int index=-1;
        for(int i=0;i<n;i++){
            right += arr[i];
        }
        for(int i=0;i<n;i++){
            right -=arr[i];
            
            if(left==right){
                index =i;
                break;
            }
            left +=arr[i];
        }
        return index;
    }
};