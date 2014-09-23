#include <stdio.h>

typedef struct {
    const char* name;
    const char* species;
    int age;
} turtle;

typedef struct {
    const char* description;
    float value;
} swang;

typedef struct {
    swang* swang;
    const char* sequence;
} combination;

typedef struct {
    combination numbers;
    const char* make;
} safe;

void happy_birthday(turtle* t)
{
    // t->ageと一緒
    (*t).age = (*t).age + 1;
    printf("誕生日おめでとう、%s!これで%i才ですね!\n", (*t).name, (*t).age);
}

void turtle_age()
{
    turtle myrtle = {"マートル", "オサガメ", 99};
    happy_birthday(&myrtle);
    printf("%sの年齢は%i才です\n", myrtle.name, myrtle.age);
}

void bank()
{
    swang gold = {"GOLD!", 1000000.0};
    //ポインタとして定義されてる個所はポインタで渡す
    combination numbers = {&gold, "6502"};
    safe s = {numbers, "RAMACON250"};
    printf("中身 = %s\n", s.numbers.swang->description);
}

int main()
{
    turtle_age();
    bank();
    return 0;
}
