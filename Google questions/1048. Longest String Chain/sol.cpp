Given a list of words, each word consists of English lowercase letters.

Let's say word1 is a predecessor of word2 if and only if we can add exactly one letter anywhere in word1 to make it equal to word2.  For example, "abc" is a predecessor of "abac".

A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >= 1, where word_1 is a predecessor of word_2, word_2 is a predecessor of word_3, and so on.

Return the longest possible length of a word chain with words chosen from the given list of words.

 

Example 1:

Input: ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: one of the longest word chain is "a","ba","bda","bdca".
 

Note:

1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] only consists of English lowercase letters.

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        // unordered_map< string, int > hash;
        int n = words.size();
        string str = "";
        if (!n) return 0;
        sort(words.begin(), words.end(), compareInterval); 
        
        int res = 1;
        vector< int > dp(n,1);
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(pred(words[j], words[i])) 
                    dp[i] = max(dp[i],dp[j]+1);
            }
            res = max(res,dp[i]);
        }
        return res;
        
//         int n = words.size();
//         if (!n) return 0;
        
//         //sort first
//         sort(words.begin(), words.end(), 
//              [](const string& a, const string& b) {
//                  return a.size() < b.size();
//              });
        
//         // start dp
//         int res = 1;
//         vector<int> dp(n, 1);
        
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < i; ++j) {
//                 if (pred(words[j], words[i])) {
//                     dp[i] = max(dp[i], dp[j]+1);
//                 }
//             }
//             res = max(res, dp[i]);
//         }
        
//         return res;
    }
    static bool compareInterval(string i1, string i2) { 
        return (i1.length() < i2.length()); 
    }
    
    bool pred(string &a, string &b) {
        // int count = 0;
        // int i = 0;
        // int j = 0;
        // while (i < word1.length() && j < word2.length()) {
        //     if (word1[i] == word2[j]) {
        //         ++i;
        //     }
        //     ++j;
        //     if (j-i >= 2) {
        //         return false;
        //     }
        // }
        // return true;
        int b_size = b.size(), a_size = a.size();
        if (b_size - a_size != 1) return false;
        for (int i = 0; i < b_size; ++i) {
            string sub = b.substr(0, i) + b.substr(i+1, b_size-i-1);
            if (sub == a) return true;
        }
        return false;
    }
};