/*
This problem was asked by Microsoft.

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example, given [100, 4, 200, 1, 3, 2], the longest consecutive element sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

#include <iostream>
#include <unordered_set>

#define MAX(x, y) ((x) > (y) ? (x) : (y));

// Returns length of the longest contiguous subsequence 
int findLongestConseqSubseq(int arr[], int n) 
{ 
    std::unordered_set<int> S; 
    int ans = 0; 
  
    // Hash all the array elements 
    for (int i = 0; i < n; i++) 
        S.insert(arr[i]); 
  
    // check each possible sequence from the start 
    // then update optimal length 
    for (int i=0; i<n; i++) 
    { 
        // if current element is the starting 
        // element of a sequence 
        if (S.find(arr[i]-1) == S.end()) 
        { 
            // Then check for next elements in the 
            // sequence 
            int j = arr[i]; 
            while (S.find(j) != S.end()) 
                j++; 
  
            // update  optimal length if this length 
            // is more 
            ans = MAX(ans, j - arr[i]); 
        } 
    } 
    return ans; 
}

void DoLongestConsecutiveElements()
{
    int arr[] =  {1, 9, 3, 10, 4, 20, 2}; 
    int n = sizeof arr/ sizeof arr[0]; 
    std::cout << "Length of the Longest contiguous subsequence is "
         << findLongestConseqSubseq(arr, n); 
}