/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* d = new ListNode();
    ListNode* i = d;

    while (l1 != NULL || l2 != NULL) {
      int v1 = l1 == NULL ? INT_MAX : l1->val;
      int v2 = l2 == NULL ? INT_MAX : l2->val;

      if (v1 < v2) {
        i->next = l1;
        l1 = l1->next;
      } else {
        i->next = l2;
        l2 = l2->next;
      }
      i = i->next;
    }
    return d->next;
  }
};
