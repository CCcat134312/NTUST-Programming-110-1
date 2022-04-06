// maze touch left wall
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#define SIZE 12
char maze[SIZE][SIZE];
enum direction
{
    up,
    down,
    left,
    right
};
struct point
{
    int x;
    int y;
    enum direction dir;
};
void MoveOne(struct point* p)
{
    switch (p->dir)
    {
    case right:
        p->y++;
        break;
    case left:
        p->y--;
        break;
    case up:
        p->x--;
        break;
    case down:
        p->x++;
        break;
    }
}
int FrontIsWall(struct point p)
{
    switch (p.dir)
    {
    case right:
        return (maze[p.x][p.y + 1] == '#');
    case left:
        return (maze[p.x][p.y - 1] == '#');
    case up:
        return (maze[p.x - 1][p.y] == '#');
    case down:
        return (maze[p.x + 1][p.y] == '#');
    }
}
int LeftIsWall(struct point p)
{
    switch (p.dir)
    {
    case right:
        return (maze[p.x - 1][p.y] == '#');
    case left:
        return (maze[p.x + 1][p.y] == '#');
    case up:
        return (maze[p.x][p.y - 1] == '#');
    case down:
        return (maze[p.x][p.y + 1] == '#');
    }
}
void TurnRight(struct point* p)
{
    switch (p->dir)
    {
    case right:
        p->dir = down;
        return;
    case left:
        p->dir = up;
        return;
    case up:
        p->dir = right;
        return;
    case down:
        p->dir = left;
        return;
    }
}
void TurnLeft(struct point* p)
{
    switch (p->dir)
    {
    case right:
        p->dir = up;
        return;
    case left:
        p->dir = down;
        return;
    case up:
        p->dir = left;
        return;
    case down:
        p->dir = right;
        return;
    }
}
void PrintMaze()
{
    for (int i = 0; i < SIZE; i++, putchar('\n'))
        for (int j = 0; j < SIZE; j++)
            putchar(maze[i][j]);
}
int main()
{
    for (int i = 0; i < SIZE; i++)
        scanf("%s", &maze[i]);

    struct point p = { .y = 0, .dir = right };
    for (int i = 0; i < SIZE; i++)
        if (maze[i][0] == 'X')
            p.x = i;
    maze[p.x][p.y] = 'R';
    p.y++;
    while (p.y != SIZE - 1 && p.y != 0)
    {
        maze[p.x][p.y] = 'R';
        if (!LeftIsWall(p))
            TurnLeft(&p);

        if (!FrontIsWall(p))
            MoveOne(&p);
        else
            TurnRight(&p);
    }
    maze[p.x][p.y] = 'R';
    PrintMaze();
    if (p.y == 0)
    {
        puts("This maze has no solution");
    }
    return 0;
}
/*
############
##XXXXX#XXX#
##X###X###X#
##X#XXXXXXX#
##X#######X#
#XX#X####XX#
XX##XXXXXX##
####X##X##X#
#X#X#XXX##X#
#X#X##X#XXX#
#XXX##XXX#XX
############
*/