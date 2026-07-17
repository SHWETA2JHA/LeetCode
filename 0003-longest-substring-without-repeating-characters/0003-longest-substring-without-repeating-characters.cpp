class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int i=0, j=0, n=s.size();
        unordered_map<char, int>mp;
        while(j<n){
            char c=s[j];
            if(mp.find(c)!=mp.end()){
                
                int pos=mp[c];
                i=max(pos+1,i);
                mp[c]=j;
            }
            else{
                mp[c]=j;
            }
            ans=max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};