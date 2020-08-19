Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector< int > v;
        unordered_map< int, int > hash;
        
        int i=0, n = nums.size();
  
        for(i=0;i<n;i++) {
            int k = target - nums[i];
            if(hash.find(k) != hash.end()) {
                v.push_back(i);
                v.push_back(hash[k]);
                break;
     
            }
            hash[nums[i]] = i;

            // cout<<i<<" "<<nums[i]<<"\n";
            
        }
        
        
        return v;
    }
};