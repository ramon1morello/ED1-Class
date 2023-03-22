
#include <stdio.h>
#include <string.h>

#include "vector.h"

int main()
{
    Vector *v;

    v = vector_construct();

    for (int i = 1; i <= 25; i++)
        vector_push_back(v, i);

    for (int i = 0; i < v->size; i++)
        printf("%d\n", v->data[i]);

    vector_destroy(v);

    printf("OK!\n");

    return 0;
}
