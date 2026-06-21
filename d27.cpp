class Solution {
  public:
    int divide(int a, int b) {
        // code here
        if (a == b) return 1;

        if (a== INT_MIN && b == -1)
            return INT_MAX;

        bool sign = true;

        if ((a< 0 && b > 0) ||
            (a> 0 && b < 0)) {
            sign = false;
        }

        long long n = a;
        long long d = b;

        n = abs(n);
        d = abs(d);

        long long ans = 0;

        while (n >= d) {

            long long temp = d;
            long long multiple = 1;

            while ((temp << 1) <= n) {
                temp <<= 1;
                multiple <<= 1;
            }

            n -= temp;
            ans += multiple;
        }

        if (ans > INT_MAX && sign)
            return INT_MAX;

        if (ans > INT_MAX && !sign)
            return INT_MIN;

        return sign ? ans : -ans;
    }
};
