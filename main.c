#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Show(int **matrix, int rows, int cols)
{
    int i,j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
            printf("\t");
        }
        printf("\n");
    }
}

int ** memoryAllocation(int rows, int cols)
{
    int i = 0;
    int **matrix = (int **)malloc(rows*sizeof(int *));
    for( i = 0; i < rows; i++)
    {
      matrix[i] = (int *)malloc(cols*sizeof(int));
    }
    return matrix;
}
int ** matrixInit(int **matrix, int rows, int cols)
{
    int i,j,x = 0;

    for( i = 0; i < rows; i++)
    {
        for( j = 0; j < cols; j++)
        {
            matrix[i][j] = x;
            x += 1;
        }
    }
    return matrix;
}
int ** userMatrixInit(int **matrix, int rows, int cols)
{
    int i,j,x;
    printf("Number of rows = %d\n",rows);
    printf("Number of columns = %d\n",cols);
    for( i = 0; i < rows; i++)
    {
        for( j = 0; j < cols; j++)
        {
            printf("Element [%d][%d] = ",i+1,j+1);
            scanf("%d",&x);
            matrix[i][j] = x;
            printf("\n");
        }
    }
    return matrix;
}

void sumRowsAndCols(int **matrixA, int rowsA, int colsA,int **matrixB, int rowsB, int colsB)
{
    int i,j,x;
    printf("Sum rows A: \n");
    for( i = 0; i < rowsA; i++)
    {
        x = 0;
        for( j = 0; j < colsA; j++)
        {
            x+=matrixA[i][j];
        }
        printf("Row [%d] = %d \n",i+1,x);
    }
    printf("Sum cols B: \n");
    for( i = 0; i < colsB; i++)
    {
        x = 0;
        for( j = 0; j < rowsB; j++)
        {
            x+=matrixB[j][i];
        }
        printf("Col [%d] = %d \n",i+1,x);
    }
}
int Max(int **matrix, int rows, int cols)
{
    int i,j,max;
    max = matrix[0][0];
    for( i = 0; i < rows; i++)
    {
        for( j = 0; j < cols; j++)
        {
            if(max<matrix[i][j])
            {
               max = matrix[i][j];
            }
        }
    }
    return max;
}
int Min(int **matrix, int rows, int cols)
{
    int i,j,min;
    min = matrix[0][0];
    for(i  = 0; i<rows; i++)
    {
        for(j = 0; j<i; j++)
        {
            if(matrix[i][j]<min)
            {
                min = matrix[i][j];
            }
        }
    }
    return min;
}
void matrixTransposed(int **matrix, int rows, int cols)
{
    int i = 0,j = 0;
    for (i = 0; i < cols; i++)
    {
        for (j = 0; j < rows; j++)
        {
           printf("%d ",matrix[j][i]);
           printf("\t");
        }
        printf("\n");
    }
}
void matrixMultiplication(int **matrixA, int rowsA, int colsA,int **matrixB, int rowsB, int colsB)
{
    int i,j,k,S;
    if(rowsA !=rowsB)
    {
        printf("Unable to find the product\n");
    }
    else
    {
        printf("Multiplication matrix A and B (A x B) : \n");
        for(i = 0;i<rowsA;i++)
        {
          for(j = 0;j<colsB;j++)
          {
             S = 0;
             for(k=0; k < rowsB; k++)
             {
                 S+=matrixA[i][k]*matrixB[k][j];
             }
             printf("%d \t",S);
          }
          printf("\n");
        }
    }

}
void array()
{
    int length,i = 0,j,k;
    int *arr;
    printf("Enter the length of the one-dimensional array :");
    scanf("%d",&length);
    arr = (int *)malloc(length * sizeof(int));

    for (i = 0; i<length; i++)
    {
      printf("a[%d] = ",i+1);
      scanf("%d",&arr[i]);
    }
    printf("Standart: \n");
    for(i = 0;i<length;i++)
    {
      printf("%d ",arr[i]);
    }
    printf("\n");
    for(i = 0; i<length-1; i++)
    {
        for(j = 0; j<length-1; j++)
        {
          if(arr[j]<arr[j+1])
          {
            k=arr[j+1];
            arr[j+1] = arr[j];
            arr[j] = k;
          }
        }
    }
    printf("Max -> min: \n");
    for(i = 0;i<length;i++)
    {
      printf("%d ",arr[i]);
    }
    free(arr);
}

void clearMemory(int **matrix, int rows)
{
    int i;
    for(i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}
int main()
{
    int var,rowsA,colsA;
    int rowsB,colsB;

    printf("A = (N x N)\n");
    printf("N = ");
    scanf("%d",&rowsA);
    printf("\n");
    colsA = rowsA;
    printf("B = (N x M)\n");
    printf("N = ");
    scanf("%d",&rowsB);
    printf("\n");
    printf("M = ");
    scanf("%d",&colsB);
    printf("\n");


    int **A = memoryAllocation(rowsA,colsA);
    int **B = memoryAllocation(rowsB,colsB);

    printf("Do you want to initialize the matrix yourself? (1 - yes, any key - no)\n");
    scanf("%d",&var);
    if(var == 1)
    {
       printf("A : \n");
       A = userMatrixInit(A,rowsA,colsA);
       printf("B : \n");
       B = userMatrixInit(B,rowsB,colsB);
    }
    else
    {
       A = matrixInit(A,rowsA,colsA);
       B = matrixInit(B,rowsB,colsB);
    }
    printf("Matrix A: \n");
    Show(A,rowsA,colsA);
    printf("Matrix B: \n");
    Show(B,rowsB,colsB);

    printf("Max element in matrix A : %d",Max(A,rowsA,colsA));
    printf("\n");
    printf("Min element under main diagonal in matrix A : %d",Min(A,rowsA,colsA));
    printf("\n");

    printf("Transposed Matrix B: \n");
    matrixTransposed(B,rowsB,colsB);

    sumRowsAndCols(A,rowsA,colsA,B,rowsB,colsB);

    matrixMultiplication(A,rowsA,colsA,B,rowsB,colsB);

    array();

    clearMemory(A,rowsA);
    clearMemory(B,rowsB);
    return 0;
}
