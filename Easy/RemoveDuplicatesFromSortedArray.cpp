/*
 * ��Ŀ��Remove Duplicates from Sorted Array
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 *
 * For example,
 * Given input array nums = [1,1,2],
 *
 * Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
 *
 * ���ӣ�https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
 *
 */
 
/*
 * ������Ľⷨ��(29ms)
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (0 == size || 1 == size)
        {
            return size;
        }
        int newLength = 1, preValue = nums[0], pos = 1;
        for (int i = 1; i < size; ++i)
        {
            if (preValue != nums[i])
            {
                preValue = nums[i];
                nums[pos++] = nums[i];
                ++newLength;
            }
        }
        return newLength;
    }
};

/*
 * �Ż���Ľⷨ��(25ms)
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (0 == size || 1 == size)
        {
            return size;
        }
        int dupCount = 0;
        for (int i = 1; i < size; ++i)
        {
            if (nums[i] == nums[i - 1])
            {
                ++dupCount;
            }
            else
            {
                nums[i - dupCount] = nums[i];
            }
        }
        return size - dupCount;
    }
};