// 2211. Count Collisions on a Road
#include <iostream>
using namespace std;

class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int collisions = 0;
        
        // Remove leading 'L's (they just move away without collisions)
        int left = 0;
        while (left < n && directions[left] == 'L') {
            left++;
        }
        
        // Remove trailing 'R's (they just move away without collisions)
        int right = n - 1;
        while (right >= 0 && directions[right] == 'R') {
            right--;
        }
        
        // Count all cars that are not 'S' in the middle section
        for (int i = left; i <= right; i++) {
            if (directions[i] != 'S') {
                collisions++;
            }
        }
        
        return collisions;
    }
};