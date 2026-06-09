#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define ROWS 25
#define COLS 60

char canvas[ROWS][COLS];

/* Function Declarations */

void initCanvas();
void displayCanvas();
void drawPoint(int x, int y, char ch);
void drawRectangle(int x, int y, int height, int width);
void drawLine(int x1, int y1, int x2, int y2);
void drawTriangle(int x, int y, int height);
void drawCircle(int xc, int yc, int r);
void deleteArea(int x1, int y1, int x2, int y2);

/* Main Function */

int main()
{
    int choice;

    initCanvas();

    while(1)
    {
        printf("\n===== 2D GRAPHICS EDITOR =====\n");
        printf("1. Draw Rectangle\n");
        printf("2. Draw Line\n");
        printf("3. Draw Triangle\n");
        printf("4. Draw Circle\n");
        printf("5. Delete Area\n");
        printf("6. Display Canvas\n");
        printf("7. Clear Canvas\n");
        printf("8. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                int x, y, h, w;

                printf("Enter x y height width: ");
                scanf("%d%d%d%d", &x, &y, &h, &w);

                drawRectangle(x, y, h, w);
                break;
            }

            case 2:
            {
                int x1, y1, x2, y2;

                printf("Enter x1 y1 x2 y2: ");
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

                drawLine(x1, y1, x2, y2);
                break;
            }

            case 3:
            {
                int x, y, h;

                printf("Enter top x y and height: ");
                scanf("%d%d%d", &x, &y, &h);

                drawTriangle(x, y, h);
                break;
            }

            case 4:
            {
                int xc, yc, r;

                printf("Enter center x y and radius: ");
                scanf("%d%d%d", &xc, &yc, &r);

                drawCircle(xc, yc, r);
                break;
            }

            case 5:
            {
                int x1, y1, x2, y2;

                printf("Enter delete area x1 y1 x2 y2: ");
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

                deleteArea(x1, y1, x2, y2);
                break;
            }

            case 6:
                displayCanvas();
                break;

            case 7:
                initCanvas();
                printf("Canvas Cleared!\n");
                break;

            case 8:
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}

/* Function Definitions */

/* Initialize Canvas */
void initCanvas()
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            canvas[i][j] = '_';
        }
    }
}

/* Display Canvas */
void displayCanvas()
{
    printf("\n");

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("%c", canvas[i][j]);
        }

        printf("\n");
    }
}

/* Draw Single Point */
void drawPoint(int x, int y, char ch)
{
    if(x >= 0 && x < ROWS && y >= 0 && y < COLS)
    {
        canvas[x][y] = ch;
    }
}

/* Draw Rectangle */
void drawRectangle(int x, int y, int height, int width)
{
    for(int i = x; i < x + height; i++)
    {
        for(int j = y; j < y + width; j++)
        {
            drawPoint(i, j, '*');
        }
    }
}

/* Draw Line */
void drawLine(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;

    float x = x1;
    float y = y1;

    for(int i = 0; i <= steps; i++)
    {
        drawPoint(round(x), round(y), '*');

        x += xInc;
        y += yInc;
    }
}

/* Draw Triangle */
void drawTriangle(int x, int y, int height)
{
    for(int i = 0; i < height; i++)
    {
        for(int j = -i; j <= i; j++)
        {
            drawPoint(x + i, y + j, '*');
        }
    }
}

/* Draw Circle */
void drawCircle(int xc, int yc, int r)
{
    for(int angle=0;angle<360;angle++)
    {
        float rad=angle*3.14159/180;
        int x = xc + r*cos(rad);
        int y = yc + r*sin(rad);
        drawPoint(x, y, '*');
    }
}
/* Delete Area */
void deleteArea(int x1, int y1, int x2, int y2)
{
    for(int i=x1; i<=x2; i++)
    {
        for(int j=y1; j<=y2; j++)
        {
            drawPoint(i,j,'_');
        }
    }
}
    
