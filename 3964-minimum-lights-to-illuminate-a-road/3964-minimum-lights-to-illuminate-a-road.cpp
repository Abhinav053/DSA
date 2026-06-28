class Solution {
public:
    int minLights(vector<int>& lights) {
        int n=lights.size();
        vector<bool> v(n,false);
        int r=-1;
        for(int i=0;i<n;i++){
            if(lights[i]>0){
                r=max(r,i+lights[i]);
            }
            if(r>=i){
                v[i]=true;
            }
        }
        int l=n;
        for(int i=n-1;i>=0;i--){
            if(lights[i]>0){
                l=min(l,i-lights[i]);
            }
            if(l<=i){
                v[i]=true;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(!v[i]){
                ans++;
                i+=2;
            }
        }
        return ans;
    }
};