#include <vector>

std::vector<int> tribonacci(std::vector<int> signature, int n)
{
    std::vector<int> result;

    if(0 == n)
        return result;
    
    for(int i = 0; i<3 && n; i++, n--)
        result.push_back(signature[i]);

    for(int i = 0; i < n; i++)
        result.push_back(result[i] + result[i+1] + result[i+2]);

    return result;
}

void DoTribonacci()
{
    std::vector<int> v_in = {0, 0 ,1};

    std::vector<int> v_out = tribonacci(v_in, 5);
}