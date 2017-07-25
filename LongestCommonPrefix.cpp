class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        if (0 == strs.size())
        {
            return result;
        }
        
        pair<string::iterator, string::iterator> myPair;
        result = strs[0];
        for (vector<string>::iterator iter = strs.begin() + 1; iter != strs.end(); ++iter)
        {
            myPair = mismatch((*iter).begin(), iter->end(), result.begin());
            if (result.end() != myPair.second)
            {
                result.assign(result.begin(), myPair.second);
            }
        }
        return result;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;
        for (int i = 0; 0 < strs.size(); prefix += strs[0][i], ++i)  //计算prefix中的索引为i的字符
        {
            for (int j = 0; j < strs.size(); ++j)  //遍历容器中存储的每个string
            {
                if (i >= strs[j].size() || (j > 0 && strs[j][i] != strs[j - 1][i]))
                {
                    return prefix;
                }
            }
        }
        return prefix;
    }
};