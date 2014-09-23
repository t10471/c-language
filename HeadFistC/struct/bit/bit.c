#include <stdio.h>

typedef struct {
    unsigned int first_visit : 1;
    unsigned int come_again : 1;
    unsigned int fingers_lost : 4;
    unsigned int shark_attack : 1;
    unsigned int days_a_week : 3;
} survey;

typedef struct {
    unsigned int first_visit;
    unsigned int come_again;
    unsigned int fingers_lost;
    unsigned int shark_attack;
    unsigned int days_a_week;
} survey2;

int main()
{
    survey s = {1, 0, 4, 1, 3};
    //4バイト
    printf("%d, %d, %d, %d, %d sizeof %lu\n", s.first_visit, s.come_again,
           s.fingers_lost, s.shark_attack, s.days_a_week, sizeof s);
    survey2 s2 = {1, 0, 4, 1, 3};
    //20バイト
    printf("%d, %d, %d, %d, %d sizeof %lu\n", s2.first_visit, s2.come_again,
           s2.fingers_lost, s2.shark_attack, s2.days_a_week, sizeof s2);
}
