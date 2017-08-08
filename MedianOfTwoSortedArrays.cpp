class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result = 0;
        vector<int>::size_type pos1 = 0, pos2 = 0, pos = 0, totleSize = nums1.size() + nums2.size();
        bool isOdd = totleSize % 2;
        double first = 0, second = 0;
        
        if (0 == totleSize)
        {
            return 0;
        }
        
        if (0 == nums1.size() || 0 == nums2.size())
        {
            first = second = (0 != nums1.size() ? nums1[0] : nums2[0]);
        }
        else
        {
            second = (nums1[0] < nums2[0] ? nums1[0] : nums2[0]);
        }
        
        //考虑将两个数组合起来成为一个排好序的数组，pos指将要获取的位置的数
        while (pos <= totleSize / 2)
        {
            first = second;
            if (pos1 != nums1.size() && pos2 != nums2.size())
            {
                second = nums1[pos1] < nums2[pos2] ? nums1[pos1++] : nums2[pos2++];
            }
            else if (pos1 != nums1.size())
            {
                second = nums1[pos1++];
            }
            else
            {
                second = nums2[pos2++];
            }
            ++pos;
        }
        
        return isOdd ? second : (first + second) / 2;
    }
};