/*
148. Sort List

Given the head of a linked list, return the list after sorting it in ascending order.

 

Example 1:

Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:

Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Example 3:

Input: head = []
Output: []

 

Constraints:

    The number of nodes in the list is in the range [0, 5 * 104].
    -105 <= Node.val <= 105

 

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
*/

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
    ListNode* findmiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    ListNode* merge2lists(ListNode* list1, ListNode* list2) {
        ListNode* dummynode = new ListNode(-1);
        ListNode* temp = dummynode;
        while (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }
        if (list1 != NULL) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }
        return dummynode->next;
    }
    
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* middle = findmiddle(head);
        ListNode* right = middle->next;
        middle->next = NULL;
        ListNode* left = head;
        
        left = sortList(left);
        right = sortList(right);

        return merge2lists(left, right);
    }
};