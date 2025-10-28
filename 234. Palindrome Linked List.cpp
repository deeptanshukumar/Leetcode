/*
234. Palindrome Linked List
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?*/

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

#include <iostream> 
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
};
class Solution {
public:
    ListNode* reverseLL(ListNode* head){
        ListNode* prev=NULL, *curr=head, *forward;
        while(curr!=NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL&&fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newhead = reverseLL(slow);
        ListNode* temp = newhead;
        slow = head;
        while(newhead!=NULL){
            if(newhead->val!=slow->val) return false;
            newhead=newhead->next;
            slow = slow->next;
        }
        reverseLL(newhead);
        return true;
    }
};