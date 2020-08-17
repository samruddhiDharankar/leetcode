/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?

*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector< int > v;
        TreeNode *curr, *temp;
        curr = root;
        temp = root;
        stack < TreeNode* > s;
        
        // while(true) {
        //     while(temp) {
        //         s.push(temp);
        //         temp = temp->left;
        //     }
        //     if(s.empty()) break;
        //     temp = s.top();
        //     s.pop();
        //     v.push_back(temp->val);
        //     temp = temp->right;
        // }
        
        while(curr != NULL || !s.empty()) {
            while(curr != NULL) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            cout<<curr->val<<"\n";
            v.push_back(curr->val);
            s.pop();
            curr = curr->right;
        }
        
    
        // inorder(root, v);
        
        return v;
    }
    
//     void inorder(TreeNode *root, vector< int > &v) {
//         if(root == NULL)
//             return;
        
//         inorder(root->left, v);
//         v.push_back(root->val);
//         inorder(root->right, v);
//     }
    
};