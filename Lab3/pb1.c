#include <stdio.h>

void f1(int *val);
void f2(int *val);
void f3(int val);
void f4(int val);


void f1(int *val) {
    (*val)++;
    printf("Numele functiei este: f1\n Valoarea variabilei: %d\nAdresa ei: %p\n",
           *val, val);
    f2(val);
}

void f2(int *val) {
    (*val)++;
    printf("Numele functiei este: f2\n Valoarea variabilei: %d\nAdresa ei: %p\n",
           *val, val);
    f3(*val);
}

void f3(int val) {
    val++;
    printf("Numele functiei este: f3\n Valoarea variabilei: %d\nAdresa ei: %p\n",
           val, &val);
    f4(val);
}

void f4(int val) {
    val++;
    printf("Numele functiei este: f4\n Valoarea variabilei: %d\nAdresa ei: %p\n",
           val, &val);
}

int main(void) {
    int val = 0;
    //scanf("%d", &val);
    printf("da\n");
    f1(&val);

    return 0;
}