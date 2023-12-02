#include <stdio.h>
int HCF(int x, int y)
{
    if (y == 0)
        return x;
    else
        return (HCF(y, x % y));
}
int main()
{
    int x, y, g;
    printf("Enter the value of x and y:");
    scanf("%d%d", &x, &y);
    g = HCF(x, y);
    printf("\n Value of HCF (%d , %d)=%d", x, y, g);
    return 0;
}
