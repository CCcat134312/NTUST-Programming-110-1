#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 12
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
char maze[SIZE][SIZE];
void MoveOne(struct point *p)
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
int RightIsWall(struct point p)
{
    switch (p.dir)
    {
    case right:
        return (maze[p.x + 1][p.y] == '#');
    case left:
        return (maze[p.x - 1][p.y] == '#');
    case up:
        return (maze[p.x][p.y + 1] == '#');
    case down:
        return (maze[p.x][p.y - 1] == '#');
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
void TurnRight(struct point *p)
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
void TurnLeft(struct point *p)
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
            printf("%c", maze[i][j]);
    putchar('\n');
}
int main(void)
{
    for (int i = 0; i < SIZE; i++)
        scanf("%s", &maze[i]);

    struct point p = {.y = 0, .dir = right};
    for (int i = 0; i < SIZE; i++)
        if (maze[i][0] == '.')
            p.x = i;

    while (p.y != SIZE - 1)
    {
        maze[p.x][p.y] = 'X';
        if (!RightIsWall(p))
            TurnRight(&p);
        if (!FrontIsWall(p))
            MoveOne(&p);
        else
            TurnLeft(&p);
        PrintMaze();
        printf("%d %d %d\n", p.x, p.y, p.dir);
    }
    return 0;
}
/*
############
#...#......#
..#.#.####.#
###.#....#.#
#....###.#..
####.#.#.#.#
#..#.#.#.#.#
##.#.#.#.#.#
#........#.#
######.###.#
#......#...#
############
*/