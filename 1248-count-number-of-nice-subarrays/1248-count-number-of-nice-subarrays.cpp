class Solution {
private:
    int solve(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;
        int l = 0, r = 0, n = nums.size(), ans = 0, sum = 0;

        while (r < n) {
            sum += nums[r];
            while (sum > goal) {
                sum -= nums[l++];
            }
            ans += (r - l + 1);
            r++;
        }
        return ans;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> v;
        for (auto i : nums) {
            if (i % 2 == 0)
                v.push_back(0);
            else
                v.push_back(1);
        }

        return solve(v, k) - solve(v, k - 1);
    }
};