// See LICENSE for license details.

#ifndef __ENCODING_H__
#define __ENCODING_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* symbolic CSR names: */
#define CSR_CYCLE		0xc00
#define CSR_TIME		0xc01
#define CSR_INSTRET		0xc02
#define CSR_HPMCOUNTER3		0xc03
#define CSR_HPMCOUNTER4		0xc04
#define CSR_HPMCOUNTER5		0xc05
#define CSR_HPMCOUNTER6		0xc06
#define CSR_HPMCOUNTER7		0xc07
#define CSR_HPMCOUNTER8		0xc08
#define CSR_HPMCOUNTER9		0xc09
#define CSR_HPMCOUNTER10	0xc0a
#define CSR_HPMCOUNTER11	0xc0b
#define CSR_HPMCOUNTER12	0xc0c
#define CSR_HPMCOUNTER13	0xc0d
#define CSR_HPMCOUNTER14	0xc0e
#define CSR_HPMCOUNTER15	0xc0f
#define CSR_HPMCOUNTER16	0xc10
#define CSR_HPMCOUNTER17	0xc11
#define CSR_HPMCOUNTER18	0xc12
#define CSR_HPMCOUNTER19	0xc13
#define CSR_HPMCOUNTER20	0xc14
#define CSR_HPMCOUNTER21	0xc15
#define CSR_HPMCOUNTER22	0xc16
#define CSR_HPMCOUNTER23	0xc17
#define CSR_HPMCOUNTER24	0xc18
#define CSR_HPMCOUNTER25	0xc19
#define CSR_HPMCOUNTER26	0xc1a
#define CSR_HPMCOUNTER27	0xc1b
#define CSR_HPMCOUNTER28	0xc1c
#define CSR_HPMCOUNTER29	0xc1d
#define CSR_HPMCOUNTER30	0xc1e
#define CSR_HPMCOUNTER31	0xc1f
#define CSR_CYCLEH		0xc80
#define CSR_TIMEH		0xc81
#define CSR_INSTRETH		0xc82
#define CSR_HPMCOUNTER3H	0xc83
#define CSR_HPMCOUNTER4H	0xc84
#define CSR_HPMCOUNTER5H	0xc85
#define CSR_HPMCOUNTER6H	0xc86
#define CSR_HPMCOUNTER7H	0xc87
#define CSR_HPMCOUNTER8H	0xc88
#define CSR_HPMCOUNTER9H	0xc89
#define CSR_HPMCOUNTER10H	0xc8a
#define CSR_HPMCOUNTER11H	0xc8b
#define CSR_HPMCOUNTER12H	0xc8c
#define CSR_HPMCOUNTER13H	0xc8d
#define CSR_HPMCOUNTER14H	0xc8e
#define CSR_HPMCOUNTER15H	0xc8f
#define CSR_HPMCOUNTER16H	0xc90
#define CSR_HPMCOUNTER17H	0xc91
#define CSR_HPMCOUNTER18H	0xc92
#define CSR_HPMCOUNTER19H	0xc93
#define CSR_HPMCOUNTER20H	0xc94
#define CSR_HPMCOUNTER21H	0xc95
#define CSR_HPMCOUNTER22H	0xc96
#define CSR_HPMCOUNTER23H	0xc97
#define CSR_HPMCOUNTER24H	0xc98
#define CSR_HPMCOUNTER25H	0xc99
#define CSR_HPMCOUNTER26H	0xc9a
#define CSR_HPMCOUNTER27H	0xc9b
#define CSR_HPMCOUNTER28H	0xc9c
#define CSR_HPMCOUNTER29H	0xc9d
#define CSR_HPMCOUNTER30H	0xc9e
#define CSR_HPMCOUNTER31H	0xc9f

#define __ASM_STR(x)		#x

#define csr_read(csr)						\
({								\
	register unsigned long __v;				\
	__asm__ __volatile__ ("csrr %0, " __ASM_STR(csr)	\
			      : "=r" (__v) :			\
			      : "memory");			\
	__v;							\
})

#define csr_write(csr, val)					\
({								\
	unsigned long __v = (unsigned long)(val);		\
	__asm__ __volatile__ ("csrw " __ASM_STR(csr) ", %0"	\
			      : : "rK" (__v)			\
			      : "memory");			\
})

#ifdef __cplusplus
}
#endif

#endif
