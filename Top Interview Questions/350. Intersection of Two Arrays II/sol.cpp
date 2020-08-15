Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//         int n1 = nums1.size();
//         int n2 = nums2.size();
//         vector<int> v;
// //         set<int> hs;
// //         for(int i=0;i<n1;i++) {
// //             hs.insert(nums1[i]);
// //         }
        
// //         for(int i=0;i<n2;i++) {
// //             if(hs.find(nums2[i]) != hs.end()) {
// //                 v.push_back(nums2[i]);
// //             }
// //         }
// //         return v;
//         int i=0,j=0;
//         while(i<n1 && j<n2) {
//             if(nums1[i] > nums2[j]) {
//                 j++;
//             }
//             else if(nums1[i] < nums2[j]) {
//                 i++;
//             }
//             else {
//                 v.push_back(nums1[i]);
//                 i++;
//                 j++;
//             }
//         }
        
//         while(i < n1) {
            
//         }
//         return v;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1 = (int)nums1.size(), n2 = (int)nums2.size();
        int i1 = 0, i2 = 0;
        vector<int> res;
        while(i1 < n1 && i2 < n2){
            if(nums1[i1] == nums2[i2]) {
                res.push_back(nums1[i1]);
                i1++;
                i2++;
            }
            else if(nums1[i1] > nums2[i2]){
                i2++;
            }
            else{
                i1++;
            }
        }
        return res;
    }
};