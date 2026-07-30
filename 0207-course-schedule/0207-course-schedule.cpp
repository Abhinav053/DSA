class Solution {
    bool f(unordered_map<int,vector<int>>&adj, vector<int>&vis,vector<int>&pathvis,int node){
        vis[node]=1;
        pathvis[node]=1;
        for(auto k:adj[node]){
            if(!vis[k]){
               if( f(adj,vis,pathvis,k))return true;
            }
            else {
                if(pathvis[k])return true;
            }
        }
        pathvis[node]=0;
        return false;
    }
public:
    bool canFinish(int num, vector<vector<int>>& p) {
       
        vector<int>vis(num,0);
        vector<int>pathvis(num,0);
        unordered_map<int,vector<int>>adj;
        for(auto k:p){
            adj[k[1]].push_back(k[0]);
        }

        
       for(int i=0;i<num;i++){
        if(!vis[i]){
            if(f(adj,vis,pathvis,i))return false;
        }
       }
       return true;
    }
};