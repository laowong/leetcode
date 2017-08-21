class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;
        map<char, char> myMap;
        myMap['('] = ')';
        myMap['{'] = '}';
        myMap['['] = ']';
        for (string::iterator iter = s.begin(); iter != s.end(); ++iter)
        {
            if (myMap.end() != myMap.find(*iter))
            {
                myStack.push(*iter);
            }
            else
            {
                if (myStack.empty())
                {
                    return false;
                }
                else if (*iter != myMap[myStack.top()])
                {
                    return false;
                }
                else
                {
                    myStack.pop();
                }
            }
        }
        return myStack.empty();
    }
};