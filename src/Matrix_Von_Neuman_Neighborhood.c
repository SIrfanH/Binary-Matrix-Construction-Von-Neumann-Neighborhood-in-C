#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, **matrix;
    int boyut;          // used for storing size of the matrix that is needed
    int center;         // for storing the center of the matrix
    int blackCell;      // stores number of black cells which is calculated
    printf("Enter the value of N\n");
    scanf("%d",&N);

    blackCell = 2*N*(N+1)+1;    // number of black cells
    boyut = (2*N+1)+2;          // needed matrix length,    turning point of odd numbers + 2 new row and column

    matrix = (int**)malloc(boyut* sizeof(int *));   // allocation
    for(int i=0;i<boyut;i++)
    {
        matrix[i] = (int*)malloc(boyut*sizeof(int));
    }

    for(int i=0;i<boyut;i++)    // zeroing out all elements
    {
        for(int j=0; j<boyut;j++)
        {
            matrix[i][j] = 0;
        }
    }

    center = boyut/2;       // center of the matrix
    for(int i=1;i<boyut-1;i++)
    {
        for(int j=1;j<boyut-1;j++)
        {
            if((abs(i-center)+abs(j-center))<= N)
            {
                matrix[i][j]++;     // making correspoding elements 1 representing black cells
            }
        }
    }
    int count = 0;          // for counting number of black cells in every row
    for(int i=0;i<boyut;i++)
    {
        for(int j=0; j<boyut;j++)
        {
            printf("%d  ",matrix[i][j]);    // printing the array
            if(matrix[i][j] == 1)
            {
                count++;
            }
        }
        printf("    Number of Black Cell in this Row is %d\n", count);
        count = 0;
    }
    printf("Total number of Black Cells is %d\n",blackCell);

    return 0;
}
