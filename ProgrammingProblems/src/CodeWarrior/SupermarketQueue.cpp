/*
    There is a queue for the self-checkout tills at the supermarket. Your task is write a function to calculate the total time required for all the customers to check out!

    input
    customers: an array of positive integers representing the queue. Each integer represents a customer, and its value is the amount of time they require to check out.
    n: a positive integer, the number of checkout tills.
    output
    The function should return an integer, the total time required.

    Important
    Please look at the examples and clarifications below, to ensure you understand the task correctly :)

    Examples
    queueTime(std::vector<int>{5,3,4}, 1)
    // should return 12
    // because when n=1, the total time is just the sum of the times

    queueTime(std::vector<int>{10,2,3,3}, 2)
    // should return 10
    // because here n=2 and the 2nd, 3rd, and 4th people in the 
    // queue finish before the 1st person has finished.

    queueTime(std::vector<int>{2,3,10}, 2)
    // should return 12
    Clarifications
    There is only ONE queue serving many tills, and
    The order of the queue NEVER changes, and
    The front person in the queue (i.e. the first element in the array/list) proceeds to a till as soon as it becomes free.
    N.B. You should assume that all the test input will be valid, as specified above.

    P.S. The situation in this kata can be likened to the more-computer-science-related idea of a thread pool, with relation to running multiple processes at the same time: https://en.wikipedia.org/wiki/Thread_pool
*/

/*
create queues
assign people from input queue: pop each person off the front into active set
loop:
   find min of active set
   add that min to total
   subtract that min from all other actives
   pull someone from single queue into this queue

5, 3, 6, 1

0
3
t=3+2+1+3

0
0
1
t=3+1+1+1
*/
  
#include <vector>

#define MIN(x,y) ((x) < (y) ? (x) : (y))

struct line
{
    bool open;
    int timeLeft;
};

unsigned int queueTime(std::vector<int> v, const unsigned int &numLines)
{
    unsigned int t = 0;
    std::vector<line> lines;
    unsigned int total = 0;

    // Assign people from input queue: pop each person off the front into active set
    for(unsigned int i = 0; i < numLines; i++)
    {
        if(v.end() != v.begin())
        {
            line l;
            l.open = true;
            l.timeLeft = *v.begin();

            lines.push_back(l);
            v.erase(v.begin());
        }
    }

    unsigned int linesClosed = 0;

    while(linesClosed != lines.size())
    {
        unsigned int min = -1;

        // Find min of active set
        for(auto i = lines.begin(); i != lines.end(); i++)
        {
            if(i->open)
                min = MIN(min, i->timeLeft);
        }

        total += min;

        std::vector<std::vector<int>::iterator> deleteUs;
        for(auto i = lines.begin(); i != lines.end(); i++)
        {
            i->timeLeft -= min;

            if(0 == i->timeLeft)
            {
                if(v.end() != v.begin())
                {
                    i->timeLeft = *v.begin();
                    v.erase(v.begin());
                }
                else
                {
                    i->open = false;
                    ++linesClosed;
                }
            }
        }
    }

    return total;
}

void DoSuperMarketQueue()
{
//    unsigned int t = queueTime({}, 1);

    std::vector<int> v = {2, 2, 3, 3, 4, 4};
    unsigned int t = queueTime(v, 2);
}