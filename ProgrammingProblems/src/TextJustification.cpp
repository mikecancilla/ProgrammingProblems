/*
This problem was asked by Palantir.

Write an algorithm to justify text. Given a sequence of words and an integer line length k, return a list of strings which represents each line, fully justified.

More specifically, you should have as many words as possible in each line. There should be at least one space between each word. Pad extra spaces when necessary so that each line has exactly length k. Spaces should be distributed as equally as possible, with the extra spaces, if any, distributed starting from the left.

If you can only fit one word on a line, then you should pad the right-hand side with spaces.

Each word is guaranteed not to be longer than k.

For example, given the list of words ["the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"] and k = 16, you should return the following:

["the  quick brown", # 1 extra space on the left
"fox  jumps  over", # 2 extra spaces distributed evenly
"the   lazy   dog"] # 4 extra spaces distributed evenly
*/

#include <string>
#include <vector>

#define MAX(x,y) (x > y ? x : y)

void DoTextJustification()
{
//    std::vector<std::string> words = { "the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog" };
    std::vector<std::string> words = { "the" };
    std::vector<std::string> returned_words;

    int line_length = 16;
    int num_words = 0;
    int total_length = 0;
    int words_used = 0;

    for(int i = 0; i < words.size();)
    {
        while(total_length + (num_words - 1) < line_length && i < words.size())
        {
            if(total_length + words[i].length() + num_words <= line_length)
            {
                total_length += words[i].length();
                num_words++;
                i++;
            }
            else
                break;
        }

        int left_over_spaces = line_length - total_length;
        int num_spaces = left_over_spaces / MAX(1,num_words-1);
        int first_spaces = num_spaces;
        
        if(num_words > 2)
            first_spaces += left_over_spaces % 2;

        std::string return_string;

        if(num_words)
        {
            return_string = words[words_used];

            for(int j=0; j<first_spaces; j++)
                return_string += " ";

            words_used++;
        }

        for(int x = 1; x<num_words; x++, words_used++)
        {
            return_string += words[words_used];

            for(int j=0; j<num_spaces && x != num_words-1; j++)
                return_string += " ";
        }

        returned_words.push_back(return_string);

        num_words = 0;
        total_length = 0;
    }
}