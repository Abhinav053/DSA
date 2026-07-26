class Solution {
public:
    bool lemonadeChange(vector<int>& b) {
        int n=b.size();
        int f=0;
        int t=0;
        int tt=0;
        for(int i=0;i<n;i++){
            if(b[i]==5){
                f++;
            }
            else if(b[i]==10){
               if(f<=0)return false;
               t++;
               f--;
            }
            else {
                tt++;
                if(t<=0){
                    if(f<3)return false;
                    f=f-3;
                }
                if(t>0){
                    if(f<=0)return false;
                    t--;
                    f--;

                }
               
            }
        }
        return true;
    }
};