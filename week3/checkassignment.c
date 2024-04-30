#include<stdio.h>
#include<math.h>

/// I revised the code in the txt file and replaced the %lf with %f then add some parenthesis and blanks to where is necessarry.

int main(void)
{

    float x, variable, y;

    int i;

    for(i = 0; i <= 10; i++)
    {
        variable = i / 10.0;
        x = (sin(variable));
        y = cos((variable));
        printf("sine(%f)=%f\tcosine(%f)=%f\n", variable, x, variable, y);
    }


    return 0;
}