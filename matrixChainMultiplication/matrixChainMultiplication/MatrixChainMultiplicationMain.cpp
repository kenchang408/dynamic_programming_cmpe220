#include<stdio.h>
#include<limits.h>

using namespace std;

int MatrixChainOrder(int p[], int n);

// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
int main()
{
    int arr[] = {10, 100, 20, 50, 100, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
 
    printf("\n Minimum number of multiplications is %d ", MatrixChainOrder(arr, size));
 
    getchar();
    return 0;
}

int MatrixChainOrder(int p[], int n)
{
 
     // 0th row and 0th column of m[][] are not used 
	int m[500][500];
	
	
    int i, j, k, L, q;
 
    /* m[i,j] = Min number of scalar multiplications needed to compute
       the matrix A[i]A[i+1]...A[j] = A[i..j] where dimention of A[i] is p[i-1] x p[i] */
 
    // multiplying one matrix yields cost of 0.
    for (i = 1; i < n; i++)
        m[i][i] = 0;
 
    // L is chain length.  
    for (L=2; L<n; L++)   // for 2 or higher
    {
		int skip = 0;// 1 to skip output
		printf("\n For L = %d \n\n", L);

		
        for (i=1; i<=n-L+1; i++)
        {

			int alternative = 0;
            j = i+L-1;
            m[i][j] = INT_MAX; // set max value to m[i][j]
            for (k=i; k <= (j-1); k++)
            {
	
		for(int count=i; count<=j; count++)
				{   
					if(j<=n-1)
					{
					if(count==i)
					{
						 if(i == k)
							printf("(A%u)", count);
						 else
							printf("(A%u", count);
					}
					else if (count==j)
					{
						if(count == k+1)
							printf("(A%u)   =>   ", count);
						else
							printf("A%u)   =>   ", count);
					}
					else if (count==k)
						printf("A%u)", count);
					else if (count==k+1)
						printf("(A%u", count);
					else 
						printf("A%u", count);
					}
				}
			

		
                // q = cost/scalar multiplications
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				//printf("j = %d \n\n", j);
				//printf("p[i-1] = %u, p[k]= %u, p[j] = %u \n\n", p[i-1], p[k], p[j]);
				//printf(" q = m[%u][%u] + m[%u+1][%u] + p[%u-1]*p[%u]*p[%u] = %u \n", i, k, k, j, i, k, j, q);
                
				if(j<=n-1)
				{
					if (q > m[i][j] && (alternative>0))
						printf("k = %u: m[%d, %d] with cost %u\t\tX\n", k, i, j, q);
					else
						printf("k = %u: m[%d, %d] with cost %u\t\tO\n", k, i, j, q);
				
				}

				if (q < m[i][j])
                    m[i][j] = q;

				
				alternative ++;
            }
			
        }
    }

    return m[1][n-1];
}