#define max(A, B) ((A) > (B) ? (A) : (B))
#define square(x) x * x
#undef getchar // delete func from this file
#define dprint(expr) printf(#expr " = %g\n", expr)
// dprint(x\y)
#define paste(front, back) front ## back // ## concatenation in one string

#if !defined(HDR)
#define HDR
#endif

#if SYSTEM == SYSV
	#define HDR "sysv.h"
#elif SYSTEM == BSD
	#define HDR "bsd.h"
#elif SYSTEM == MSDOS
	#define HDR "msdos.h" 
#else
	#define HDR "default.h"
#endif

#include HDR