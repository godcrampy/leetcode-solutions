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
  ListNode* partition(ListNode* head, int x) {
    ListNode* less = new ListNode();
    ListNode* more = new ListNode();
    ListNode* lessI = less;
    ListNode* moreI = more;

    while (head != NULL) {
      if (head->val < x) {
        lessI->next = head;
        lessI = lessI->next;
      } else {
        moreI->next = head;
        moreI = moreI->next;
      }
      head = head->next;
    }

    moreI->next = NULL;
    lessI->next = more->next;
    return less->next;
  }
};
