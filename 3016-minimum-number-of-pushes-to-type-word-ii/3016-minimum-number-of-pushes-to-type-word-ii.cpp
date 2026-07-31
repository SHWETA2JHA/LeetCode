class Solution {
public:

    static bool cmp(const pair<char, int>& a, const pair<char, int>& b) { 
        return a.second > b.second; 
    }

    int minimumPushes(string word) {
        map<char, int> mp;

        for (int i = 0; i < word.size(); i++) {
            if (mp.find(word[i]) == mp.end()) {
                mp[word[i]] = 1;
            } else {
                mp[word[i]]++;
            }
        }

        vector<pair<char, int>> vec;
        for (auto& it : mp) {
            vec.push_back(it);
        }

        sort(vec.begin(), vec.end(), cmp);  

        vector<int> cnt(26, 0);
        int c = 0;
        for (auto& it : vec) { 
            int ind = it.first - 97;
            c++;
            if (c <= 8) cnt[ind] = 1;
            else if (c > 8 && c <= 16) cnt[ind] = 2;
            else if (c > 16 && c <= 24) cnt[ind] = 3;
            else cnt[ind] = 4;
        } 

        int ans = 0;
        for (int i = 0; i < word.size(); i++) {
            int j = word[i] - 97;
            //cout<<word[i]<<" "<<cnt[j]<<endl;
            ans += cnt[j];
        }
        return ans;
    }
};
