class Solution {
public:
    int minAddToMakeValid(string s) {
        int countfirst=0;
        int ans=0;
        for(auto ch:s){
            if(ch=='('){
                countfirst++;
                ans++;
            }
            else if(countfirst !=0 && ch==')'){
                countfirst--;
                ans--;
            }
            else if(countfirst==0 && ch==')'){
                ans++;
            }
        }
        return ans;
        
    }
};
