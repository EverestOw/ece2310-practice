/*
*   Add header info
*/

/*
*   @brief returns whether x is greater than y
*   
*   @param x : (double)
*   @param y : (int)
*   @return true: x is greater than y
*/
#include <cstdio>

bool isGreaterThan(double x, double y)
{
    return x > y;
}

int main() 
{
    double x = 33;
    int y = 7;

    if(isGreaterThan(x, y))
    {
        printf("%f > %i", x, y);
    }
    else
    {
        printf("%f <= %i", x,y);
    }

    return 0;
}