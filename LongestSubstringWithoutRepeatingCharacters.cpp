/* 解法一：*/
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
        
        //包含最后一个字符的不重复子字符串还未判断是否为最大长度，需要判断一次
        return maxLength > hash.size() ? maxLength : hash.size();
    }
};

/* 解法二：
 * start指向新字符串起始的前一个字符，dist表示每个字符最后一次出现的位置，每一次
 * 更新dist中某字符当前最后一次出现位置时，查看前一次出现位置是否位于start之后,
 * 是，则意味着重复字符出现，使start指向该位置（因为start指向的是新字符串起始前一
 * 个字符）。 
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