Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int, int> s_h, t_h;
        for(int i=0;i<s.length();i++) {
            s_h[s[i]]++;
        }
        for(int i=0;i<t.length();i++) {
            t_h[t[i]]++;
        }
        
        if(s_h == t_h)
            return true;
        else
            return false;
        
    }
};