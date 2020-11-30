/*
leetcode21. 合并两个有序链表
将两个升序链表合并为一个新的 升序
链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

示例：
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (nullptr == l1) {
      return l2;
    }
    if (nullptr == l2) {
      return l1;
    }

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    while (l1 && l2) {
      if (l1->val <= l2->val) {
        if (nullptr == head) {
          head = tail = l1;
        } else {
          tail->next = l1;
          tail = tail->next;
        }
        l1 = l1->next;
      } else {
        if (nullptr == head) {
          head = tail = l2;
        } else {
          tail->next = l2;
          tail = tail->next;
        }
        l2 = l2->next;
      }

      if (l1) {
        tail->next = l1;
      }

      if (l2) {
        tail->next = l2;
      }
    }

    return head;
  }
};

#include <iostream>
#include <vector>

// 创建链表
ListNode* create(std::vector<int> vc) {
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
    std::cout << head->val;
    head = head->next;
  }
  std::cout << std::endl;
}

int main() {
  std::vector<int> vc1 = {2, 4, 5, 6, 7};
  auto l1 = create(vc1);
  print(l1);

  std::vector<int> vc2 = {1, 3, 5};
  auto l2 = create(vc2);
  print(l2);

  Solution s;
  auto l = s.mergeTwoLists(l1, l2);
  print(l);

  del(l);

  std::cin.get();
  return 0;
}
