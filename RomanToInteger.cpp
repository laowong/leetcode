/*
 * 题目：Roman to Integer
 * Given a roman numeral, convert it to an integer.
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 * 链接：https://leetcode.com/problems/roman-to-integer/description/
 * 
 * 什么是罗马数字？
 * 罗马数字（roman numeral）计数方法：
 * |---|---|----|----|-----|-----|------|
 * | I | V | X  | L  |  C  |  D  |  M   |
 * |---|---|----|----|-----|-----|------|
 * | 1 | 5 | 10 | 50 | 100 | 500 | 1000 |
 * |---|---|----|----|-----|-----|------|
 * 1. 相同的数字连写、所表示的数等于这些数字相加得到的数、如：Ⅲ=3；
 * 2. 小的数字在大的数字的右边、所表示的数等于这些数字相加得到的数、 如：Ⅷ=8、Ⅻ=12；
 * 3. 小的数字（限于 I、X 和 C）在大的数字的左边、所表示的数等于大数减小数得到的数、如：Ⅳ=4、Ⅸ=9；
 * 4. 正常使用时、连写的数字重复不得超过三次；
 * 5. 在一个数的上面画一条横线、表示这个数扩大 1000 倍。
 *
 */
class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        map<char, int> hash;
        hash['I'] = 1;
        hash['V'] = 5;
        hash['X'] = 10;
        hash['L'] = 50;
        hash['C'] = 100;
        hash['D'] = 500;
        hash['M'] = 1000;
        
        int preValue = 0;
        for (string::size_type pos = 0; pos != s.size(); ++pos)
        {
            int curValue = hash[s[pos]];
            if (curValue > preValue)
            {
                result = result + curValue - 2 * preValue;
            }
            else
            {
                result += curValue;
            }
            preValue = curValue;
        }
        return result;
    }
};