class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        int count=0;
        bool i_flag =false;
        bool j_flag=false;
        while(true){
            if(!i_flag && (nums[i]==mini|| nums[i]==maxi)){
                count++;
                i_flag=true;
            }
              if(!j_flag && (nums[j]==mini|| nums[j]==maxi)){
                count++;
                j_flag=true;
            }
            if(i_flag && j_flag)break;
        if(!i_flag && !j_flag)    count+=2;
        else count++;
            i++;
            j--;
        }
           i_flag =false;
         j_flag=false;
        int count1=0;
        for(int i=0;i<nums.size();i++){
             if(i_flag && j_flag)break;
            if(nums[i]==mini)i_flag=true;
            if(nums[i]==maxi)j_flag=true;
            count1++;

        }
          i_flag =false;
         j_flag=false;
        int count2=0;

         for(int i=nums.size()-1;i>=0;i--){
             if(i_flag && j_flag)break;
            if(nums[i]==mini)i_flag=true;
            if(nums[i]==maxi)j_flag=true;
            count2++;

        }
        return min({count,count2,count1});
    }
};