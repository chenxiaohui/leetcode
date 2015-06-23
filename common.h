#include <iostream>
#include <iterator>
#include <algorithm>
#include <stack>
#include <string>
#include <gtest/gtest.h>

using namespace std;

#define n(A) sizeof(A)/sizeof(int)

template <typename T>
bool equal(const vector<T>& A, const vector<T>& B) {
  bool ret = false;
  if (A.size() == B.size()) {
    size_t na = A.size();
    size_t i = 0;
    while (i < na && A[i] == B[i]) {
      i++;
    }
    if (i == na) {
      ret = true;
    }
  }
  return ret;
}

template <typename T>
bool equal(const T* A, int na, const T* B, int nb) {
  bool ret = false;
  if (na == nb) {
    int i = 0;
    while (i < na && A[i] == B[i]) {
      i++;
    }
    if (i == na) {
      ret = true;
    }
  }
  return ret;
}
template<typename T>
void print(const vector<T>& ve){
   cout << "[";
   copy(ve.begin(), ve.end(), ostream_iterator<T>(cout, ","));
   cout <<"]" <<endl;
}

template<typename T>
void print(const T *ar, int n){
   cout << "[";
   copy(ar, ar + n, ostream_iterator<T>(cout, ","));
   cout <<"]" <<endl;
}

typedef struct _LinkNode {
  int val;
  struct _LinkNode * next;
} LinkNode, * LinkList;

LinkList createLinkList(int a[], int n) {
  LinkList ret = NULL;
  LinkList p = NULL;
  LinkList r = NULL;
  if (n > 0) {
    for (int i = 0; i < n; i++) {
      p = (LinkList)malloc(sizeof(LinkNode));
      p->next = NULL;
      p->val = a[i];
      if (ret == NULL) {
        ret = p;
      } else {
        r->next = p;
      }
      r = p;
    }
  }
  return ret;
}

void print(LinkList list) {
  LinkList p = list;
  while (p != NULL) {
    cout << p->val;
    if (p->next != NULL) {
      cout << "->";
    }
    p = p->next;
  }
  cout << endl;
}

bool equal(LinkList lista, LinkList listb) {
  while (lista != NULL && listb != NULL && lista->val == listb->val) {
    lista = lista->next;
    listb = listb->next;
  }
  return lista == listb;
}

void destroy(LinkList list) {
  LinkList p = NULL;
  while (list != NULL) {
    p = list;
    list  = list->next;
    free(p);
  }
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

