class Solution {
public:
    int minMoves(int target, int d) {
        int i=target;
        int count=0;
       
       while(i>1){
        if(d==0){
            return count+=(i-1);
        }
                else if(  i%2==0){
                i=i/2;
                count++;
                d--;
            }
            else{
                i-=1;
                count++;
            }
       }
        return count;
    }
};