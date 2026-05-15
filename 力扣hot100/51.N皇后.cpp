#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> res;

    // 回溯函数
    void backtracing(int row, int n, vector<string>& chessboard)
    {
        // 终止条件：如果行号等于 n，说明所有行都成功放置了皇后
        if (row == n)
        {
            res.push_back(chessboard);
            return;
        }

        // 遍历当前行的每一列
        for (int i = 0; i < n; i++)
        {
            // 检查当前位置 (row, i) 是否合法
            if (isValid(row, i, chessboard, n))
            {
                chessboard[row][i] = 'Q';       // 做选择：放置皇后
                backtracing(row + 1, n, chessboard); // 递归：处理下一行
                chessboard[row][i] = '.';       // 撤销选择：回溯
            }
        }
    }

    // 检查位置是否合法
    bool isValid(int row, int col, vector<string>& chessboard, int n)
    {
        // 1. 检查列：看当前列上方是否有皇后
        for (int i = 0; i < row; i++)
        {
            if (chessboard[i][col] == 'Q')
            {
                return false;
            }
        }

        // 2. 检查左上对角线 (45度)
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (chessboard[i][j] == 'Q')
            {
                return false;
            }
        }

        // 3. 检查右上对角线 (135度)
        // 注意：这里 j < n 是防止越界的关键
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (chessboard[i][j] == 'Q')
            {
                return false;
            }
        }

        return true;
    }

    vector<vector<string>> solveNQueens(int n) {
        res.clear(); // 清空结果，防止多次调用残留
        // 初始化 n x n 的棋盘，全部填充满 '.'
        vector<string> chessboard(n, string(n, '.'));
        // 从第 0 行开始回溯
        backtracing(0, n, chessboard);
        return res;
    }
};
int main() {
    Solution s;
    int n = 6;
    
    vector<vector<string>> result = s.solveNQueens(n);
    
    cout << "[";
    for (int k = 0; k < result.size(); ++k) {
        cout << "[";
        for (int i = 0; i < result[k].size(); ++i) {
            cout << "\"" << result[k][i] << "\"";
            if (i < result[k].size() - 1) cout << ",";
        }
        cout << "]";
        if (k < result.size() - 1) cout << ",";
    }
    cout << "]" << endl << endl;
    
    
    }