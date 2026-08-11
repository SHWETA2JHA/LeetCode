class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int ans=nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==nums[i-1]+1){
                ans+=nums[i];
            }else break;
        }
        unordered_map<int,int>mp;
        for(auto i: nums)mp[i]++;

        for(int i=0; i<50; i++){
            if(mp.find(ans)!=mp.end())ans++;
            else return ans;
        }
        return ans;
    }
};