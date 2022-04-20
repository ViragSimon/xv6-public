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
    printf(1,"Protect pages\n");
    mprotect(p, 5);
    printf(1,"Read from protected pages\n");
    printf(1, "The value p[0] = %d\n", p[0]);
    printf(1,"Try to write to protected pages (expecting trap)\n");
    *p = 2;
    printf(1,"This should not be printed\n");
    exit();
}
