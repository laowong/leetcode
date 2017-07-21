class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> hash;
        for (int index = 0; index != nums.size(); ++index)
        {
            if(hash.find(target - nums[index]) != hash.end())
            {
                result.push_back(hash[target - nums[index]]);
                result.push_back(index);
                break;
            }
            hash[nums[index]] = index;
        }
        return result;
    }
};