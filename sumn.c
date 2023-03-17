#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int get_process_name(char *pid, char *buffer)
{
    memset(buffer, 0, sizeof(buffer));
    if (strspn(pid, "0123456789") != strlen(pid))
    {
        return 0;
    }
    char tmp[256];
    snprintf(tmp, sizeof(tmp), "/proc/%s/cmdline", pid);

    FILE *f = fopen(tmp, "rb");
    if (f == NULL)
    {
        return 0;
    }
    char *arg = 0;
    size_t size = 0;
    while (getdelim(&arg, &size, 0, f) != -1)
    {
        strcat(buffer, arg);
    }
    return 0;
}

int main()
{
    char process_name[1000];
    get_process_name("9181", process_name);
    puts(process_name);
    return 0;
}
