//给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。 
//
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。 
//
// 此外，你可以假设该网格的四条边均被水包围。 
//
// 
//
// 示例 1： 
//
// 
//输入：grid = [
//  ["1","1","1","1","0"],
//  ["1","1","0","1","0"],
//  ["1","1","0","0","0"],
//  ["0","0","0","0","0"]
//]
//输出：1
// 
//
// 示例 2： 
//
// 
//输入：grid = [
//  ["1","1","0","0","0"],
//  ["1","1","0","0","0"],
//  ["0","0","1","0","0"],
//  ["0","0","0","1","1"]
//]
//输出：3
// 
//
// 
//
// 提示： 
//
// 
// m == grid.length 
// n == grid[i].length 
// 1 <= m, n <= 300 
// grid[i][j] 的值为 '0' 或 '1' 
// 
// Related Topics 深度优先搜索 广度优先搜索 并查集 
// 👍 1147 👎 0


#include "iostream"
#include "cassert"
#include "vector"
#include "string"
#include "functional"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        vector<vector<char>> visited(grid);
        unsigned long oneSize = grid.size();
        unsigned long twoSize = grid.at(0).size();
        int res = 0;

        function<void(int, int, bool)> search;
        search = [&search, &grid, &visited, &res, &oneSize, &twoSize](int one, int two, bool flag) {
            if (one < 0 || one >= oneSize || two < 0 || two >= twoSize) {
                return;
            }
            if (visited[one][two] == 'y') {
                return;
            }
            visited[one][two] = 'y';

            if (grid[one][two] != '1') {
                return;
            }
            // 依次上下左右
            search(one, two + 1, false);
            search(one, two - 1, false);
            search(one + 1, two, false);
            search(one - 1, two, false);
            if (flag) {
                res++;
            }

        };

        for (int i = 0; i < oneSize; ++i) {
            for (int j = 0; j < twoSize; ++j) {
                search(i, j, true);
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    //
    vector<vector<char>> t1 = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    int i = solution.numIslands(t1);

    return 0;
}