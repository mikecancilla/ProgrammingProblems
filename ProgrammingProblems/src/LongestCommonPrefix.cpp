#include <vector>
#include <string>

std::string longestCommonPrefix(std::vector<std::string>& strs)
{
    if(strs.size() == 0)
        return {};

    if(strs.size() == 1)
        return strs[0];

    std::string &s1 = strs[0];
    int max = s1.size();
    unsigned int index;

    for(int i=1; i<strs.size(); i++)
    {
        std::string &s2 = strs[i];

        max = max < s2.size() ? max : s2.size();

        index = 0;
        for(int j=0; j<max; j++)
        {
            if(s1[j] == s2[j])
                index++;
        }

        max = index < max ? index : max;
    }

    return s1.substr(0, max);
}

void DoLongestCommonPrefix()
{
    std::vector<std::string> strings = {"flower", "flow", "flight"};
    std::string s = longestCommonPrefix(strings);

    strings = {""};
    s = longestCommonPrefix(strings);
}