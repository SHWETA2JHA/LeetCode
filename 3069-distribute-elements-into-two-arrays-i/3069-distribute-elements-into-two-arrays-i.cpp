class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>v1,v2;
        int i=0;
        v1.push_back(nums[0]);
        v2.push_back(nums[1]);
        i=2;
        while(i<n){
            if(v1.back()>v2.back())v1.push_back(nums[i++]);
            else v2.push_back(nums[i++]);
        }
        
        for(auto j : v2)v1.push_back(j);
        return v1;
    }
};