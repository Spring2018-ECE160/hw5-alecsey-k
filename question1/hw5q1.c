#include <stdio.h>
#include <ctype.h>

int getch();
void ungetch(int);
int getfloat(double *pn);

#define BUFSIZE 100

char buf[BUFSIZE];  // buffer for ungetch
int bufp = 0;       // next free position in buf

int getch(void) // get a (possibly pushed back) character
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) // push character back on input
{
    if (bufp >= BUFSIZE)
        printf("ungetch:too many characters\n");
    else
        buf[bufp++] = c;
}

int getfloat(double *pn)
{
    int c, sign, temp;
    int pow = 1;

    while (isspace(c = getch())) // skip white space
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
    {
        ungetch(c); // it's not a number
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        temp = getch();
        if (isdigit(temp))
            c = temp;
        else
        {
            ungetch(temp);
            return 0;
        }
    }

    for (*pn = 0.0; isdigit(c); c = getch())
        *pn = 10.0 * *pn + (c - '0');

    if (c == '.')
        c = getch();

    for ( ; isdigit(c); c = getch())
    {
        pow *= 10.0;
        *pn = 10.0 * *pn + (c - '0');
    }

    *pn = *pn * sign / pow;

    if (c != EOF)
        ungetch(c);

    return c;
}

int main()
{
    int c1, c2, c3;
    double pn1, pn2, pn3;

    c1 = getfloat(&pn1);
    c2 = getfloat(&pn2);
    c3 = getfloat(&pn3);

    printf("c1 = %d, pn1 = %f\n", c1, pn1);
    printf("c2 = %d, pn2 = %f\n", c2, pn2);
    printf("c3 = %d, pn3 = %f\n", c3, pn3);

    return 0;
}
