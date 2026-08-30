class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini=INT_MAX, maxi=INT_MIN,  j=-1, k=-1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                j=i;
            }
            if(nums[i]<mini){
                mini=nums[i];
                k=i;
            }
        }

        mini=min(j,k), maxi=max(j,k);
        int ans=maxi+1, rem=nums.size()-mini;
        ans=min(ans, rem);
        rem=mini+1+nums.size()-maxi;
        ans=min(ans, rem);

        return ans;
    }
};