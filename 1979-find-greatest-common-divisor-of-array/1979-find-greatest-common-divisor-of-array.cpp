class Solution {
private:
    int gcd(int a, int b){
        if(a==0)return b;

        return gcd(b%a, a);
    }
public:
    int findGCD(vector<int>& nums) {
        int maxi=INT_MIN, mini=INT_MAX;

        for(auto n: nums){
            maxi=max(maxi, n);
            mini=min(mini, n);
        }

        return gcd(mini, maxi);
    }
};