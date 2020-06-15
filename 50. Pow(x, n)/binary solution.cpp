class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        int cp;
        if(n==INT_MIN)
            cp = -(n+1);
        else
            cp = n>=0? n : -n;
        double mid = x;
        for(int i=0; i<sizeof(n)*8; ++i){
            if(cp&1)
                res *= mid;
            mid = mid*mid;
            cp = cp >> 1;
        }
        if(n==INT_MIN)
            res *= x;
        return n>=0? res : 1/res;
    }
};
