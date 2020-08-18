Return all non-negative integers of length N such that the absolute difference between every two consecutive digits is K.

Note that every number in the answer must not have leading zeros except for the number 0 itself. For example, 01 has one leading zero and is invalid, but 0 is valid.

You may return the answer in any order.

 

Example 1:

Input: N = 3, K = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
Example 2:

Input: N = 2, K = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
 

Note:

1 <= N <= 9
0 <= K <= 9

class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector< int > v;
        
        queue< int > q;
        
        for(int i=1;i<10;i++) {
            q.push(i);
        }
        
        for(int i=1;i<N;i++) {
            int size = q.size();
            for(int j=0;j<size;j++) {
                int unit = q.front();
                q.pop();
                int num = unit % 10;
                
                if(num + K < 10) {
                    q.push(unit*10 + num+K);
                }
                if(num - K >= 0 && K != 0) {
                    q.push(unit*10 + num-K);
                }
            }
        }
        if(N == 1) {
            v.push_back(0);
        }
        while(!q.empty()) {
            v.push_back(q.front());
            q.pop();
        }
        return v;
    }
    // at the 1st level: [1, 2, 3, 4, 5, 7, 8, 9]
    // at the 2nd level: [18, 29, 70, 81, 92]
    // at the 3rd level: [181, 292, 707, 818, 929]
};