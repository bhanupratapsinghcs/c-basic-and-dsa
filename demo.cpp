#include <bits/stdc++.h>
#include <String>
using namespace std;
void printGrid(vector<vector<char>> grid) res [[1,2,3], [4, 5,5]]
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid.size(); j++)
        {
            cout << grid[i][i];
        }
        cout << '\n';
    }
    cout << "----------------------------------" << endl;
}
int checkWinCase(vector<vector<char>> grid, int x, int y)
{
    int noOfRow = 0;
    int n = grid.size();
    // x = 1 ; y = 1;
    // x = 2-1 ; y = 3-1;
    
    for (int i = y; i < n+y-1; i++) //00 == 10 and 01 == 02 0 1 2 2
    {
        if (grid[x][i%n] == grid[x][(i + 1)%n]) // checking the row where the data in entered 
        // 0 0 == 0 1
        // 0 1 == 0 2
        {
            noOfRow++;
        }
    }
    // 3 * 3
    //   x= 0 y = 0
    //   10, 11, 12
    int noOfCol = 0;
    for (j in (column - 1))
    {
        if (grid[y][j] == grid[y][j + 1])
        {
            noOfCol++;
        }
    }
    int diagonal1 = 0, diagonal2 = 0;
    // 1 3 4
    // 4 5 6
    // 7 8 9
    for (int i = 0; i < grid.size() - 1; i++)
    {
        if (grid[i][i] == grid[i + 1][i + 1])
        {
            diagonal1++;
        }
        if (grid[i][n - 1 - i] == grid[i + 1][n- 2 - i]) // 02 == 11  and 11 == 20
        0 2 == 1 1
        1 1 == 2 0
        {
            diagonal2++;
        }
    }
    n = n-1;
    if ((noOfRow == n) || (noOfCol == n) || (diagonal1 == n) || (diagonal2 == n))
    {
        return 1;
    }
    return 0;
}
int chechTheMoveAndFill(vector<vector<char>> &grid, int x, int y)
{
    if (grid[x][y] == '-')
    {
        return 1;
    }
    return 0;
}
// int
int main()
{
    string user1, user2;
    int row, column; // size of grid
    char user1playtoken, user2playtoken;
    cin >> user1playtoken >> user1;
    cin >> user2playtoken >> user2;
    vector<vector<char>> grid;
    // initialisiing the grid
    for (int i = i < row; i++)
    {
        for (int j = j < column; j++)
        {
            grid[i][i] = '-';
        }
        
    }
    // start the game by taking the input
    printGrid(grid);
    int x, y;
    for (int i = 0; i < grid.size()*grid.size(); i++)
    {
        cin >> x >> y;
        if (i % 2 == 0) // user one
        {
            if (chechTheMoveAndFill(grid, x, y))
            {
                grid[x][y] == user1playtoken; // token for playing the come
                printGrid(grid);

                if (checkWinCase(grid, x, y))
                { //checking for each wining condition iteratation
                    cout << user1 << " won the game" << endl;
                    return 0; // this return will end the program here as player as won the match
                }
            }
            else
            {
                cout << "invalid Input";
                printGrid(grid);
                i--; // decreasing the invilid the input
            }
        }
        else //user 2
        {
            if (chechTheMoveAndFill(grid, x, y))
            {
                grid[x][y] == user2playtoken; // token for playing the come
                printGrid(grid);
                if (checkWinCase(grid, x, y))
                {
                    cout << user2 << " won the game" << endl;
                    return 0; // this return will end the program here as player as won the match
                }
            }
            else
            {
                cout << "invalid Input";
                printGrid(grid);
                i--;
            }
        }
    }
    string termination;
    cin >> termination;
    if (termination == "exit")
    {
        cout << "Game Over";
    }
}