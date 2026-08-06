class Solution {
public:
    bool check(int n, int t) {
        int prod = 1;

        while (n) {
            prod *= (n % 10);

            if (prod % t == 0)
                return true;

            n /= 10;
        }

        return prod % t == 0;
    }

    int smallestNumber(int n, int t) {
        while (!check(n, t))
            n++;
        return n;
    }
};