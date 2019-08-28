
#include <algorithm>
#include <string>
#include <vector>

bool IsVowel(char c)
{
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

int getCount(const std::string& inputStr){
  std::vector<char> ret(std::count_if(inputStr.begin(), inputStr.end(), IsVowel));
  std::copy_if(inputStr.begin(), inputStr.end(), ret.begin(), IsVowel);
  return ret.size();
}

void DoNumVowels()
{
    std::string s = "thequickbrownfoxjumpedoverthelazydog";
    int i = getCount(s);
}