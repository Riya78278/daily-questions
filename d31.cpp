class Solution {
private:
    void dfs(int node,vector<vector<int>>&adjlist,vector<int>&vis,int &nodes,int &edgecount){
        vis[node]=1;
        nodes++;
        edgecount+=adjlist[node].size();

        for(auto it:adjlist[node]){
            if(!vis[it]){
                dfs(it,adjlist,vis,nodes,edgecount);
            }
        }
    }    
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adjlist(n);
        for(auto e: edges){
            int u=e[0];
            int v=e[1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        int compcount=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            
            if(!vis[i]){
                int node=0;
                int edgcount=0;
                dfs(i,adjlist,vis,node,edgcount);
                edgcount=edgcount/2;

                if(edgcount == node*(node-1)/2){
                compcount++;
            }
            }
            //edgcount=edgcount/2;

            
        }
        return compcount;

    }
};
