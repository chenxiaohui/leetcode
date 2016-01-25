/*
 *  reverse a link list using differenct method
 */
#include "common.h"

class Solution {
public:
  void reverse(LinkList & list) {
    LinkList p = list;
    LinkList q = NULL;
    LinkList r = NULL;
    while (p != NULL) {
      r = q;
      q = p;
      p = p->next;
      q->next = r;
    }
    list = q;
  }
  void reverse2(LinkList & list) {
    LinkList p = list;
    LinkList r = NULL;
    LinkList ret = NULL;
    while (p != NULL) {
      r = p;
      p = p->next;
      r->next = ret;
      ret = r;
    }
    list = ret;
  }
};

Solution s;
TEST(reverseLinkList, normal) {
  int a[] = {1, 2, 3, 4};
  LinkList list = createLinkList(a, n(a));
  s.reverse(list);
  int b[] = {4, 3, 2, 1};
  LinkList list_pre = createLinkList(b, n(b));
  EXPECT_TRUE(equal(list, list_pre));
  destroy(list);
  destroy(list_pre);
}

TEST(reverseLinkList, single) {
  int a[] = {1};
  LinkList list = createLinkList(a, n(a));
  s.reverse(list);
  LinkList list_pre = createLinkList(a, n(a));
  EXPECT_TRUE(equal(list, list_pre));
  destroy(list);
  destroy(list_pre);
}

