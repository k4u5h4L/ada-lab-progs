#include <stdio.h>

int main(void) {
    int n, i, j, a[10][10], s[10], d[10], v, k, min, u;

    printf("Enter the number of vertices\n");
    scanf("%d", &n);

    printf("Enter the cost matrix \n");
    printf("Enter 999 if no edge between vertices \n");

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    printf("Enter the source vertex \n");
    scanf("%d", &v);
    for (i = 1; i <= n; i++) 
        s[i] = 0;
        d[i] = a[v][i];
    
    d[v] = 0;
    s[v] = 1;
    for (k = 2; k <= n; k++) 
        min = 999;
        for(i=1;i<=n;i++) 
            if(s[i]==0 && d[i]<min) {
                min=d[i];
                u=i;
            }
            s[u] = 1;
            for (i = 1; i <= n; i++) 
                if (s[i] == 0) {
                    if(d[i] > (d[u] + a[u][i]))
                        d[i] = d[u] + a[u][i];
                }
            
        
    
    printf("The shortest distance from %d is \n",v);
    for(i=1;i<=n;i++)
        printf("%d --> %d = %d\n",v,i,d[i]);

    return 0;
}