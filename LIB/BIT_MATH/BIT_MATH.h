#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(VAR , BIT_NO)   	 		VAR = VAR | ( 1 << BIT_NO )
#define CLR_BIT(VAR , BIT_NO)   	 		VAR = VAR & ( ~ ( 1 << BIT_NO ) )
#define TOG_BIT(VAR , BIT_NO)   			VAR = VAR ^ ( 1 << BIT_NO )
#define GET_BIT(VAR , BIT_NO)   	 		((VAR >> BIT_NO) & 1)

#define SET_REG(VAR)				VAR = 0xFF
#define CLR_REG(VAR)				VAR = 0x00

#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)			CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)		0b##b7##b6##b5##b4##b3##b2##b1##b0
#endif
