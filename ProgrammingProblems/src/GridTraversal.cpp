#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <stack>
#include <utility>
#include <deque>

enum CellValue
{
    eFalse,
    eTrue,
    eOutOfBounds
};

void PrintStack(std::deque<std::pair<int, int>> &stack)
{
    for(auto p : stack)
        std::cout << "[" << p.first << "," << p.second << "]\n"; 
}

template<typename T>
class Array
{
public:
    unsigned int m_rows;
    unsigned int m_columns;

    Array(unsigned int rows, unsigned int columns)
       : m_array(nullptr)
       , m_rows(rows)
       , m_columns(columns)
    {
        m_array = new T *[m_rows * m_columns];

        for(unsigned int r=0; r<m_rows; r++)
        {
            m_array[r] = new T[m_columns];
            memset(m_array[r], 0, m_columns * sizeof(T));
        }
    }

    ~Array()
    {
        for(unsigned int r=0; r<m_rows; r++)
            delete [] m_array[r];

        delete [] m_array;
        m_array = nullptr;
    }

    void Fill()
    {
        m_array[0][0] = true;
        m_array[0][1] = true;
        m_array[0][2] = true;
        m_array[0][3] = true;
        m_array[0][4] = true;

        m_array[1][4] = true;
        m_array[2][4] = true;
        m_array[3][4] = true;
        m_array[4][4] = true;

        m_array[1][3] = true;

        //m_array[1][3] = true;
        //m_array[2][3] = true;
        //m_array[3][3] = true;
        //m_array[4][3] = true;

        /*
        m_array[0][0] = true;
        m_array[0][1] = true;
        m_array[0][2] = true;
        m_array[0][3] = true;
        m_array[0][4] = true;

        m_array[1][0] = true;
        m_array[1][1] = true;
        m_array[1][2] = true;
        m_array[1][3] = true;
        m_array[1][4] = true;

        m_array[2][0] = true;
        m_array[2][1] = true;
        m_array[2][2] = true;
        m_array[2][3] = true;
        m_array[2][4] = true;

        m_array[3][0] = true;
        m_array[3][1] = true;
        m_array[3][2] = true;
        m_array[3][3] = true;
        m_array[3][4] = true;

        m_array[4][0] = true;
        m_array[4][1] = true;
        m_array[4][2] = true;
        m_array[4][3] = true;
        m_array[4][4] = true;
        */

        /*
        srand(time(NULL));

        for(unsigned int r=0; r<m_rows; r++)
            for(unsigned int c=0; c<m_columns; c++)
            m_array[r][c] = rand() & 1;

        m_array[0][0] = true;
        m_array[m_rows-1][m_columns-1] = true;
        */
    }

    void Print()
    {
        for(unsigned int r=0; r<m_rows; r++)
        {
            for(unsigned int c=0; c<m_columns; c++)
                std::cout << m_array[r][c] << " ";

            std::cout << '\n';
        }
    }

    CellValue get(int r, int c)
    {
        if(r < 0 ||
           r >= m_rows)
            return eOutOfBounds;

        if(c < 0 ||
           c >= m_columns)
            return eOutOfBounds;

        return static_cast<CellValue>(m_array[r][c]);
    }

    void set(unsigned int r, unsigned int c)
    {
        if(r < 0 ||
           r >= m_rows)
            return;

        if(c < 0 ||
           c >= m_columns)
            return;

        m_array[r][c] = true;
    }

private:
    T **m_array;
};

bool FindPath(unsigned int r, unsigned int c, Array<bool> &a, Array<bool> &visited, std::deque<std::pair<int, int>> &pathStack)
{
    if(a.get(r, c) == eTrue && visited.get(r, c) == eFalse)
    {
        // c.first == N/S, Row major
        // c.second == E/W, Column second

        visited.set(r, c);

        if(r == visited.m_rows-1 &&
           c == visited.m_columns-1)
        {
            pathStack.emplace(pathStack.end(), std::pair<int, int>(r, c));
            return true;
        }

        // N
        if(FindPath(r-1, c, a, visited, pathStack))
        {
            pathStack.emplace(pathStack.end(), std::pair<int, int>(r, c));
            return true;
        }

        // S
        if(FindPath(r+1, c, a, visited, pathStack))
        {
            pathStack.emplace(pathStack.end(), std::pair<int, int>(r, c));
            return true;
        }

        // W
        if(FindPath(r, c-1, a, visited, pathStack))
        {
            pathStack.emplace(pathStack.end(), std::pair<int, int>(r, c));
            return true;
        }

        // E
        if(FindPath(r, c+1, a, visited, pathStack))
        {
            pathStack.emplace(pathStack.end(), std::pair<int, int>(r, c));
            return true;
        }
    }

    return false;
}

