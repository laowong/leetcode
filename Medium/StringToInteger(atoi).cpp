class Solution {
public:
    int myAtoi(string str) {
        int pos = 0;
        int sign = 1;
        long long result = 0;
        while (pos < str.size() && ' ' == str[pos]) ++pos; //去除whitespace
        if (pos < str.size() && ('-' == str[pos] || '+' == str[pos]))
        {
            '-' == str[pos] ? sign = -1 : sign = 1;
            ++pos;
        }
        
        while ((pos < str.size()) && ('0' <= str[pos]) && (str[pos] <= '9'))
        {
            result = 10 * result + str[pos] - '0';
            if (sign * result >= INT_MAX) return INT_MAX;
            if (sign * result <= INT_MIN) return INT_MIN;
            ++pos;
        }
        
        return sign * result;
    }
};