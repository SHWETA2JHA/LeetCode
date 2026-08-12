class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i = 0, ans = 0, n = nums.size();
        unordered_map<int, int> mp;
        for (int j = 0; j < n; j++) {
            mp[nums[j]]++;
            while (mp[nums[j]] > k) {
                mp[nums[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};