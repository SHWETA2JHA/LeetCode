class Solution {
private:
    bool compatible(unordered_map<char,int>&mp, int k){
        int maxi=INT_MIN, cnt=0;
        for(auto i: mp){
            maxi=max(maxi, i.second);
            cnt+=i.second;
        }
        cnt-=maxi;
        if(cnt<=k)return true;
        return false;
    }
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int>mp;

        int i=0, j=0, n=s.size(), maxlen=0;

        while(j<n){
            char c=s[j];
            mp[c]++;

            if(compatible(mp, k)){
                maxlen=max(maxlen, j-i+1);
            }
            else{
                while(!compatible(mp, k)){
                    mp[s[i]]--;
                    if(mp[s[i]]==0)mp.erase(s[i]);
                    i++;
                }
            }
            j++;
        }

        return maxlen;
    }
};