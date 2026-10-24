class Solution {
    void f(int n, vector<string>&ans,string str,int open,int close){
        if(open ==n && close ==n){
            ans.push_back(str);
            return;
        }
        if(close>open){
            return ;
        }

      if(open<n)  f(n,ans,str+'(',open+1,close);
      if(close<n)  f(n,ans,str+')',open,close+1);
    }

public:
    vector<string> generateParenthesis(int n) {
       vector<string>ans; 
       string str="";

        f(n,ans,str,0,0);
        return ans;
    }
};