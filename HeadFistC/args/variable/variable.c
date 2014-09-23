#include <stdio.h>
#include <stdlib.h>

/* 
:QuickRun -args "100 200" 
*/
float total = 0.0;
short count = 0;
short tax_percent = 6;

float add_with_tax(float f)
{
    float tax_rate = 1 + tax_percent / 100.0;
    total = total + (f * tax_rate);
    count = count + 1;
    return total;
}
int main(int argc, char* args[])
{
    float val;
    int i;
    printf("Price of item: ");
    for (i = 0; i < argc; i++) { 
        printf("Total so far: %.2f\n", add_with_tax(atof(args[i])));
        printf("Price of item: ");
    }
    //少数点以下2桁まで
    printf("\nFinal total: %.2f\n", total);
    //hiはshort用
    printf("Number of items: %hi\n", count);
    return 0;
}
