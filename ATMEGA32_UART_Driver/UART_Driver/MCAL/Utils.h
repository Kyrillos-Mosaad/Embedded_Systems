#ifndef Utils_h
#define Utils_h

#define SetBit(REG,BIT)		(REG = REG | (1<<BIT))
#define CLEARBIT(REG,BIT) 	(REG = REG & (~(1<<BIT)))
#define READBIT(REG,BIT)	(REG = (REG>>BIT)&1)
#define toggle (REG,BIT)	(REG = REG ^ (1<<BIT))

#endif
