#include "types.h"
#include "user.h"
#include "mmu.h"

int
main(int argc, char *argv[])
{
    uint* p;
    p = malloc(5*PGSIZE);
    printf(1,"Write to memory\n");
    *p = 3;
    printf(1, "The value of p[0] = %d\n", p[0]);
    printf(1,"Protect pages\n");
    mprotect(p, 5);
    printf(1,"Read from protected pages\n");
    printf(1, "The value of p[0] = %d\n", p[0]);
    printf(1,"Unprotect previously protected pages\n");
    munprotect(p, 5);
    printf(1,"Read from unprotected pages\n");
    printf(1, "The value of p[0] = %d\n", p[0]);
    printf(1,"Try to write to unprotected pages\n");
    *p = 2;
    printf(1,"Wrote to unprotected page\n");
    printf(1, "The new value of p[0] = %d\n", p[0]);
    exit();
}
