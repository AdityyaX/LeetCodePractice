class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int avg=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==i){
                avg=i+1;
                continue;

            }

            else{
                // cout<<i<<endl;
                return (i);
            }
        }
        return avg;
    }
};