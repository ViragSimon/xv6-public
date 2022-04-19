#include "types.h"
#include "user.h"
#include "mmu.h"



void
munprotect_test(void){
    uint* p;
    p = malloc(5*PGSIZE);
    *p = 1;
    printf(1,"Wrote to memory\n");
    printf(1,"Protect memory\n");
    mprotect(p, 5);
    printf(1,"Unprotect memory\n");
    munprotect(p, 5);
    printf(1,"Try to write to unprotected memory\n");
    *p = 2;
    printf(1,"Wrote to memory\n");

}


int
main(int argc, char *argv[])
{
    munprotect_test();
    exit();
}
