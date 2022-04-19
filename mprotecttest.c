#include "types.h"
#include "user.h"
#include "mmu.h"


int
main(int argc, char *argv[])
{
    uint* p;
    p = malloc(5*PGSIZE);
    *p = 1;
    printf(1,"Wrote to memory\n");
    mprotect(p, 5);
    printf(1,"Protected memory\n");
    printf(1,"Read from memory: %d\n", *p);
    printf(1,"Try to write to protected memory (expecting trap)\n");
    *p = 2;
    printf(1,"This should not be printed\n");
    exit();
}
