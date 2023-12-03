class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
    
        
            
            for(int i=0;i<nums.size();i++){
                int count=0;
                int tar=nums[i];
           for(int j=0;j<nums.size();j++){
           if(nums[j]==tar){
               count++;
           }
            }
                if(count==1){
                    return tar;
                }
            }
        
         
        return -1;
    }
};