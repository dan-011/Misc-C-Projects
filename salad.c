#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char *argv[]){
	if(argc == 1) return 0;
	FILE** files = (FILE**)malloc(sizeof(FILE*)*(argc-1));
	for(int i = 1; i < argc; i++){
		files[i-1] = fopen(argv[i], "r");
	}
	int end = 0;
	int file_index = 0;
	while(!end){
		if(file_index == argc-1) file_index = 0;
		if(feof(files[file_index])){
			printf("\n");
			file_index++;
			continue;
		}
		int n_ch = fgetc(files[file_index]);
		char ch = (char)n_ch;
		if(n_ch != -1) printf("%c", ch);
		else printf("\n");
		if(ch == '\n' || n_ch == -1){
			file_index++;
		}
		int store = 1;
		for(int k = 0; k < argc-1; k++){
			if(!feof(files[k])){
				store = 0;
			}
		}
		if(store){
			end = 1;
		}
	}
	for(int i = 0; i < argc-1; i++){
		fclose(files[i]);
	}
	free(files);
	return 0;
}
