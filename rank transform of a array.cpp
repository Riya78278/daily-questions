class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>ans;
        unordered_map<int,int>numrank;

        for(auto num:arr){
            if(numrank.find(num)==numrank.end()){
                ans.push_back(num);
                numrank[num]=0;
            }
        }
        sort(ans.begin(),ans.end());

        for(int i=0;i<ans.size();i++){
            numrank[ans[i]]=i+1;
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=numrank[arr[i]];
        }
        return arr;
    }
};
