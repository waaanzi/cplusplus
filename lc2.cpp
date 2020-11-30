/*
leetcode2. 两数相加
给出两个非空的链表用来表示两个非负的整数。其中，它们各自的位数是按照逆序
的方式存储的，并且它们的每个节点只能存储一位数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/

struct ListNode {
  int val;
  struct ListNode* next;
};

#include <malloc.h>
#include <stddef.h>
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  struct ListNode* head = NULL;
  struct ListNode* tail = NULL;
  int carry = 0;  // 进位
  while ((NULL != l1) || (NULL != l2) || carry) {
    int num1 = (NULL == l1) ? 0 : l1->val;
    int num2 = (NULL == l2) ? 0 : l2->val;

    if (NULL == head) {
      head = (struct ListNode*)malloc(sizeof(struct ListNode));
      tail = head;
    } else {
      tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
      tail = tail->next;
    }
    tail->val = (num1 + num2 + carry) % 10;
    carry = (num1 + num2 + carry) / 10;

    if (NULL != l1) {
      l1 = l1->next;
    }
    if (NULL != l2) {
      l2 = l2->next;
    }
  }

  tail->next = NULL;

  return head;
}

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = NULL;
    ListNode* tail = NULL;
    int carry = 0;  // 进位
    while ((nullptr != l1) || (nullptr != l2) || carry) {
      int num1 = (nullptr == l1) ? 0 : l1->val;
      int num2 = (nullptr == l2) ? 0 : l2->val;

      if (NULL == head) {
        head = new ListNode;
        tail = head;
      } else {
        tail->next = new ListNode;
        tail = tail->next;
      }
      tail->val = (num1 + num2 + carry) % 10;
      carry = (num1 + num2 + carry) / 10;

      if (nullptr != l1) {
        l1 = l1->next;
      }
      if (nullptr != l2) {
        l2 = l2->next;
      }
    }

    tail->next = nullptr;

    return head;
  }
};


// C++
#include <iostream>
#include <vector>
using namespace std;

// 创建链表
ListNode* create(vector<int> vc) {
  ListNode* head = nullptr;
  ListNode* tail = nullptr;
  auto it = vc.begin();
  while (it != vc.end()) {
    ListNode* temp = new ListNode();
    temp->val = *it;
    temp->next = nullptr;

    if (nullptr == tail) {
      head = temp;
      tail = temp;
    } else {
      tail->next = temp;
      tail = tail->next;
    }
    ++it;
  }
  return head;
}

// 释放链表
void del(ListNode* head) {
  while (head) {
    auto temp = head->next;
    delete head;
    head = temp;
  }
}

// 打印链表
void print(ListNode* head) {
  while (head) {
    cout << head->val;
    head = head->next;
  }
  cout << endl;
}

int main() {
  vector<int> vc1 = {2,4,3};
  auto l1 = create(vc1);
  print(l1);

  vector<int> vc2 = {5,6,4};
  auto l2 = create(vc2);
  print(l2);

  Solution s;
  auto l = s.addTwoNumbers(l1, l2);
  print(l);

  del(l1);
  del(l2);
  del(l);

  std::cin.get();
  return 0;
}
