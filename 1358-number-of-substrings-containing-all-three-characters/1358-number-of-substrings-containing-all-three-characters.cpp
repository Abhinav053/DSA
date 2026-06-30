class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        int i=0;
        int j=0;
        int count=0;
        while(j<s.size()){
            mp[s[j]]++;
            if(mp.size()==3){
                //int freq=0;
                while(mp.size()==3){
               
                mp[s[i]]--;
                if(mp[s[i]]==0)mp.erase(s[i]);
               count+=(1+n-1-j);
               i++;
                }
                
                
            }
            j++;
        }
        return count;
    }
};