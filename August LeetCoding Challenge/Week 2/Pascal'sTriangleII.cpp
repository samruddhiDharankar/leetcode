Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v;
        int k = rowIndex, i, j=0;
        v.push_back(1);
        int temp = 0, x;
        for(i=0;i<k;i++) {
            temp = v[0];
            for(j=1;j<v.size();j++) {
                x = v[j];
                v[j] = temp + v[j];
                temp = x;
            }
            // temp = v[j];
            v.push_back(1);
        }
        return v;
    }
};