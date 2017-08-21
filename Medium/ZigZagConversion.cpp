/*
 * 题目：ZigZag Conversion
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display
 * this pattern in a fixed font for better legibility)
 * P       A       H       N
 *   A   P   L   S   I   I   G
 *     Y       I       R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
 * string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 *
 * 链接：https://leetcode.com/problems/zigzag-conversion/description/
 *
 */
 
/*
 * 解法一：36ms
 */
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1)
        {
            return s;
        }
        string *str = new string[numRows];
        int step = 0, row = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (row == 0)
            {
                step = 1;
            }
            else if(row == numRows - 1)
            {
                step = -1;
            }
            str[row].push_back(s[i]);
            row += step;
        }
        string result;
        for (int i = 0; i < numRows; ++i)
        {
            result += str[i];
        }
        delete[] str;
        return result;
    }
};

/*
 * 解法二：13ms
 * 0                  2m                 4m                  6m
 *   1             2m-1  2m+1         4m-1 4m+1            6m-1
 *     2        2m-2       2m+2     4m-2     4m+2        6m-2
 *       .   .               .    .                .    .
 *         m                   3m                    5m
 *
 * 如上图，是Z字形图的数字规律。可以看出，第1行和第m行delta为2m，第2行到第m-1行，每次有2个值，且该两个值与后面的对应值delta也为2m。事实证明：
 * 该算法最终的运行效率明显好于算法一。
 */
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1)
        {
            return s;
        }
        string result;
        int delta = 2 * (numRows - 1);
        int first = 0, second = 0;
        for (int i = 0; i < numRows; ++i)
        {
            first = i;
            second = delta - i; 
            while (first < s.size())
            {
                result.push_back(s[first]);
                first += delta;
                if ((0 != i) && ((numRows - 1) != i) && (second < s.size()))
                {
                    result.push_back(s[second]);
                    second += delta;
                }
            }
        }
        return result;
    }
};