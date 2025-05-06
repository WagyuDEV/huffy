#include <stdio.h>
#include <stdlib.h>

#include "../lib/dict.h"

int main(int argc, char** argv){
	FILE* input = fopen("./resources/mochi.jpg", "r");

	int file_size = fseek(input, 0L, SEEK_END);

	Dict chars = Dict_new(100);

	for(int i = 0; i < file_size; i+=1){
		Dict_iota(&chars, getc(input));
	}

	for(int i = 0; i < chars.used; i+=1){
		// printf("%c | %d\n", );
	}
}