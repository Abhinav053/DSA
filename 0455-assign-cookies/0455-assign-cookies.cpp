class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int mini=1e9;
        int j=0;
        int maxi=-1e9;
        int count=0;
        bool found=false;
        for(int i=0;i<s.size();i++){
            if(j==g.size())break;
            if(j==0 || found){
                mini=g[j];
              
                found=false;
            }
            if(mini<=s[i]){
                count++;
                  j++;
                found=true;
            }
        }
        return count;

    }
};