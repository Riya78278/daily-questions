class Solution {
  public:
    int minFlips(string& s) {
        // code here
        int flip1=0;
        int flip2=0;
        
        for(int i=0;i<s.size();i++){
            
            char expect1=(i%2==0)?'0':'1';
            char expect2=(i%2==0)?'1':'0';
            
            flip1 +=(s[i]!=expect1);
            flip2 +=(s[i]!= expect2);
        }
        return min(flip1,flip2);
        
        
    }
};
