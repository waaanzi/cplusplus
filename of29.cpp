/*
剑指Offer 29. 顺时针打印矩阵
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

示例 1：
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]

示例 2：
输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]


限制：
0 <= matrix.length <= 100
0 <= matrix[i].length <= 100
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// int* spiralOrder(int** matrix,
//                 int matrixSize,
//                 int* matrixColSize,
//                 int* returnSize) {}
//
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int row = matrix.size();
    if (0 == row) {
      return vector<int>();
    }

    int col = matrix[0].size();
    if (0 == col) {
      return vector<int>();
    }

    return getCircle(matrix, 0, 0, row, col);
  }

 private:
  vector<int> getCircle(vector<vector<int>>& matrix,
                        int start_row,
                        int start_col,
                        int row_len,
                        int col_len) {
    if (row_len < 1 || col_len < 1) {
      return vector<int>();
    }

    vector<int> res;

    if (1 == row_len && 1 == col_len) {
      // .
      res.push_back(matrix[start_row][start_col]);
    } else if (1 == row_len) {
      // ——
      for (int i = 0; i < col_len; ++i) {
        res.push_back(matrix[start_row][start_col + i]);
      }
    } else if (1 == col_len) {
      // |
      for (int i = 0; i < row_len; ++i) {
        res.push_back(matrix[start_row + i][start_col]);
      }
    } else {
      // 口
      for (int i = 0; i < col_len; ++i) {
        res.push_back(matrix[start_row][start_col + i]);
      }

      for (int i = 1; i < row_len; ++i) {
        res.push_back(matrix[start_row + i][start_col + col_len - 1]);
      }

      for (int i = col_len - 2; i >= 0; --i) {
        res.push_back(matrix[start_row + row_len - 1][start_col + i]);
      }

      for (int i = row_len - 2; i > 0; --i) {
        res.push_back(matrix[start_row + i][start_col]);
      }
    }

    auto inner_circle = getCircle(matrix, start_row + 1, start_col + 1,
                                  row_len - 2, col_len - 2);

    copy(inner_circle.begin(), inner_circle.end(), back_inserter(res));

    return res;
  }
};

#include <iostream>
int main() {
   Solution s;
   {
     vector<vector<int>> matrix{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
     auto res = s.spiralOrder(matrix);
     for (auto i : res) {
       cout << i << " ";
     }
     cout << endl;
   }
   {
     vector<vector<int>> matrix{{3}, {2}};
     auto res = s.spiralOrder(matrix);
     for (auto i : res) {
       cout << i << " ";
     }
   }

  cin.get();
  return 0;
}