Given a string, find the first non-repeating character in it and return its index. If it doesnt exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode"
return 2.

class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        int count[26] = {0};
        for(int i=0;i<n;i++) {
            int index = s[i] - 'a';
            count[index]++;
        }
        
        for(int i=0;i<n;i++) {
            int index = s[i] - 'a';
            if(count[index] == 1)
                return i;
        }
        return -1;
        
    }
    
};