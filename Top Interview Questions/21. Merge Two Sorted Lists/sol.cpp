Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head1, *head2, *head3, *temp;
        head1 = l1, head2 = l2;
        head3 = new ListNode(-1);
        temp = head3;
        
        while(head1 && head2) {
            if(head1->val <= head2->val) {
                head3->next = new ListNode(head1->val);
                head3 = head3->next;
                head1 = head1->next;
            }
            else {
                head3->next = new ListNode(head2->val);
                head3 = head3->next;
                head2 = head2->next;
            }
        }
        
        while(head1) {
            head3->next = new ListNode(head1->val);
            head3 = head3->next;
            head1 = head1->next;
        }
        while(head2) {
            head3->next = new ListNode(head2->val);
            head3 = head3->next;
            head2 = head2->next;
        }
        return temp->next;
    }
};