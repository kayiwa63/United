#include <stdio.h>

int main(int argc, char **argv){
    FILE *fptr;

    //open file

    fptr = fopen("glad.text","w");

    //print to the file
    //fprintf(fptr,"argc:%d\n",argc);
    for (int i=0; i<argc; i++){
        fprintf(fptr,"arg %d: \"%s\"\n",i,argv[i]);
    }

    fclose(fptr);
    return 0;

}