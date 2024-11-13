#include "types.h"
#include "user.h"

int
main(int argc, char *argv[])
{
#ifdef PSX
	psx();
#endif // PSX
	
	exit();
}
