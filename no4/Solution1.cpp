class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp;
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] < nums2[j]) {
                temp.push_back(nums1[i]);
                i++;
            } else {
                temp.push_back(nums2[j]);
                j++;
            }
        }
        while(i < nums1.size()) {
            temp.push_back(nums1[i]);
            i++;
        }
        while(j < nums2.size()) {
            temp.push_back(nums2[j]);
            j++;
        }
        int len = temp.size();
        return (len % 2 == 0) ? (temp[len/2] + temp[len / 2 - 1]) / 2.0 : temp[len / 2] * 1.0;
    }
};
