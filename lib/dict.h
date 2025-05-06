#include <stdlib.h>

typedef struct{
    char key;
    int value;
} item;

typedef struct{
    item* data;
    int used;
    int size;
} Dict;

// allocate hashmap
Dict Dict_new(int size){
    item* data = (item*)malloc(sizeof(item)*size);
    Dict dt = {.data = data, .used = 0, .size = size};
    return dt;
}

// add new value to dictionary
int Dict_add(Dict* self, char key, int value){
    for(int ptr = 0; ptr < self->used; ptr+=1){
        if(self->data[ptr].key == key){
            return 0; // false if key exists
        }
    }

    if(self->used >= self->size-1){
        self->data = (item*)realloc(self->data, (size_t)self->size+10);
        self->size+=10;
    }
    self->data[self->used].key = key;
    self->data[self->used].value = value;
    self->used += 1;

    return 1; // true if key is new
}

// change value in dictionary
int Dict_set(Dict* self, char key, int value){
    for(int ptr = 0; ptr < self->used; ptr+=1){
        if(self->data[ptr].key == key){
            self->data[ptr].value = value;
            return 1;
        }
    }
    return 0;
}

int Dict_get(Dict* self, char key){
    for(int ptr = 0; ptr < self->used; ptr+=1){
        if(self->data[ptr].key == key){
            return self->data[ptr].value;
        }
    }
    return -999;
}

int Dict_iota(Dict* self, char key){
    if(Dict_get(self, key) != -999){
        Dict_set(self, key, Dict_get(self, key)+1);
    }else{
        Dict_add(self, key, 1);
    }
}

int Dict_getIdx(Dict* self, int idx){
    if(idx <= self->used){
        return self->data[idx].value;
    }else{
        return -999;
    }
}