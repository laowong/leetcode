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