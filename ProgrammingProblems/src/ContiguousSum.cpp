#include <vector>
#include <queue>

std::vector<int> contiguousSum(std::vector<int> &v, int target)
{
    int sum=0;
    unsigned int i1=0, i2=0;
    std::vector<int> ret;

    for(int i=0; i<v.size() && !ret.size(); i++)
    {
        if(sum + v[i] == target)
        {
            i2 = i;
            for(int i=i1; i<=i2; i++)
                ret.push_back(v[i]);
        }
        else if(sum + v[i] > target)
        {
            sum -= v[i1++];
            i--;
        }
        else
        {
            sum += v[i];
            i2 = i;
        }
    }

    return ret;
}

void DoContiguousSum()
{
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::vector<int> r = contiguousSum(v, 9);

    r = contiguousSum(v, 7);
}