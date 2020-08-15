Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Example: 

Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

int add = 0;
class Solution {
public:
    bool isHappy(int n) {
        // int visited[INT_MAX] = {0};
        
        unordered_map< int, int > visited;
        
        
        
        if(n == 1 && visited[n] != 1) {
            return true;
        }
        // else if(n != 1 && visited[n]) {
        //     return false;
        // }
        while(visited[n] != 1 && n !=1) {   
            visited[n] = 1;
            int no = square(n);
            // cout<<no<<"\n";
            // cout<<a<<"\t"<<b<<"\n";
            if(no == 1)
                return true;
            else
                n = no;
        }
        return false;
    }
    int square(int n){
        add = 0;
        while( n!= 0) {
            int a = n / 10;
            int b = n % 10;
            n = a;
            add += b*b;
        }
        return add;
    }

};