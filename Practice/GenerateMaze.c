#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 12
#define WALL '#'
#define PATH '.'
char maze[SIZE][SIZE];
void BuildWall()
{
    for (int i = 0; i < SIZE; i++)
        maze[0][i] = WALL;
    for (int i = 0; i < SIZE; i++)
        maze[11][i] = WALL;
    for (int i = 0; i < SIZE; i++)
        maze[i][0] = WALL;
    for (int i = 0; i < SIZE; i++)
        maze[i][11] = WALL;
}
void GetSquare(char *arr, int status)
{
    for (int i = 0; i < 9; i++)
        arr[i] = '0';
    // 0 -> no wall, 1 -> right wall
    // 2 -> up wall, 3 -> up right wall
    switch (status)
    {
    case 0: // no wall
        return;
    case 1: // right wall
        for (int i = 0; i < 3; i++)
            arr[2 + i * 3] = '1';
        return;
    case 2: // up wall
        for (int i = 0; i < 3; i++)
            arr[i] = '1';
        return;
    case 3: // up right wall
        for (int i = 0; i < 3; i++)
            arr[i] = '1';
        for (int i = 0; i < 3; i++)
            arr[2 + i * 3] = '1';
        return;
    }
}
void DrawSquare(int x, int y, int status)
{
    char wall[9];
    GetSquare(wall, status);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (wall[i * 3 + j] == '1')
                maze[i + x][j + y] = WALL;
            else
                maze[i + x][j + y] = PATH;
}
void StartAndEnd()
{
    int start = rand() % 10 + 1, end = rand() % 10 + 1;
    maze[start][0] = PATH;
    maze[end][11] = PATH;
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
    srand(time(NULL));
    for (int i = 0; i < SIZE / 3; i++)
        for (int j = 0; j < SIZE / 3; j++)
            DrawSquare(i * 3, j * 3, rand() % 4);
    BuildWall();
    StartAndEnd();
    PrintMaze();
    return 0;
}