#define _DEFAULT_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>


int main(int argc, char ** argv)
{
    if(argc < 2){
        FILE* f = stdin;
        int num_lines = 0;
        char** lines = (char**)malloc(sizeof(char*));
        while(!feof(f)){
            num_lines++;
            lines = (char**)realloc(lines, sizeof(char*)*num_lines);
            lines[num_lines-1] = (char*)malloc(sizeof(char)*255);
            fgets(lines[num_lines-1], 255, f);
        }
        for(int i = num_lines - 2; i >= 0; i--){
        //for(int i = num_lines-1; i >= 0; i--){
            printf("%s", lines[i]);
        }
        for(int i = 0; i < num_lines; i++){
            free(lines[i]);
        }
        free(lines);
        return 0;
    }
    for(int i = 1; i < argc; i++){
        
        FILE* f = fopen(argv[i], "r");
        char* line = (char*)malloc(sizeof(char)*255);
        int pos = 253;
        int offset = -1;
        do{
            fseek(f, offset, SEEK_END);
            int n_ch = fgetc(f);
            char ch = (char)n_ch;
            if(n_ch >= 0){
                line[pos] = ch;
                line[254] = '\0';
            }
            if(ch == '\n' && pos+1 < 255){
                printf("%s", &line[pos+1]);
                pos = 253;
            }
            pos--;
            offset--;
        } while(ftell(f)!=1);
        printf("%s", &line[pos+1]);
        fclose(f);
        free(line);
    }
    return 0;
}
