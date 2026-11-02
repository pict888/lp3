
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int n;
bool found = false;
vector<int> board;

bool isSafe(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i] == col)
            return false;
        if (abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

void printBoard()
{
    cout << "\nSolution:\n\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i] == j)
                cout << " Q ";
            else
                cout << " . ";
        }
        cout << endl;
    }
}

void solve(int row)
{
    if (found)
        return;

    if (row == n)
    {
        found = true;
        printBoard();
        return;
    }

    // Keep the first queen in its original position
    if (board[row] != -1)
    {
        solve(row + 1);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col))
        {
            board[row] = col;
            solve(row + 1);
            board[row] = -1;
        }
    }
}

int main()
{
    int firstRow, firstCol;

    cout << "Enter number of queens: ";
    cin >> n;

    if (n < 1)
    {
        cout << "Invalid board size";
        return 0;
    }

    board.resize(n, -1);

    cout << "Enter first queen row and column (0 to " << n - 1 << "): ";
    cin >> firstRow >> firstCol;

    if (firstRow < 0 || firstRow >= n || firstCol < 0 || firstCol >= n)
    {
        cout << "Invalid position";
        return 0;
    }

    board[firstRow] = firstCol;

    solve(0);

    if (!found)
        cout << "\nNo solution exists for this position";

    return 0;
}
