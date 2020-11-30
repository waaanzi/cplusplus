/*
leetcode2. �������
���������ǿյ�����������ʾ�����Ǹ������������У����Ǹ��Ե�λ���ǰ�������
�ķ�ʽ�洢�ģ��������ǵ�ÿ���ڵ�ֻ�ܴ洢һλ���֡�
��������ǽ��������������������᷵��һ���µ���������ʾ���ǵĺ͡�
�����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ��

ʾ����
���룺(2 -> 4 -> 3) + (5 -> 6 -> 4)
�����7 -> 0 -> 8
ԭ��342 + 465 = 807
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
  int carry = 0;  // ��λ
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
    int carry = 0;  // ��λ
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

// ��������
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

// �ͷ�����
void del(ListNode* head) {
  while (head) {
    auto temp = head->next;
    delete head;
    head = temp;
  }
}

// ��ӡ����
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
