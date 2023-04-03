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

int vector_size(Vector *v){
    return v->size;
}

data_type vector_get(Vector *v, int index){
    return v->data[index];
}

void vector_set(Vector *v, int i, data_type val){
    v->data[i] = val;
}

int vector_find(Vector *v, data_type val){
    for(int i = 0; i < v->size; i++){
        if(v->data[i] == val){
            return i;
        }
    }
    return -1;
}

data_type vector_remove(Vector *v, int idx){
    data_type val = v->data[idx];
    for(int i = idx; i < v->size - 1; i++){ 
        v->data[i] = v->data[i+1]; //remove o i-esimo valor, reescrevendo os demais
    }
    v->size--;
    return val;
}
data_type vector_pop_front(Vector *v){
    return vector_remove(v, 0);
}

data_type vector_pop_back(Vector *v){
    return vector_remove(v, v->size - 1);
}
void vector_insert(Vector *v, int i, data_type val){
    if(v->size == v->allocated){
        v->allocated *= 2;
        v->data = (data_type*)realloc(v->data, v->allocated * sizeof(data_type));
    }
    for(int j = v->size; j > i; j--){
        v->data[j] = v->data[j-1];
    }
    v->data[i] = val;
    v->size++;
}

void vector_swap(Vector *v, int i, int j){
    data_type aux = v->data[i];
    v->data[i] = v->data[j];
    v->data[j] = aux;
}

void vector_sort(Vector *v){
    for(int i = 0; i < v->size; i++){
        for(int j = 0; j < v->size - 1; j++){
            if(v->data[j] > v->data[j+1]){
                vector_swap(v, j, j+1);
            }
        }
    }
}

int vector_binary_search(Vector *v, data_type val){
    int left = 0;
    int right = v->size - 1;
    int mid;
    while(left <= right){
        mid = (left + right) / 2;
        if(v->data[mid] == val){
            return mid;
        }
        else if(v->data[mid] < val){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return -1;
}

void vector_reverse(Vector *v){
    for(int i = 0; i < v->size / 2; i++){
        vector_swap(v, i, v->size - 1 - i);
    }
}