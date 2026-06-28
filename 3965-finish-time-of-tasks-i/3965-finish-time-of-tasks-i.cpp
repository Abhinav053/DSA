class Solution {
   
    long long f(int node,unordered_map<int,vector<int>>&adj,vector<int>& baseTime){
       if(adj.find(node)==adj.end())return baseTime[node];
        long long maxi=0;
       long long mini=LLONG_MAX;
       long long ans=0;
        for(auto k:adj[node]){
          ans= f(k,adj,baseTime);
            maxi=max(maxi,ans);
            mini=min(mini,ans);
        }
        return baseTime[node] + maxi + (maxi - mini);
    }
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        unordered_map<int,vector<int>>adj;
        vector<int>indeg(n,0);
        for(auto k:edges){
            adj[k[0]].push_back(k[1]);
            indeg[k[1]]++;
        }
        int root=-1;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                root=i;
            }
        }

        

       long long k= f(root,adj,baseTime);
        //cout<<maxi<<" "<<mini<<" ";

        return k;
    }
};