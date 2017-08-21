class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int max = 0, temp = 0;
        vector<int>::iterator iter = nums.begin();
        while (iter != nums.end())
        {
            if (iter < nums.begin() + k)
            {
                max = *iter + max;
                temp = max;
            }
            else
            {
                temp = temp + (*iter) - (*(iter - k));
                max = (max > temp ? max : temp);
            }
            ++iter;
        }
        return static_cast<double>(max) / k;
    }
};