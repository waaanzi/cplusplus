/*
leetcode83. 删除排序链表中的重复元素
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:
输入: 1->1->2
输出: 1->2

示例 2:
输入: 1->1->2->3->3
输出: 1->2->3
*/

#include <malloc.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head){
  if(NULL == head) {
    return head;
  }

  struct ListNode* ps = head; // 慢指针
  struct ListNode* pf = head->next; // 快指针
  while (NULL != pf) {
    if (pf->val == ps->val){
      struct ListNode* ptemp = pf;
      pf = pf->next;
      free(ptemp);
    }else{
      ps->next = pf;
      ps = ps->next;
      pf = pf->next;
    }
  }

  ps->next = NULL;

  return head;
}

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
    ListNode* deleteDuplicates(ListNode* head) {
        
    }
};

#include <vector>
#include <iostream>
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
  vector<int> vc1 = { 1, 1, 2, 3, 3 };
  auto l1 = create(vc1);
  print(l1);

  auto l2 = deleteDuplicates(l1);
  print(l2);

  del(l2);

  std::cin.get();
  return 0;
}