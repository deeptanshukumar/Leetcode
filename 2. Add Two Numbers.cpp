/*
2. Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.*/

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
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> digits;
        int carry = 0;

        while (l1 != NULL || l2 != NULL) {
            int a = 0;
            int b = 0;

            if (l1 != NULL) {
                a = l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL) {
                b = l2->val;
                l2 = l2->next;
            }

            int sum = a + b + carry;
            digits.push_back(sum % 10);
            carry = sum / 10;
        }

        if (carry > 0) {
            digits.push_back(carry);
        }

        ListNode* head = new ListNode(digits[0]);
        ListNode* current = head;
        for (int i = 1; i < digits.size(); i++) {
            current->next = new ListNode(digits[i]);
            current = current->next;
        }

        return head;
    }
};
