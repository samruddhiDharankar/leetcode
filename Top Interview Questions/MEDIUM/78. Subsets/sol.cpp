Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector< int > s;
        vector< vector < int > > v;
      
        subsets(nums, 0, s, v);
        return v;
    }
    void subsets(vector<int>& nums, int i, vector< int >& s, vector< vector < int > >& v) {
        v.push_back(s);
        
        for(int j=i;j<nums.size();j++) {
            s.push_back(nums[j]);
            subsets(nums, j+1, s, v);
            s.pop_back();
        }
        
    }
    
};