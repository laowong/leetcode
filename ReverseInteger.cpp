class Solution {
public:
    int reverse(int x) {
        long result = 0;
        if (INT_MAX == x || INT_MIN == x)
        {
            return 0;
        }
        if (0 > x)
        {
            return -reverse(-x);
        }
        int mod = 0;
        while(0 != x)
        {
            mod = x % 10;
            x = x / 10;
            result = 10 * result + mod;
        }
        if (INT_MAX < result || INT_MIN > result)
        {
            result = 0;
        }
        return result;
    }
};