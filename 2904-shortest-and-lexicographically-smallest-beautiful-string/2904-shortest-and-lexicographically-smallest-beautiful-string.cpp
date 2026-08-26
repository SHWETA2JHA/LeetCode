class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int i = 0, j = 0, n = s.size(), cnt = 0;
        string res = "", curr = "";

        while (j < n) {

            if (s[j] == '1')
                cnt++;

            while (cnt > k) {
                if (s[i] == '1')
                    cnt--;

                i++;
            }

            if (cnt == k) {

                while (s[i] == '0')
                    i++;

                curr = s.substr(i, j - i + 1);

                if (res == "") {
                    res = curr;
                }
                else if (curr.size() < res.size()) {
                    res = curr;
                }
                else if (curr.size() == res.size()) {
                    res = min(res, curr);
                }
            }

            j++;
        }

        return res;
    }
};