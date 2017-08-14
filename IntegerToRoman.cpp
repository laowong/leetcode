/*
 * 题目：Integer to Roman
 * Given an integer, convert it to a roman numeral.
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 * 链接：https://leetcode.com/problems/integer-to-roman/description/
 *
 */


/*
 * 解法一：
 * Ⅰ－1、Ⅱ－2、Ⅲ－3、Ⅳ－4、Ⅴ－5、Ⅵ－6、Ⅶ－7、Ⅷ－8、Ⅸ－9
 * 根据1～9的规律进行类推，其余量级的数不过是换了字母表示而已
 */
class Solution {
public:
    string intToRoman(int num) {
        string result;
        map<int, char> hash;
        hash[1] = 'I';
        hash[5] = 'V';
        hash[10] = 'X';
        hash[50] = 'L';
        hash[100] = 'C';
        hash[500] = 'D';
        hash[1000] = 'M';
        
        int order = 1000;
        int value = 0;
        
        while(0 != num)
        {
            value = num / order;
            num = num % order;
            if (0 < value && value < 4)
            {
                result.append(value, hash[order]);
            }
            else if (4 == value)
            {
                result.push_back(hash[order]);
                result.push_back(hash[5 * order]);
            }
            else if (4 < value && value < 9)
            {
                result.push_back(hash[5 * order]);
                result.append(value - 5, hash[order]);
            }
            else if (9 == value)
            {
                result.push_back(hash[order]);
                result.push_back(hash[10 * order]);
            }
            order = order / 10;
        }
        return result;
    }
};

/*
 * 解法二：
 * 预存好各位的数字，直接进行计算
 */
class Solution {
public:
    string intToRoman(int num) {
        string result;
        string THOU[] = {"", "M", "MM", "MMM"};
        string HUND[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string TENS[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string ONES[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        result += THOU[num / 1000];
        result += HUND[(num % 1000) / 100];
        result += TENS[(num % 100) / 10];
        result += ONES[num % 10];
        return result;
    }
};