/*
 * ��Ŀ��Roman to Integer
 * Given a roman numeral, convert it to an integer.
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 * ���ӣ�https://leetcode.com/problems/roman-to-integer/description/
 * 
 * ʲô���������֣�
 * �������֣�roman numeral������������
 * |---|---|----|----|-----|-----|------|
 * | I | V | X  | L  |  C  |  D  |  M   |
 * |---|---|----|----|-----|-----|------|
 * | 1 | 5 | 10 | 50 | 100 | 500 | 1000 |
 * |---|---|----|----|-----|-----|------|
 * 1. ��ͬ��������д������ʾ����������Щ������ӵõ��������磺��=3��
 * 2. С�������ڴ�����ֵ��ұߡ�����ʾ����������Щ������ӵõ������� �磺��=8����=12��
 * 3. С�����֣����� I��X �� C���ڴ�����ֵ���ߡ�����ʾ�������ڴ�����С���õ��������磺��=4����=9��
 * 4. ����ʹ��ʱ����д�������ظ����ó������Σ�
 * 5. ��һ���������滭һ�����ߡ���ʾ��������� 1000 ����
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