bool FindPathStack(unsigned int r, unsigned int c, Array<bool> &a, Array<bool> &visited, std::deque<std::pair<int, int>> &path)
{
    std::deque<std::pair<int, int>> theStack;
    theStack.push_back(std::pair<int, int>(r, c));

    unsigned int i = 0;

    while(!theStack.empty())
    {
        std::cout << "Stack Iteration:" << i++ << "\n";
        std::cout << "----------\n";

        std::pair<int, int> p = theStack.back();
        int r = p.first;
        int c = p.second;

        if(a.get(r, c) == eTrue && visited.get(r, c) == eFalse)
        {
            // c.first == N/S, Row major
            // c.second == E/W, Column second

            visited.set(r, c);

            if(r == visited.m_rows-1 &&
               c == visited.m_columns-1)
            {
                path.push_back(p);
                PrintStack(path);
                std::cout << '\n';
                return true;
            }
    
            path.push_back(p);
            PrintStack(path);
            std::cout << '\n';
            theStack.pop_back();

            // N
            theStack.emplace(theStack.end(), std::pair<int, int>(r-1, c));

            // S
            theStack.emplace(theStack.end(), std::pair<int, int>(r+1, c));

            // W
            theStack.emplace(theStack.end(), std::pair<int, int>(r, c-1));

            // E
            theStack.emplace(theStack.end(), std::pair<int, int>(r, c+1));
        }
        else
            theStack.pop_back();
    }
    return false;
}

bool FindPathQueue(unsigned int r, unsigned int c, Array<bool> &a, Array<bool> &visited, std::deque<std::pair<int, int>> &path)
{
    std::deque<std::pair<int, int>> theQueue;
    theQueue.push_back(std::pair<int, int>(r, c));

    unsigned int i = 0;

    while(!theQueue.empty())
    {
        std::cout << "Queue Iteration:" << i++ << "\n";
        std::cout << "----------\n";

        std::pair<int, int> p = theQueue.front();
        int r = p.first;
        int c = p.second;

        if(a.get(r, c) == eTrue && visited.get(r, c) == eFalse)
        {
            // c.first == N/S, Row major
            // c.second == E/W, Column second

            visited.set(r, c);

            if(r == visited.m_rows-1 &&
               c == visited.m_columns-1)
            {
                path.push_back(p);
                PrintStack(path);
                std::cout << '\n';
                return true;
            }
    
            path.push_back(p);
            PrintStack(path);
            std::cout << '\n';
            theQueue.pop_front();

            // N
            theQueue.emplace(theQueue.end(), std::pair<int, int>(r-1, c));

            // S
            theQueue.emplace(theQueue.end(), std::pair<int, int>(r+1, c));

            // W
            theQueue.emplace(theQueue.end(), std::pair<int, int>(r, c-1));

            // E
            theQueue.emplace(theQueue.end(), std::pair<int, int>(r, c+1));
        }
        else
            theQueue.pop_front();
    }
    return false;
}

void DoGridTraversal()
{
    Array<bool> a(5,5);
    a.Fill();
    a.Print();

    Array<bool> visited(5,5);

    std::deque<std::pair<int, int>> pathStack;
    //FindPathStack(0, 0, a, visited, pathStack);
    //FindPathQueue(0, 0, a, visited, pathStack);
    FindPath(0, 0, a, visited, pathStack);
    while(!pathStack.empty())
    {
        std::cout << "[" << pathStack.back().first << "," << pathStack.back().second << "]\n";
        pathStack.pop_back();
    }

    /*
    std::queue<std::pair<int, int>> pathq;
    pathq.emplace(std::pair<int, int>(0, 0));
    FindPath2(a, visited, pathq);
    while(!pathq.empty())
    {
        std::cout << "[" << pathq.front().first << "," << pathq.front().second << "]\n";
        pathq.pop();
    }
    */
}
