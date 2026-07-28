class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> v(26, 0);

        for (auto c : s) {
            v[c - 'a']++;
        }

        string s1 = "", s2 = "";
        char ch = '!';

        for (int i = 0; i < 26; i++) {
            int cnt = v[i];
            if (cnt % 2 != 0) {
                ch = 'a' + i;
            }
            cnt /= 2;
            for (int j = 0; j < cnt; j++) {
                s1 += char('a' + i);
                s2 += char('a' + i);
            }
        }

        if (ch != '!') {
            s1 = s1 + ch;
        }
        reverse(s2.begin(), s2.end());

        return s1 + s2;
    }
};