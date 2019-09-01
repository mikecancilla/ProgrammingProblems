#include <string>

int romanToInt(std::string s)
{
    int total = 0;

    for(int i=0; i<s.size(); i++)
    {
        switch(s[i])
        {
            case 'I':
                if(s[i+1] == 'V')
                {
                    total+=4;
                    i++;
                }
                else if(s[i+1] == 'X')
                {
                    total+=9;
                    i++;
                }
                else
                    total++;
            break;

            case 'V':
                total += 5;
            break;

            case 'X':
                if(s[i+1] == 'L')
                {
                    total+=40;
                    i++;
                }
                else if(s[i+1] == 'C')
                {
                    total+=90;
                    i++;
                }
                else
                    total += 10;
            break;

            case 'L':
                total += 50;
            break;

            case 'C':
                if(s[i+1] == 'D')
                {
                    total+=400;
                    i++;
                }
                else if(s[i+1] == 'M')
                {
                    total+=900;
                    i++;
                }
                else
                    total += 100;
            break;

            case 'D':
                total += 500;
            break;

            case 'M':
                total += 1000;
            break;
        }
    }

    return total;
}

void DoRomanNumerals()
{
    std::string rn = "III";
    int n = romanToInt(rn);

    rn = "XIVII";
    n = romanToInt(rn);
}