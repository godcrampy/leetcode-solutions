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
  bool isPalindrome(ListNode* head) {
    if (head == NULL || head->next == NULL) {
      return true;
    }
    auto slow = head;
    auto fast = head->next;

    while (fast != NULL && fast->next != NULL) {
      fast = fast->next->next;
      slow = slow->next;
    }

    if (fast == NULL) {
      auto temp = head;
      while (temp->next != slow) {
        temp = temp->next;
      }
      temp->next = NULL;
    }
    auto head2 = reverseList(slow->next);
    slow->next = NULL;

    while (head != NULL || head != NULL) {
      if (head == NULL || head2 == NULL) {
        return false;
      }
      if (head->val != head2->val) {
        return false;
      }
      head = head->next;
      head2 = head2->next;
    }

    return head == NULL && head2 == NULL;
  }

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