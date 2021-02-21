// https: //leetcode.com/problems/valid-sudoku
#include <stdio.h>
#include <stdbool.h>

// board 9x9, partially filled
bool isValidSudoku(char **board, int boardSize, int *boardColSize)
{
    int i, j;
    int k;
    char t;
    for (i = 0; i < 9; ++i)
    {
        for (j = 0; j < 9; ++j)
        {
            t = board[i][j];
            if (t == '.')
            {
                continue;
            }
            // check row
            for (k = j + 1; k < 9; ++k)
            {
                if (!(board[i][k] - t))
                {
                    return false;
                }
            }
            // check column
            for (k = i + 1; k < 9; ++k)
            {
                if (!(board[k][j] - t))
                {
                    return false;
                }
            }
            int n1, n2;
            int r = 1;
            for (n1 = 0; n1 < 3; ++n1)
            {
                for (n2 = 0; n2 < 3; ++n2)
                {
                    if (board[i - i % 3 + n1][j - j % 3 + n2] == t)
                    {
                        if (r)
                        {
                            r++;
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

int main(){
    if(2) printf("2\n");
    return 0;
}