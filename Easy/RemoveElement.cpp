/*
 * 题目：Remove Duplicates from Sorted Array
 * Given an array and a value, remove all instances of that value in place and return the new length.
 *
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 *
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 *
 * Example:
 * Given input array nums = [3,2,2,3], val = 3
 *
 * Your function should return length = 2, with the first two elements of nums being 2.
 *
 * 链接：https://leetcode.com/problems/remove-element/description/
 *
 * 相似题目：Remove Duplicates from Sorted Array
 * 相似题目链接：https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
 */
 
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int valCount = 0, size = nums.size();
        for (int i = 0; i < size; ++i)
        {
            if (val == nums[i])
            {
                ++valCount;
            }
            else
            {
                nums[i - valCount] = nums[i];
            }
        }
        return size - valCount;
    }
};