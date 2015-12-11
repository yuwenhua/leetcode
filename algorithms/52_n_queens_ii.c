/**
 * Follow up for N-Queens problem.
 * Now, instead outputting board configurations, return the total number of 
 * distinct solutions.
 * https://leetcode.com/problems/n-queens-ii/
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>

void print_board(int *a, int n)    //打印输出N皇后的一组解  
{  
    int i, j;  
#if 0
    for (i = 0; i < n; ++i)  
    {  
        for (j = 0; j < n; ++j)  
        {  
            if (a[i] != j)      //a[i]为初始值  
                printf("%c ", '.');  
            else                //a[i]表示在第i行的第a[i]列可以放置皇后  
                printf("%c ", '#');  
        }  
        printf("\n");  
    }
#endif
    for (i = 0; i < n; ++i)  
        printf("%d ", a[i]);  
    printf("\n");  
    //printf("--------------------------------\n");  
}
int can_place(int *array, int row, int col, int n)   
{
	int i;

	for (i = 0; i < n; ++i) {
		if (array[i] == col || (abs(i - row) == abs(array[i] - col)))  {
			return 0;
		}
	}  
//	printf("(%d, %d), a[%d] = %d", row, col,i, array[i]);
	return 1;  
}  



int totalNQueens(int n) 
{
	int sum = 0;
	int i = 0, j = 0;  
	int *a;  

	a = (int *)malloc(n*sizeof(int));
	for(i = 0; i < n;i ++) {
		a[i] = INT_MIN;
	}
	i = 0;
	j = 0;

	while (i < n) {  
		while (j < n) {  
			if(can_place(a, i, j,n))	{  
				a[i] = j; 
				j = 0;
				break;  
			}  
			else  {  
				j++;
			}  
		}  
		if(a[i] == INT_MIN){
			if (i == 0)
				break;
			else {  
				i--;
				j = a[i] + 1;
				a[i] = INT_MIN;
				continue;  
			}  
		}
		if (i == n - 1) {  
			sum++;
			print_board(a, n);

			j = a[i] + 1;
			a[i] = INT_MIN;
			continue;  
		}  
		i++;
	}
	return sum;
}

int main(int argc, char **argv) {
	//int i;
	int sum;

	sum = totalNQueens(38);
	printf("%d queens got %d solutions\n",8, sum);
	return 0;
}

