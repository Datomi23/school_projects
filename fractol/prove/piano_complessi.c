#include <stdio.h>

typedef struct s_complessi 
{
    double real;
    double imgnry;
}t_complessi;


int main()
{
    t_complessi z;
    t_complessi c;
    int i;
    double tmp_real;

    z.real = 0;
    z.imgnry = 0;
    c.real = 0.25;
    c.imgnry = 0.4;
    i = 0;

    while (i < 42)
    {
        tmp_real = (z.real * z.real) - (z.imgnry * z.imgnry);
        z.imgnry = 2 * z.real * z.imgnry;
        z.real = tmp_real;
        z.real += c.real;
        z.imgnry += c.imgnry;
        printf("iterazione nr-> %d: reale %f, immaginario %f\n", i, z.real, z.imgnry);
        i++;
    }

}

//f(z) = z^2 + c