/* �ⷨһ��*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        map<char, string::size_type> hash;
        string::size_type lastPosWhithRepeatChar = 0, pos = 0;
        
        while (pos != s.size())
        {
            if (hash.end() != hash.find(s[pos]))
            {
                if(maxLength < hash.size())
                {
                    maxLength = hash.size();
                }
                pos = hash[s[pos]] + 1;
                hash.clear();
            }
            hash[s[pos]] = pos;
            ++pos;
        }
        
        //�������һ���ַ��Ĳ��ظ����ַ�����δ�ж��Ƿ�Ϊ��󳤶ȣ���Ҫ�ж�һ��
        return maxLength > hash.size() ? maxLength : hash.size();
    }
};

/* �ⷨ����
 * startָ�����ַ�����ʼ��ǰһ���ַ���dist��ʾÿ���ַ����һ�γ��ֵ�λ�ã�ÿһ��
 * ����dist��ĳ�ַ���ǰ���һ�γ���λ��ʱ���鿴ǰһ�γ���λ���Ƿ�λ��start֮��,
 * �ǣ�����ζ���ظ��ַ����֣�ʹstartָ���λ�ã���Ϊstartָ��������ַ�����ʼǰһ
 * ���ַ����� 
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0, start = -1;
        vector<int> dist(256, -1);
        
        for(int pos = 0; pos != s.size(); ++pos)
        {
            if (dist[s[pos]] > start)
            {
                start = dist[s[pos]];
            }
            dist[s[pos]] = pos;
            maxLen = max(maxLen, pos - start);
        }
        
        return maxLen;
    }
};