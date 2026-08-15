class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int z=0, x=0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0)z++;
            x=x^nums[i];
        }

        if(x!=0)return nums.size();
        if(z>0)return nums.size()-1;
        return 0;
    }
};