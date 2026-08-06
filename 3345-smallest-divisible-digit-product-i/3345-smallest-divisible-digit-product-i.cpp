class Solution {
public:
    int pr(int n) {
        int p = 1;
        while (n) {
            p = p * (n % 10);
            n /= 10;
        }
        return p;
    }
    int smallestNumber(int n, int t) {

        while (true) {
            int prod = pr(n);
            if (prod % t == 0)
                return n;
            n++;
        }

        return -1;
    }
};