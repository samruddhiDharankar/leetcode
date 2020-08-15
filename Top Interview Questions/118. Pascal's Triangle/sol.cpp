Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > v;
        vector<int> row;
        int temp, add=0;
        if(numRows == 0) {
            // row.push_back(NULL);
            // v.push_back(row);
            return v;
        }
        else {
        row.push_back(1);
        v.push_back(row);
        // cout<<v[0][0]<<"\n";
        
        for(int i=1;i<numRows;i++) {
            temp = row[0];
            for(int j=1;j<i;j++) {
                // cout<<row[j]<<"\n";
                int x = row[j];
                row[j] += temp;
                temp = x;
            }
            row.push_back(1);
            v.push_back(row);
        }  
        }
        return v;
    }
};