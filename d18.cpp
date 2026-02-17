// 3606. Coupon Code Validator


#include <iostream>
using namespace std;
class Solution {
private:
    bool isvalid(string &s){
        if(s.empty()) return false;
        for(char c:s){
            if(!isalnum(c) && c!='_'){
                return false;
            }
        }
        return true;
    }    
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {

        unordered_map<string,int>priority={
            {"electronics",0},
            {"grocery",1},
            {"pharmacy",2},
            {"restaurant",3}
        };
        vector<pair<int,string>>primary;

        for(int i=0;i<code.size();i++){
            if(isActive[i] && priority.find(businessLine[i])!=priority.end() && isvalid(code[i])){
                primary.push_back({priority[businessLine[i]],code[i]});
            }
        }

        sort(primary.begin(),primary.end());
        vector<string>result;
        for(auto &p:primary){
            result.push_back(p.second);
        }

        return result;

        
    }
};
