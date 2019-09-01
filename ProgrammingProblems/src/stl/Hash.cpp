#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

std::vector<int> twoSumNoHash(std::vector<int>& nums, int target)
{
    std::vector<int> ret;
        
    for(unsigned int i=0; i<nums.size()-1; i++)
    {
        for(unsigned int j=i+1; j<nums.size(); j++)
            if(nums[i] + nums[j] == target)
            {
                ret.push_back(i);
                ret.push_back(j);
                return ret;
            }
    }
        
    return ret;
}

std::vector<int> twoSumHash(std::vector<int>& nums, int target)
{
    std::vector<int> ret;
    std::unordered_set<int> hashTable;
        
    for(auto numsIt = nums.begin(); numsIt != nums.end(); numsIt++)
    {
        auto hashIt = hashTable.find(target - *numsIt);
        if(hashIt != hashTable.end())
        {
            if(*numsIt + *hashIt == target)
            {
                ret.push_back(std::find(nums.begin(), nums.end(), *hashIt) - nums.begin());
                ret.push_back(numsIt - nums.begin());
                return ret;
            }
        }
        else
            hashTable.insert(*numsIt);
    }
        
    return ret;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool twoSumHashBT(struct TreeNode *node, int value)
{
    std::unordered_set<int> hashTable;
    std::queue<TreeNode*> q;

    q.push(node);

    while(!q.empty())
    {
        struct TreeNode *n = q.front();

        auto hashIt = hashTable.find(value - n->val);
        if(hashIt != hashTable.end())
            return true;
        else
            hashTable.insert(n->val);

        if(n->left)
            q.push(n->left);

        if(n->right)
            q.push(n->right);

        q.pop();
    }

    return false;
}

std::vector<int> twoSumAscendingOrder(std::vector<int> &numbers, int target)
{
    std::vector<int> ret;
    int l = 0;
    int r = numbers.size() - 1;

    while(l < r)
    {
        if(target > numbers[l] + numbers[r])
            l++;
        else if(target < numbers[l] + numbers[r])
            r--;
        else
        {
            ret.push_back(l);
            ret.push_back(r);
            return ret;
        }
    }

    return ret;
}

void DoTwoSum()
{
    std::vector<int> nums;
    std::vector<int> ret;

    // Empty input
    //ret = twoSumHash(nums, 99);

    // Not possible
    nums = {2, 7, 11, 15};
    //ret = twoSumHash(nums, 99);

    // Some good cases
    //ret = twoSumHash(nums, 9);
    //ret = twoSumHash(nums, 22); // Check possible duplicate 11+11

    ret = twoSumAscendingOrder(nums, 9);
}

