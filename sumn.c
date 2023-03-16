#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int get_process_name(char* pid, char* buffer)
{
    FILE    *f;
    long    numbytes;
    if(strspn(pid, "0123456789") != strlen(pid)) {
        return 0;
    }

    char tmp[255];
    snprintf(tmp, sizeof(tmp), "/proc/%s/cmdline", pid);
    f = fopen(tmp, "rb");
    if( f== NULL){
	    return 1;
    }
    fseek(f, 0L, SEEK_END);
    numbytes = ftell(f);
    fseek(f, 0L, SEEK_SET);

    buffer = (char*)calloc(numbytes, sizeof(char));
    if(buffer == NULL){
        return 1;
    }

    fread(buffer, sizeof(char), numbytes, f);
    fclose(f);

    printf(buffer);
    return 0;

}

int main(){
	char process_name[256];
	get_process_name("25195", process_name);
	puts(process_name);
	return 0;
}

