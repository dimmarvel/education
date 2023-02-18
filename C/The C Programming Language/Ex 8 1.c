#include "syscalls.h"
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int fp;
    void filecopy(int ifp, int ofp);

    if (argc == 1) // no arguments, default stdin
        filecopy(0, 1);
    else
        while (--argc > 0)
            if ((fp = open(*++argv, 0_RDONLY)) == -1)
                error("cat: can`t open the file %s\n", *argv);
            else
            {
                filecopy(fp, 1);
                close(fp);
            }
    return 0;
}

void filecopy(int ifp, int ofp)
{
    int n;
    char buf[BUFSIZ];

    while ((n = read(ifp, buf, BUFSIZ)) > 0)
        if (write(ofp, buf, n) != n)
            error("cat:write error");
}