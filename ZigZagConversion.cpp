/*
 * ��Ŀ��ZigZag Conversion
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
 * ���ӣ�https://leetcode.com/problems/zigzag-conversion/description/
 *
 */
 
/*
 * �ⷨһ��36ms
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
 * �ⷨ����13ms
 * 0                  2m                 4m                  6m
 *   1             2m-1  2m+1         4m-1 4m+1            6m-1
 *     2        2m-2       2m+2     4m-2     4m+2        6m-2
 *       .   .               .    .                .    .
 *         m                   3m                    5m
 *
 * ����ͼ����Z����ͼ�����ֹ��ɡ����Կ�������1�к͵�m��deltaΪ2m����2�е���m-1�У�ÿ����2��ֵ���Ҹ�����ֵ�����Ķ�ӦֵdeltaҲΪ2m����ʵ֤����
 * ���㷨���յ�����Ч�����Ժ����㷨һ��
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