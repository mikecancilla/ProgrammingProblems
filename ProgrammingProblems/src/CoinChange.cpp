/*
The canonical DP coin change problem.

Given a value N, if we want to make change for N cents,
and we have an infinite supply of each of S = { S1, S2, ..., Sm} valued coins,
how many ways can we make the change?

The order of coins doesn’t matter.

For example, for N = 4 and S = {1,2,3}, there are four solutions:
{1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4.

For N = 10 and S = {2, 5, 3, 6}, there are five solutions:
{2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.
*/

/*
var N = 10, c = [2,5,3,6];

function change (cc, n) {
    var s = 0, i, j;

    for(i = 0; i < cc.length; i++) {
        s += cc[i];
    }

    if(s === N) {
        return console.log(cc);
    }

    if(s < N) {
        for(j = n; j < c.length; j++) {
            cc.push(c[j]);
            change(cc, j);
            cc.pop();
        }
    }
}

change([], 0);
*/

#include <vector>
#include <iostream>

void print(std::vector<int> v)
{
    for(auto i : v)
        std::cout << i << " ";

    std::cout << std::endl;
}

int change(int &N, std::vector<int> &c, std::vector<int> cc = {}, int start = 0)
{
    static int count = 0;

    print(cc);

    int s=0;

    for(int i=0; i<cc.size(); i++)
        s += cc[i];

    if(s == N)
        return ++count;

    if(s < N)
    {
        for(int i=start; i<c.size(); i++)
        {
            cc.push_back(c[i]);
            change(N, c, cc, i);
            cc.pop_back();
        }
    }

    return count;
}

void DoChange()
{
    int N = 10;
    std::vector<int> c = {2,5,7,3,1,6};

    int count = change(N, c);
}