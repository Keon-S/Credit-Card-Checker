#include <stdio.h>
#include <cs50.h>
#include <math.h>
long long a = 0;
long long b = 0;
long long c, d, e, temp;
long long f = 0;
long long length(long long n)
{
    if (n == 0)
    {
        return 0;
    }
    return floor( log10( llabs( n ) ) ) + 1;
}
long long lengtha(long long x)
{
    if (x >= 1000000000000000 && x < 10000000000000000)
    {
        return 16;
    }
    if (x >= 100000000000000)
    {
        return 15;
    }
    if (x >= 1000000000000 && x < 10000000000000)
    {
        return 13;
    }
    return 0;
}

int main(void)
{
    long long number = get_long_long("Number: ");
    unsigned int length = lengtha(number);
    if (length == 0)
    {
        printf("INVALID\n");
        return 0;
    }
    temp = number;
    for (unsigned int i = 2; i <= length; i += 2)
    {

        temp /= 10;
        c = temp % 10;
        c = c * 2;
        while (c > 0)
        {
            e = c % 10;
            f = f + e;
            c /= 10;
        }
        temp /= 10;
    }
    a += f;
    temp = number;
    c = 0;
    d = 0;
    while (temp > 0)
    {
        d = temp % 10;
        c = c + d;
        temp /= 10;
        temp /= 10;
    }
    a = a + c;
    if (a % 10 != 0 )
    {
        printf("INVALID\n");
        return 0;
    }
    if (length == 13)
    {
        printf("VISA\n");
        return 0;
    }
    else if (length == 15)
    {
        printf("AMEX\n");
        return 0;
    }
    else
    {
        int t = 15;
        while (t > 0)
        {
            number /= 10;
            t--;
        }
        if (number == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("MASTERCARD\n");
        }
    }
}
