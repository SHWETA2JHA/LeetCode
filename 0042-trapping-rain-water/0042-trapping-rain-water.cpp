class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>l(n, -1), r(n, -1);

        int maxi=-1;
        for(int i=0; i<n; i++){
            maxi=max(maxi, height[i]);
            r[i]=maxi;
        }
        maxi=-1;
        for(int i=n-1; i>=0; i--){
            maxi=max(maxi, height[i]);
            l[i]=maxi;
        }

        int water=0;

        for(int i=0; i<n; i++){
            water+=min(l[i],r[i])-height[i];
        }
        return water;
    }
};