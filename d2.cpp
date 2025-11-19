// 717. 1-bit and 2-bit Characters (18.nov.2025)
#include <iostream>
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        int n = bits.size();
        while (i < n - 1) {
            if (bits[i] == 0) {
                i += 1;  
            } else {
                i += 2;  
            }
        }
        return i == n - 1;  // true if last is single-bit
    }
};
