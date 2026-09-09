class Solution {
public:
    int countRotations(string s, int k) {
        string str=s+s;
        int ans=0;
        for(int i=0;i<s.size();i++){
            int count=0;
            for(int j=i;j<i+s.size()-1;j++){
            if(str[j]==str[j+1])count++;
            }
            if(count==k)ans++;
        }
        return ans;
    }
};