/*
leetcode83. ɾ�����������е��ظ�Ԫ��
����һ����������ɾ�������ظ���Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Ρ�

ʾ�� 1:
����: 1->1->2
���: 1->2

ʾ�� 2:
����: 1->1->2->3->3
���: 1->2->3
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

  struct ListNode* ps = head; // ��ָ��
  struct ListNode* pf = head->next; // ��ָ��
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
  vector<int> vc1 = { 1, 1, 2, 3, 3 };
  auto l1 = create(vc1);
  print(l1);

  auto l2 = deleteDuplicates(l1);
  print(l2);

  del(l2);

  std::cin.get();
  return 0;
}