#include <stdio.h>
#include <stdarg.h>

enum drink { MUDSLIDE, FUZZY_NAVEL, MONKEY_GLAND, ZOMBIE };
double price(enum drink d)
{
    switch (d) {
        case MUDSLIDE:
            return 6.79;
        case FUZZY_NAVEL:
            return 5.31;
        case MONKEY_GLAND:
            return 4.82;
        case ZOMBIE:
            return 5.89;
    }
    return 0;
}

// 少なくとも1つは固定引数が必要
double total(int args, ...)
{
    double total = 0;
    va_list ap;
    va_start(ap, args);
    int i;
    for (i = 0; i < args; i++) {
        //第二引数は可変引数の型
        enum drink d = va_arg(ap, enum drink);
        total += price(d);
    }
    va_end(ap);
    return total;
}

void print_ints(int dummy, int args, ...)
{
    va_list ap;
    va_start(ap, args);
    int i;
    for (i = 0; i < args; i++) {
        printf("argument: %i\n", va_arg(ap, int));
    }
    va_end(ap);
}

int main()
{
    printf("Price is %.2f\n", total(2, MONKEY_GLAND, MUDSLIDE));
    printf("Price is %.2f\n", total(3, MONKEY_GLAND, MUDSLIDE, FUZZY_NAVEL));
    printf("Price is %.2f\n", total(1, ZOMBIE));
    print_ints(1,4,3,4,5,6);
    return 0;
}
