Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.


class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        unordered_map<char,int> hash;
        
        for(int i=0;i<n;i++) {
            hash[s[i]]++;
        }
        int total = 0, max = 0;
        for(auto i : hash) {
            if(i.second % 2 == 0) {
                total += i.second;
                cout<<i.first<<"\t"<<i.second<<"\t"<<total<<"\n";
            }
            else {
                if(i.second > max)
                    max = i.second;
            }
        }
        
        total += max;
        bool flag = 0;
        for(auto i : hash) {
            if(i.second % 2 != 0) {
                if((i.second-1) != 0) {
                    flag = 1;
                    total += i.second - 1;
                }
            }
        }
        if(flag == 1)
            total = total - (max-1);
        return total;
    }
};