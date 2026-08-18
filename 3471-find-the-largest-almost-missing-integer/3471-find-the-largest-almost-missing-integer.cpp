class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int maxi=INT_MIN;

        for(auto i: nums){
            mp[i]++;
            maxi=max(maxi,i);
        }
        if(k==nums.size())return maxi;

        int maxi2=INT_MIN;
        if(k==1){
            for(auto i: mp){
                if(i.second==1)maxi2=max(maxi2, i.first);
            }
            return maxi2==INT_MIN?-1:maxi2;
        }

        int fir=nums[0], last=nums[nums.size()-1];
        if(mp[fir]>1 && mp[last]==1)return last;
        else if(mp[fir]==1 && mp[last]>1)return fir;
        else if(mp[fir]==1 && mp[last]==1) return max(fir,last);

        return -1;
    }
};