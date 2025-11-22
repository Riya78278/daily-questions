// Anagram
#include <iostream>
using namespace std;

class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        // code here
        unordered_map<char,int>map;
        for(int i=0;i<s1.size();i++){
            map[s1[i]]++;
        }
        for(int i=0;i<s2.size();i++){
            if(map.find(s2[i])!=map.end()){
                map[s2[i]]--;
                if(map[s2[i]]==0){
                    map.erase(s2[i]);
                }
            }
            else{
                return false;
            }
        }
        if(!map.empty()){
            return false;
        }
        return true;
    }
    
};