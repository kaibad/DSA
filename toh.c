#include <stdio.h>
void TOH(int n, char S, char T, char A)
{
    if (n == 1)
    {
        printf("\n Move disk %d from peg %c to peg %c", n, S, T);
    }
    else
    {
        TOH(n - 1, S, A, T);
        printf("\n Move disk %d from peg %c to peg %c", n, S, T);
        TOH(n - 1, A, T, S);
    }
}
int main()
{
    int n;
    printf("Enter no of disk:");
    scanf("%d", &n);
    TOH(n, 'S', 'T', 'A');
    return 0;
}
