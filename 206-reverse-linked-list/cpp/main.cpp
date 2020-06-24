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
  ListNode* reverseList(ListNode* head) {
    if (head == NULL || head->next == NULL) {
      return head;
    }
    auto a = head;
    auto b = head->next;
    auto c = head->next->next;
    a->next = NULL;

    while (b != NULL) {
      b->next = a;
      a = b;
      b = c;
      if (c != NULL) {
        c = c->next;
      }
    }
    return a;
  }
};