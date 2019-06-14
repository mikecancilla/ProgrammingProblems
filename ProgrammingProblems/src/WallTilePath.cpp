/*
This problem was asked by Google.

You are given an M by N matrix consisting of booleans that represents a board.Each True boolean represents a wall.Each False boolean represents a tile you can walk on.

Given this matrix, a start coordinate, and an end coordinate, return the minimum number of steps required to reach the end coordinate from the start.If there is no possible path, then return null.You can move up, left, down, and right.You cannot move through walls.You cannot wrap around the edges of the board.

For example, given the following board :

[[f, f, f, f],
 [t, t, f, t],
 [f, f, f, f],
 [f, f, f, f]]

and start = (3, 0) (bottom left) and end = (0, 0) (top left), the minimum number of steps required to reach the end is 7, since we would need to go through(1, 2) because there is a wall everywhere else on the second row.
*/

// SOLUTION: https://www.geeksforgeeks.org/shortest-path-in-a-binary-maze/

#define MAX(x, y) (x >= y) ? x : y;

struct Pos
{
    int r, c;
};

bool g_bDone = false;

#define VALIDATE(map, r, c) ((r >= 0 && r <= 3) && (c >= 0 && c <= 3) && !map[r*4 + c])

/*
unsigned int WalkPath(bool *map, const int &r, const int &c, const Pos &end)
{
    if(g_bDone)
        return 0;

    if(r < 0 ||
       r > 3)
       return 0;

    if(c < 0 ||
       c > 3)
       return 0;

    if(r == end.r &&
       c == end.c)
    {
        g_bDone = true;
        return 0;
    }

    if(VALIDATE(map, r, c+1))
        return 1 + WalkPath(map, r, c+1, end);

    if (VALIDATE(map, r, c-1))
        return 1 + WalkPath(map, r, c-1, end);

    if (VALIDATE(map, r+1, c))
        return 1 + WalkPath(map, r+1, c, end);

    if (VALIDATE(map, r-1, c))
        return 1 + WalkPath(map, r-1, c, end);

    return 0;
}
*/
unsigned int WalkPath(bool *map, const int &r, const int &c, const Pos &end)
{
    if (g_bDone)
        return 0;

    if (r < 0 ||
        r > 3)
        return 0;

    if (c < 0 ||
        c > 3)
        return 0;

    if (r == end.r &&
        c == end.c)
    {
        g_bDone = true;
        return 0;
    }

	map[r*4 + c] = true;

	unsigned int points[4] = {0, 0, 0, 0};

	// right
    if (VALIDATE(map, r, c + 1))
        points[0] =  1 + WalkPath(map, r, c + 1, end);

	// left
    if (VALIDATE(map, r, c - 1))
        points[1] = 1 + WalkPath(map, r, c - 1, end);

	// down
    if (VALIDATE(map, r + 1, c))
        points[2] = 1 + WalkPath(map, r + 1, c, end);

	// up
    if (VALIDATE(map, r - 1, c))
        points[3] = 1 + WalkPath(map, r - 1, c, end);

    unsigned int min = -1;
    for(unsigned int i=0; i<4; i++)
		if(points[i] < min)
			min = points[i];

    return min;
}

void DoWallTilePath()
{
    bool map[4 * 4] = {false, false, false, false,
                        true,  true, false,  true,
                       false, false, false, false,
                       false, false, false, false};

    const Pos start = { 3, 0 };
    const Pos end =   { 0, 0 };

    WalkPath(map, start.r, start.c, end);
}