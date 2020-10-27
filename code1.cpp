#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node {
  int val;
  Node* next;
};

void print(Node* head) {
  while (head) {
    std::cout << head->val;
    head = head->next;
  }
  std::cout << std::endl;
}

// 将两个链表表示的整数相加，结果用链表表示。
// 例如：
// [1->2->3] + [4->5->6] = [5->7->9]

Node* add(Node* head1, Node* head2) {
  std::stack<int> d1;
  while (head1) {
    d1.push(head1->val);
    head1 = head1->next;
  }

  std::stack<int> d2;
  while (head2) {
    d2.push(head2->val);
    head2 = head2->next;
  }

  Node* h = nullptr;
  int sum = 0;
  while (d1.size() || d2.size()) {
    if (d1.size()) {
      sum += d1.top();
      d1.pop();
    }
    if (d2.size()) {
      sum += d2.top();
      d2.pop();
    }

    Node* node = new Node();
    node->val = sum % 10;
    node->next = h;

    sum = sum / 10;
    h = node;
  }

  if (0 != sum) {
    Node* node = new Node();
    node->val = sum;
    node->next = h;
    h = node;
  }

  return h;
}

Node* create(std::vector<int> vc) {
  Node* head = nullptr;
  Node* tail = nullptr;
  auto it = vc.begin();
  while (it != vc.end()) {
    Node* temp = new Node();
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

void del(Node* head) {
  while(head) {
    auto temp = head->next;
    delete head;
    head = temp;
  }
}

int main() {
  std::vector<int> vc1 = {6,6,6,6,6};
  auto l1 = create(vc1);
  print(l1);

  std::vector<int> vc2 = {1,2,3,4,5};
  auto l2 = create(vc2);
  print(l2);

  auto l = add(l1, l2);
  print(l);

  del(l1);
  del(l2);
  del(l);

  std::cin.get();
  return 0;
}