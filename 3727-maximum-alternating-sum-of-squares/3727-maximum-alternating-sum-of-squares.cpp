class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int>v(nums.begin(),nums.end());

        for(int i=0; i<v.size(); i++){
            if(v[i]<0)v[i]*=-1;
        }

        sort(v.begin(),v.end());

        int k=v.size()/2;
        long long s1=0,s2=0;
        for(int i=0;i<v.size(); i++){
            if(i<k)s1=s1 + (long long)(v[i]*v[i]);
            else s2 = s2 + (long long)(v[i]*v[i]);
        }

        return s2-s1;
    }
};