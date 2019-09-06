#include <string>

bool EqualShift(const std::string &a, const std::string &b)
{
    if(a.size() != b.size())
        return false;

    size_t pos = b.find(a[0]);

    if(pos == std::string::npos)
        return false;

    bool bRet = true;

    for(int i=0; i<a.size(); i++)
    {
        size_t index = pos++ % b.size();
        if(a[i] != b[index])
        {
            bRet = false;
            break;
        }
    }

    return bRet;
}

void DoShiftAString()
{
    std::string a = "abcde";
    std::string b = "cdeab";

    a = "abc";
    b = "acb";

    bool e = EqualShift(a, b);
}