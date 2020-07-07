#include <stdio.h>
#include <math.h>
int count=0,x[100];

int place(int k,int i) { // checks whether kth queen can be placed in ith column
    int j;
    for(j=1;j<k;j++) // x[j]=i means same column, (x[j]-j) =( j-k) means same diagonal
        if((x[j]==i) ||(abs(x[j]-i)==abs(j-k)))
            return 0; // kth queen cannot be placed in ith column
    return 1;
}
void nqueen(int k,int n) {
    int i,j,p;
    for(i=1;i<=n;i++)
    if(place(k,i)) // if kth queen can be placed in ith column
    {
    x[k]=i; // place kth Queen in ith column
    if(k==n) // if all queens are placed then we print the solution matrix
    {
    count++;
    for(j=1;j<=n;j++)
    {
    for(p=1;p<=n;p++)
    if(x[j]==p) printf("q");
    else printf(" 0 ");
    printf("\n");
    }
    }
    else
    nqueen(k+1,n);
    }
    printf("\n"); 
}

int main(void) {
    int n;
    // printf("\t\t\tN QUEEN'S PROBLEM\n");
    printf("\nEnter the number of queens:");
    scanf("%d",&n);
    nqueen(1,n);
    if(count==0)
        printf("\n There is no solution for '%d - Queens' problem",n);
    else
        printf("Total number of solutions :%d",count);

    return 0;
}