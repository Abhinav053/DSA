class Solution {
    vector<vector<int>>dp;
    bool f(string& s,int i,int cnt){
        if(cnt<0)return false;
        if(i>=s.size()){
            if(cnt==0)return true;
            return false;
        }
        if(dp[i][cnt]!=-1)return dp[i][cnt];
        bool left=false;
        bool right=false;
        bool str=false;

        if(s[i]=='(')left=f(s,i+1,cnt+1);
        else if(s[i]==')')right=f(s,i+1,cnt-1);
         else {
         left=   f(s,i+1,cnt+1);
          right=  f(s,i+1,cnt-1);
           str= f(s,i+1,cnt);
         }
         return dp[i][cnt]= left||right||str;
    }
public:
    bool checkValidString(string s) {
        int n=s.size();
        if(n==1){
            if(s[0]!='*')return false;
        }
        dp.assign(n+1,vector<int>(n+1,-1));
        return f(s,0,0);
    }
};