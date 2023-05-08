#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col)
{
    int N = board.size();
    for (int x = 0; x < col; x++)
        if (board[row][x] == 1)
            return false;
    for (int x = row, y = col; x >= 0 && y >= 0; x--, y--)
        if (board[x][y] == 1)
            return false;
    for (int x = row, y = col; x < N && y >= 0; x++, y--)
        if (board[x][y] == 1)
            return false;
    return true;
}

int solveNQueens(vector<vector<int>>& board, int col, int& count, int& steps)
{
    int N = board.size();
    if (col == N) {
        count++;
        if (count == 1 || count == 2) {
            cout << "Solution " << count << ":" << endl;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++)
                    cout << board[i][j] << " ";
                cout << endl;
            }
            cout << endl;
        }
        return count;
    }
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            steps++;
            count = solveNQueens(board, col + 1, count, steps); 
            board[i][col] = 0;
        }
    }
    return count;
}

int main()
{
    int N;
    cout << "Enter the value of N: ";
    cin >> N;
    vector<vector<int>> board(N, vector<int>(N, 0));
    int count = 0, steps = 0;
    int final_count = solveNQueens(board, 0, count, steps);
    if (final_count == 0)
        cout << "No solution found";
    else
        cout << "Number of solutions found: " << final_count << " in " << steps << " steps" << endl;
    return 0;
}
