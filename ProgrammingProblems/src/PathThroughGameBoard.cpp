/*
    This problem was asked by Coursera.

    Given a 2D board of characters and a word, find if the word exists in the grid.

    The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

    For example, given the following board:

    [
      ['A','B','C','E'],
      ['S','F','C','S'],
      ['A','D','E','E']
    ]
    exists(board, "ABCCED") returns true, exists(board, "SEE") returns true, exists(board, "ABCB") returns false.
*/

/*
1- Walk the board l-r, t-b
2- Keep track of current cell C(r,c)
3- Pass board and current cell to FindWord(C, board, word)
4- If not found go to 1

FindWord(C, board, word)
- if word.empty()
    return true;

- look for word[0] in u
   if there, move C, and reduce word by 1
- look for word[0] in r
   if there, move C, and reduce word by 1
- look for word[0] in d
   if there, move C, and reduce word by 1
- look for word[0] in l
   if there, move C, and reduce word by 1
*/

#include <iostream>
#include <vector>

#define ROWS 3
#define COLUMNS 4

struct Cell
{
    unsigned int r, c;

    Cell(unsigned int r, unsigned int c)
        : r(r)
        , c(c)
    {}
};

void Print(char a[ROWS][COLUMNS])
{
    std::cout << a[0][2] << '\n';
}

bool FindWord(Cell c, char a[ROWS][COLUMNS], char *word)
{
    return false;
}

void DoFindWord()
{
    std::vector<std::vector<char>> grid;
    grid.push_back({'A','B','C','E'});
    grid.push_back({'S','F','C','S'});
    grid.push_back({'A','D','E','E'});

    char a[ROWS][COLUMNS] = {'A','B','C','E',
                             'S','F','C','S',
                             'A','D','E','E'};

    std::cout << a[0][1] << '\n';
    Print(a);
    std::cout << grid[0][1] << '\n';

    Cell c(0, 0);
    char word[] = "ABCCED";
    FindWord(c, a, word);
}
