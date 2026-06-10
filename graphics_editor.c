#include <stdio.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

void clearCanvas()
{
    int i, j;
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas()
{
    int i,j;

    printf("\n+");

    for(i=0;i<COLS;i++)
        printf("-");

    printf("+\n");

    for(i=0;i<ROWS;i++)
    {
        printf("|");

        for(j=0;j<COLS;j++)
        {
            printf("%c",canvas[i][j]);
        }

        printf("|\n");
    }

    printf("+");

    for(i=0;i<COLS;i++)
        printf("-");

    printf("+\n");
}

void drawRectangle(int row, int col, int height, int width)
{
    int i, j;
    for(i = row; i < row + height && i < ROWS; i++)
    {
        for(j = col; j < col + width && j < COLS; j++)
        {
            canvas[i][j] = '*';
        }
    }
}

void drawLine(int row1, int col1, int row2, int col2)
{
    int i;
    if(row1 == row2)
    {
        for(i = col1; i <= col2 && i < COLS; i++)
            canvas[row1][i] = '*';
    }
    else if(col1 == col2)
    {
        for(i = row1; i <= row2 && i < ROWS; i++)
            canvas[i][col1] = '*';
    }
}

void drawTriangle(int row, int col, int height)
{
    int i, j;
    for(i = 0; i < height; i++)
    {
        for(j = 0; j <= i; j++)
        {
            if(row + i < ROWS && col + j < COLS)
                canvas[row + i][col + j] = '*';
        }
    }
}

void drawCircle(int centerRow, int centerCol, int radius)
{
    int x, y;
    for(y = 0; y < ROWS; y++)
    {
        for(x = 0; x < COLS; x++)
        {
            int dx = x - centerCol;
            int dy = y - centerRow;

            if(dx * dx + dy * dy <= radius * radius)
            {
                canvas[y][x] = '*';
            }
        }
    }
}

int main()
{
    int choice;

    clearCanvas();

    do
    {
        printf("\n===== 2D GRAPHICS EDITOR =====\n");
        printf("1. Draw Rectangle\n");
        printf("2. Draw Line\n");
        printf("3. Draw Triangle\n");
        printf("4. Draw Circle\n");
        printf("5. Display Canvas\n");
        printf("6. Delete All Objects\n");
        printf("7. Modify Canvas\n");
        printf("8. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                int row, col, height, width;
                printf("Row: ");
                scanf("%d", &row);
                printf("Column: ");
                scanf("%d", &col);
                printf("Height: ");
                scanf("%d", &height);
                printf("Width: ");
                scanf("%d", &width);
                drawRectangle(row, col, height, width);
                break;
            }

            case 2:
            {
                int r1, c1, r2, c2;
                printf("Row1: ");
                scanf("%d", &r1);
                printf("Col1: ");
                scanf("%d", &c1);
                printf("Row2: ");
                scanf("%d", &r2);
                printf("Col2: ");
                scanf("%d", &c2);
                drawLine(r1, c1, r2, c2);
                break;
            }

            case 3:
            {
                int row, col, height;
                printf("Row: ");
                scanf("%d", &row);
                printf("Column: ");
                scanf("%d", &col);
                printf("Height: ");
                scanf("%d", &height);
                drawTriangle(row, col, height);
                break;
            }

            case 4:
            {
                int row, col, radius;
                printf("Center Row: ");
                scanf("%d", &row);
                printf("Center Column: ");
                scanf("%d", &col);
                printf("Radius: ");
                scanf("%d", &radius);
                drawCircle(row, col, radius);
                break;
            }

            case 5:
                displayCanvas();
                break;

            case 6:
                clearCanvas();
                printf("All Objects Deleted!\n");
                break;

            case 7:
            {
                int row, col, height, width;
                clearCanvas();
                printf("Modify by drawing a new rectangle\n");
                printf("Row: ");
                scanf("%d", &row);
                printf("Column: ");
                scanf("%d", &col);
                printf("Height: ");
                scanf("%d", &height);
                printf("Width: ");
                scanf("%d", &width);
                drawRectangle(row, col, height, width);
                printf("Canvas Modified!\n");
                break;
            }

            case 8:
                printf("Exiting...\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        } // Closes the switch statement
        
    } while(choice != 8); // Closes the do-while loop

    return 0;
} // Closes the main function