class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int>mp;
        for(auto i: nums)mp.insert(i);
        int f=k;
        int t=200;
        while(t--){
            if(mp.find(f)==mp.end())return f;
            f+=k;
        }
        return -1;
    }
};