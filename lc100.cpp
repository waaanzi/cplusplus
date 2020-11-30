/*
leetcode100. ��ͬ����
������������������дһ�����������������Ƿ���ͬ��
����������ڽṹ����ͬ�����ҽڵ������ͬ��ֵ������Ϊ��������ͬ�ġ�
*/

struct TreeNode {
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
};

#include <cstddef>
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
  while (p && q) {
    if (p->val != q->val) {
      return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }

  if (((NULL == p) && q) || (p && (NULL == q))) {
    return false;
  }

  return true;
}

#include <queue>
using namespace std;
class Solution {
 public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if ((nullptr == p) ^ (nullptr == q)) {
      return false;
    }
    if ((nullptr == p) && (nullptr == q)) {
      return true;
    }
    queue<TreeNode*> q_p;
    q_p.push(p);
    queue<TreeNode*> q_q;
    q_q.push(q);
    while(!q_p.empty() && !q_q.empty()){
      auto node_p = q_p.front();
      q_p.pop();
      auto node_q = q_q.front();
      q_q.pop();

      if ((nullptr == node_p) ^ (nullptr == node_q)) {
        return false;
      }
      if ((nullptr == node_p) && (nullptr == node_q)) {
        continue;
      }

      if (node_p->val != node_q->val){
        return false;
      }

      q_p.push(node_p->left);
      q_p.push(node_p->right);
      q_q.push(node_q->left);
      q_q.push(node_q->right);
    }

    return true;
  }
};