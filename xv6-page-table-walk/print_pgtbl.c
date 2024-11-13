#include "types.h"
#include "user.h"

int func1(int);
int func2(int);

char d1 = 'a';
int d2[1000];
int d3;
int d4[1000] = {0};

static const int ronly[100] = {3};

#ifdef PRINT_PGTBL
void show_va2pa(void *, char *, char *);

void
show_va2pa(void *va, char *var, char *seg)
{
    int pa = 0;

    pa = va2pa((int) va);
	// I could check the size of va to determine if I should use 2 tabs or
	// just a single tab.
    printf(1, " %p  \t\t  %x  %x\t%s -> %s segment\n"
           , va
           , pa
           , pa & (~0xfff) // strip out the low order 3 bytes.
           , var
           , seg
        );
}
#endif // PRINT_PGTBL

int
func1(int a)
{
    return a + 1;
}

//#define BIGM
//#define BIGBIGM

int
main(int argc, char *argv[])
{
#ifdef PRINT_PGTBL
    int s1[100] = {0};
    char *h1 = 0x0;
    char *h2 = 0x0;
    char *h3 = 0x0;
    char *h4 = 0x0;
    char *h5 = 0x0;
    char *h6 = 0x0;
    int verbose = 0;

    if (argc > 1) {
        verbose = atoi(argv[1]);
    }
    print_pgtbl(verbose);

    h1 = malloc(10);
    h2 = malloc(513);
    h3 = malloc(10000);
    h4 = malloc(100000);

	if (argc > 2) {
		h5 = malloc(1000000);
	}
	if (argc > 3) {
		h6 = malloc(10000000);
	}

    print_pgtbl(verbose);

	s1[0] = func2(ronly[0]);
    s1[1] = func1(s1[0]);

	memset(s1, 1, 400);

	memset(h1, 2, 10);
    memset(h2, 2, 10);
	memset(h3, 3, 1000);
    memset(h4, 3, 10000);
	
	memset(d2, 1, 4000);
	
	if (argc > 2) {
		memset(h5, 1, 1000000);
	}
	if (argc > 3) {
		memset(h6, 2, 10000000);
	}

    print_pgtbl(verbose);
	
    printf(1, "\nvirtual addr\t  phy addr  pg addr\tsegment\n");

    show_va2pa(main, "main", "code");
    show_va2pa(func1, "func1", "code");
    show_va2pa(func2, "func2", "code");
	show_va2pa(write, "write", "code");
    show_va2pa(malloc, "malloc", "code");

    show_va2pa(&ronly, "ronly", "data");

    show_va2pa(&d1, "d1", "data");
    show_va2pa(d4, "d4", "data");

    show_va2pa(&d3, "d3", "data");
	show_va2pa(d2, "d2", "data");

    show_va2pa(s1, "s1", "stack");

	show_va2pa(h3, "h3", "heap");
	show_va2pa(h2, "h2", "heap");
    show_va2pa(h1, "h1", "heap");

    show_va2pa(h4, "h4", "heap");

	if (argc > 2) {
		show_va2pa(h5, "h5", "heap");
	}
	if (argc > 3) {
		show_va2pa(h6, "h6", "heap");
	}
#endif // PRINT_PGTBL
    
    exit();
}

int
func2(int a)
{
    return a + 2;
}
