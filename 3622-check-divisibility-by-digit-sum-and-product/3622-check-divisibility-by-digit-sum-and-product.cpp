class Solution {
public:
    bool checkDivisibility(int n) {
        int num=n, sum=0, mul=1;

        while(num){
            int r=num%10;
            num/=10;
            sum+=r;
            mul*=r;
        }

        return n%(sum+mul)==0;
    }
};