Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector< vector< int > > v;
        perm(nums, 0, v);
        return v;
    }
    
    void perm(vector<int> &nums,int index, vector< vector< int > > &v) {
        if(index == nums.size()) {
            v.push_back(nums);
        // cout<<nums[0]<<"\t"<<nums[1]<<"\t"<<nums[2]<<"\n";
        }
        else {
            for(int i=index;i<nums.size();i++) {
                swap(&nums[i], &nums[index]);
                // cout<<nums[0]<<"\t"<<nums[1]<<"\t"<<nums[2]<<"\n";
                perm(nums, index+1, v);
                swap(&nums[i], &nums[index]);
            }
        }
    }
    
    void swap(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }  
    
};