/*
Snail Sort
Given an n x n array, return the array elements arranged from outermost elements to the middle element, traveling clockwise.

array = [[1,2,3],
         [4,5,6],
         [7,8,9]]
snail(array) #=> [1,2,3,6,9,8,7,4,5]
For better understanding, please follow the numbers of the next array consecutively:

array = [[1,2,3],
         [8,9,4],
         [7,6,5]]
snail(array) #=> [1,2,3,4,5,6,7,8,9]
*/

/*
   r, d, l, u

   t = 0
   b = array.size();
   l = 0
   r = array[0].size()

*/

#include <vector>

std::vector<int> snail(std::vector<std::vector<int>> array) {
    int t = 0;
    int b = array.size()-1;
    int l = 0;
    int r = array[0].size()-1;
    int count = array.size() * array[0].size();

    std::vector<int> ret;

    while(count)
    {
        // L to R, column
        for(int col=l; col<=r; col++, count--)
            ret.push_back(array[t][col]);

        t++;
    
        // T to B, row
        for(int row=t; row<=b && count; row++, count--)
            ret.push_back(array[row][r]);

        r--;

        // R to L, column
        for(int col=r; col>=l && count; col--, count--)
            ret.push_back(array[b][col]);

        b--;

        // B to T, row
        for(int row=b; row>=t && count; row--, count--)
            ret.push_back(array[row][l]);

        l++;
    }

    return ret;
}

void DoSnail()
{
    std::vector<std::vector<int>> a = {{1, 2, 3},
                                       {4, 5, 6},
                                       {7, 8, 9}};

    std::vector<int> ret = snail(a);
}