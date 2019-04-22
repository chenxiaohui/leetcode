/*
   You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

#include "common.h"

class Solution {
  public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode *lr1 = reverse(l1);
      ListNode *lr2 = reverse(l2);
      ListNode *l3 = NULL, *p = NULL, *q = NULL;
      int carry = 0;
      while (lr1 != NULL && lr2 != NULL) {
        carry += lr1 ->val+ lr2->val;
        p = new ListNode(carry % 10);
        if (l3 == NULL) {
          l3 = p;
        } else {
          q->next = p;
        }
        q = p;
        carry /= 10;
        lr1 = lr1->next;
        lr2 = lr2->next;
      }
      while (lr1 != NULL) {
        p = new ListNode(lr1->val);
        q->next = p;
        q = p;
        lr1 = lr1->next;
      }
      while (lr2 != NULL) {
        p = new ListNode(lr2->val);
        q->next = p;
        q = p;
        lr2 = lr2->next;
      }
      return reverse(l3);
    }

    ListNode* reverse(ListNode* l1) {
      ListNode *p = l1;
      ListNode *q = NULL;
      ListNode *r = NULL;
      while(p != NULL) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
      }
      return q;
    }
};
Solution s;

TEST(AddTwoNumbers, normal) {
  {
    int a1[]  = {1,2,3};
    int b1[]  = {4,5,4};
    int c1[]  = {5,7,7};

    LinkList a = createLinkList(a1, 3);
    LinkList b = createLinkList(b1, 3);
    LinkList c = s.addTwoNumbers(a, b);
    LinkList c_res = createLinkList(c1, 3);

    ASSERT_TRUE(equal(c, c_res));
  }
}
