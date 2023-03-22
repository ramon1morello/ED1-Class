#include <stdlib.h>
#include "vector.h"


Vector *vector_construct(){
   
    Vector *vector = (Vector *)calloc(10, sizeof(Vector));
    vector -> data = (data_type*)calloc(10,sizeof(data_type));
    vector -> size = 0;
    vector -> allocated = 10;

return vector;
}

void vector_destroy(Vector *v){
    free(v-> data);
    free(v);
}

void vector_push_back(Vector *v, data_type val){
    if(v->size == v->allocated){
        v->allocated *= 2;
        v->data = (data_type*)realloc(v->data, v->allocated * sizeof(data_type));
    }
    v->data[v->size] = val;
    v->size++;
}
