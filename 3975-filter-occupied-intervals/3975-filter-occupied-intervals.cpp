class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals,
                                                int fs, int fe) {
        vector<vector<int>> merged;
        vector<vector<int>> ans;

        sort(occupiedIntervals.begin(), occupiedIntervals.end());

       
            
        int cx=occupiedIntervals[0][0],cy=occupiedIntervals[0][1];
        for(int i=1;i<occupiedIntervals.size();i++){
            int tx=occupiedIntervals[i][0],ty=occupiedIntervals[i][1];
            if(cy>=tx || tx==cy+1){
                cy=max(cy,ty);
            }
            else{
                merged.push_back({cx,cy});
                cx=tx,cy=ty;
            }
        }
        merged.push_back({cx,cy});

        
        for (auto &it : merged) {
            int s = it[0];
            int e = it[1];

           
            if (e < fs || s > fe) {
                ans.push_back({s, e});
            }

            else if (s >= fs && e <= fe) {
                continue;
            }
           
            else if (s < fs && e <= fe) {
                ans.push_back({s, fs - 1});
            }
          
            else if (s >= fs && e > fe) {
                ans.push_back({fe + 1, e});
            }
            
            else {
                ans.push_back({s, fs - 1});
                ans.push_back({fe + 1, e});
            }
        }

        return ans;
    }
};