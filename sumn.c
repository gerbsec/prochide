#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int get_process_name(char *pid, char *buffer)
{
    long length;
    if (strspn(pid, "0123456789") != strlen(pid))
    {
        return 0;
    }

    char tmp[255];
    snprintf(tmp, sizeof(tmp), "/proc/%s/cmdline", pid);
    FILE *f = fopen(tmp, "rb");
    puts(tmp);
    if (f)
    {
        fscanf(tmp, sizeof(buffer), buffer);
    }
    if (buffer){
        printf("%s", buffer);
    }
    return 0;
}

int main()
{
    char process_name[1000];
    get_process_name("3430", process_name);
    puts(process_name);
    return 0;
}
