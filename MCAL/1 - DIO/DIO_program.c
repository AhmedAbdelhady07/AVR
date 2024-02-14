/********************************************************************************************************************/
/*****************     Author 		: Ahmed Abdelhady 	*************************************************************/
/*****************     File 		: Program Of DIO  	*************************************************************/
/*****************     Date 		: 1/1/2023  		*************************************************************/
/*****************     Version 		: 1.0  				*************************************************************/
/*****************     Description 	: Drive For DIO 	*************************************************************/
/********************************************************************************************************************/

/* LIB Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL Layer */
#include 	"DIO_private.h"
#include 	"DIO_config.h"
#include 	"DIO_interface.h"

void DIO_voidInit						(void)
{
	DIO_u8_DDRA_REG = CONC(		 DIO_u8_PA7_INITIAL_DIRECTION , DIO_u8_PA6_INITIAL_DIRECTION , DIO_u8_PA5_INITIAL_DIRECTION , DIO_u8_PA4_INITIAL_DIRECTION ,
			DIO_u8_PA3_INITIAL_DIRECTION , DIO_u8_PA2_INITIAL_DIRECTION , DIO_u8_PA1_INITIAL_DIRECTION , DIO_u8_PA0_INITIAL_DIRECTION ) ;

	DIO_u8_DDRB_REG = CONC(		 DIO_u8_PB7_INITIAL_DIRECTION , DIO_u8_PB6_INITIAL_DIRECTION , DIO_u8_PB5_INITIAL_DIRECTION , DIO_u8_PB4_INITIAL_DIRECTION ,
			DIO_u8_PB3_INITIAL_DIRECTION , DIO_u8_PB2_INITIAL_DIRECTION , DIO_u8_PB1_INITIAL_DIRECTION , DIO_u8_PB0_INITIAL_DIRECTION ) ;

	DIO_u8_DDRC_REG = CONC(		 DIO_u8_PC7_INITIAL_DIRECTION , DIO_u8_PC6_INITIAL_DIRECTION , DIO_u8_PC5_INITIAL_DIRECTION , DIO_u8_PC4_INITIAL_DIRECTION ,
			DIO_u8_PC3_INITIAL_DIRECTION , DIO_u8_PC2_INITIAL_DIRECTION , DIO_u8_PC1_INITIAL_DIRECTION , DIO_u8_PC0_INITIAL_DIRECTION ) ;

	DIO_u8_DDRD_REG = CONC(		 DIO_u8_PD7_INITIAL_DIRECTION , DIO_u8_PD6_INITIAL_DIRECTION , DIO_u8_PD5_INITIAL_DIRECTION , DIO_u8_PD4_INITIAL_DIRECTION ,
			DIO_u8_PD3_INITIAL_DIRECTION , DIO_u8_PD2_INITIAL_DIRECTION , DIO_u8_PD1_INITIAL_DIRECTION , DIO_u8_PD0_INITIAL_DIRECTION ) ;


	DIO_u8_PORTA_REG = CONC(	 DIO_u8_PA7_INITIAL_VALUE , DIO_u8_PA6_INITIAL_VALUE , DIO_u8_PA5_INITIAL_VALUE , DIO_u8_PA4_INITIAL_VALUE ,
			DIO_u8_PA3_INITIAL_VALUE , DIO_u8_PA2_INITIAL_VALUE , DIO_u8_PA1_INITIAL_VALUE , DIO_u8_PA0_INITIAL_VALUE) ;

	DIO_u8_PORTB_REG = CONC( 	 DIO_u8_PB7_INITIAL_VALUE , DIO_u8_PB6_INITIAL_VALUE , DIO_u8_PB5_INITIAL_VALUE , DIO_u8_PB4_INITIAL_VALUE ,
			DIO_u8_PB3_INITIAL_VALUE , DIO_u8_PB2_INITIAL_VALUE , DIO_u8_PB1_INITIAL_VALUE , DIO_u8_PB0_INITIAL_VALUE ) ;

	DIO_u8_PORTC_REG = CONC(	 DIO_u8_PC7_INITIAL_VALUE , DIO_u8_PC6_INITIAL_VALUE , DIO_u8_PC5_INITIAL_VALUE , DIO_u8_PC4_INITIAL_VALUE ,
			DIO_u8_PC3_INITIAL_VALUE , DIO_u8_PC2_INITIAL_VALUE , DIO_u8_PC1_INITIAL_VALUE , DIO_u8_PC0_INITIAL_VALUE) ;

	DIO_u8_PORTD_REG = CONC(	 DIO_u8_PD7_INITIAL_VALUE , DIO_u8_PD6_INITIAL_VALUE , DIO_u8_PD5_INITIAL_VALUE , DIO_u8_PD4_INITIAL_VALUE ,
			DIO_u8_PD3_INITIAL_VALUE , DIO_u8_PD2_INITIAL_VALUE , DIO_u8_PD1_INITIAL_VALUE , DIO_u8_PD0_INITIAL_VALUE) ;

}

u8 DIO_u8SetPinDirection 		( u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8PinDirection )
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	if(Copy_u8PinID <=DIO_u8_PIN7)
	{
		switch (Copy_u8PinDirection)
		{
		case DIO_u8_OUTPUT :

			switch(Copy_u8PortID)
			{
			case DIO_u8_PORTA : SET_BIT(DIO_u8_DDRA_REG , Copy_u8PinID) ; 	break ;
			case DIO_u8_PORTB : SET_BIT(DIO_u8_DDRB_REG , Copy_u8PinID) ; 	break ;
			case DIO_u8_PORTC : SET_BIT(DIO_u8_DDRC_REG , Copy_u8PinID) ; 	break ;
			case DIO_u8_PORTD : SET_BIT(DIO_u8_DDRD_REG , Copy_u8PinID) ; 	break ;
			default 		  : Local_u8ErrorState = STD_TYPES_NOK 		;	break ;
			}

			break ;

			case DIO_u8_INPUT :

				switch(Copy_u8PortID)
				{
				case DIO_u8_PORTA : CLR_BIT(DIO_u8_DDRA_REG , Copy_u8PinID) ; 	break ;
				case DIO_u8_PORTB : CLR_BIT(DIO_u8_DDRB_REG , Copy_u8PinID) ; 	break ;
				case DIO_u8_PORTC : CLR_BIT(DIO_u8_DDRC_REG , Copy_u8PinID) ; 	break ;
				case DIO_u8_PORTD : CLR_BIT(DIO_u8_DDRD_REG , Copy_u8PinID) ; 	break ;
				default 		  : Local_u8ErrorState = STD_TYPES_NOK 		;	break ;
				}

				break ;

				default : Local_u8ErrorState = STD_TYPES_NOK 				;	break ;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}

	return Local_u8ErrorState ;
}

u8 DIO_u8SetPinValue 			( u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8PinValue )
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	if(Copy_u8PinID <=DIO_u8_PIN7)
	{
		switch (Copy_u8PinValue)
		{
		case DIO_u8_HIGH :

			switch(Copy_u8PortID)
			{
			case DIO_u8_PORTA : SET_BIT(DIO_u8_PORTA_REG , Copy_u8PinID) ; 	break ;
			case DIO_u8_PORTB : SET_BIT(DIO_u8_PORTB_REG , Copy_u8PinID) ; 	break ;
			case DIO_u8_PORTC : SET_BIT(DIO_u8_PORTC_REG , Copy_u8PinID) ; 	break ;
			case DIO_u8_PORTD : SET_BIT(DIO_u8_PORTD_REG , Copy_u8PinID) ; 	break ;
			default 		  : Local_u8ErrorState = STD_TYPES_NOK 		 ;	break ;
			}

			break ;

			case DIO_u8_LOW :

				switch(Copy_u8PortID)
				{
				case DIO_u8_PORTA : CLR_BIT(DIO_u8_PORTA_REG , Copy_u8PinID) ; 	break ;
				case DIO_u8_PORTB : CLR_BIT(DIO_u8_PORTB_REG , Copy_u8PinID) ; 	break ;
				case DIO_u8_PORTC : CLR_BIT(DIO_u8_PORTC_REG , Copy_u8PinID) ; 	break ;
				case DIO_u8_PORTD : CLR_BIT(DIO_u8_PORTD_REG , Copy_u8PinID) ; 	break ;
				default 		  : Local_u8ErrorState = STD_TYPES_NOK 		 ;	break ;
				}

				break ;

				default : Local_u8ErrorState = STD_TYPES_NOK                 ;	break ;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}

	return Local_u8ErrorState ;
}

u8 DIO_u8GetPinValue 			( u8 Copy_u8PortID , u8 Copy_u8PinID , u8 * Copy_Pu8ReturnedPinValue )
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;
	u8 Local_u8PinValue ;

	if((Copy_Pu8ReturnedPinValue !=NULL) &&( Copy_u8PinID <= DIO_u8_PIN7 ))
	{	
		switch (Copy_u8PortID)
		{
		case DIO_u8_PORTA :

			Local_u8PinValue = GET_BIT(DIO_u8_PINA_REG , Copy_u8PinID) ;

			if(Local_u8PinValue == 0)
			{
				* Copy_Pu8ReturnedPinValue = DIO_u8_LOW ;
			}
			else
			{
				* Copy_Pu8ReturnedPinValue = DIO_u8_HIGH ;
			}

			break ;

		case DIO_u8_PORTB :

			Local_u8PinValue = GET_BIT(DIO_u8_PINB_REG , Copy_u8PinID) ;

			if(Local_u8PinValue == 0)
			{
				* Copy_Pu8ReturnedPinValue = DIO_u8_LOW ;
			}
			else
			{
				* Copy_Pu8ReturnedPinValue = DIO_u8_HIGH ;
			}

			break ;

		case DIO_u8_PORTC :

			Local_u8PinValue = GET_BIT(DIO_u8_PINC_REG , Copy_u8PinID) ;

			if(Local_u8PinValue == 0)
			{
				* Copy_Pu8ReturnedPinValue = DIO_u8_LOW ;
			}
			else
			{
				* Copy_Pu8ReturnedPinValue = DIO_u8_HIGH ;
			}

			break ;

		case DIO_u8_PORTD :

			Local_u8PinValue = GET_BIT(DIO_u8_PIND_REG , Copy_u8PinID) ;

			if(Local_u8PinValue == 0)
			{
				* Copy_Pu8ReturnedPinValue = DIO_u8_LOW ;
			}
			else
			{
				* Copy_Pu8ReturnedPinValue = DIO_u8_HIGH ;
			}

			break ;

		default : Local_u8ErrorState = STD_TYPES_NOK ; break ;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}

	return Local_u8ErrorState ;
}

u8 DIO_u8SetAllPortDirection 	( u8 Copy_u8PortID , u8 Copy_u8PortDirection ) 
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	switch (Copy_u8PortDirection)
	{
	case DIO_u8_OUTPUT :
		switch (Copy_u8PortID)
		{
		case DIO_u8_PORTA : SET_REG(DIO_u8_DDRA_REG)  			; break ;
		case DIO_u8_PORTB : SET_REG(DIO_u8_DDRB_REG) 			; break ;
		case DIO_u8_PORTC : SET_REG(DIO_u8_DDRC_REG)  			; break ;
		case DIO_u8_PORTD : SET_REG(DIO_u8_DDRD_REG)  			; break ;
		default 		  : Local_u8ErrorState = STD_TYPES_NOK 	; break ;
		}

		break ;

		case DIO_u8_INPUT :

			switch (Copy_u8PortID)
			{
			case DIO_u8_PORTA : CLR_REG(DIO_u8_DDRA_REG)  			; break ;
			case DIO_u8_PORTB : CLR_REG(DIO_u8_DDRB_REG)  			; break ;
			case DIO_u8_PORTC : CLR_REG(DIO_u8_DDRC_REG)  			; break ;
			case DIO_u8_PORTD : CLR_REG(DIO_u8_DDRD_REG)  			; break ;
			default 		  : Local_u8ErrorState = STD_TYPES_NOK  ; break ;
			}
			break ;

			default : Local_u8ErrorState = STD_TYPES_NOK 			; break ;
	}

	return Local_u8ErrorState ;
}

u8  DIO_u8SetPortDirection		(u8 Copy_u8PortID , u8 Copy_u8PortDirection)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	if(Copy_u8PortDirection <=255)
	{		
		switch(Copy_u8PortID)
		{
		case DIO_u8_PORTA : DIO_u8_DDRA_REG = Copy_u8PortDirection ; break ;
		case DIO_u8_PORTB : DIO_u8_DDRB_REG = Copy_u8PortDirection ; break ;
		case DIO_u8_PORTC : DIO_u8_DDRC_REG = Copy_u8PortDirection ; break ;
		case DIO_u8_PORTD : DIO_u8_DDRD_REG = Copy_u8PortDirection ; break ;
		default			  : Local_u8ErrorState = STD_TYPES_NOK	   ; break ;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}
	return Local_u8ErrorState ;
}

u8 DIO_u8SetAllPortValue 	( u8 Copy_u8PortID , u8 Copy_u8PinValue )
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	switch (Copy_u8PinValue)
	{
	case DIO_u8_HIGH :

		switch (Copy_u8PortID)
		{
		case DIO_u8_PORTA : SET_REG(DIO_u8_PORTA_REG)  				;  break ;
		case DIO_u8_PORTB : SET_REG(DIO_u8_PORTB_REG)  				;  break ;
		case DIO_u8_PORTC : SET_REG(DIO_u8_PORTC_REG)  				;  break ;
		case DIO_u8_PORTD : SET_REG(DIO_u8_PORTD_REG)  				;  break ;
		default 		  : Local_u8ErrorState = STD_TYPES_NOK   	;  break ;
		}

		break ;

		case DIO_u8_LOW :

			switch (Copy_u8PortID)
			{
			case DIO_u8_PORTA : CLR_REG(DIO_u8_PORTA_REG)  				; 	break ;
			case DIO_u8_PORTB : CLR_REG(DIO_u8_PORTB_REG)  				; 	break ;
			case DIO_u8_PORTC : CLR_REG(DIO_u8_PORTC_REG)  				; 	break ;
			case DIO_u8_PORTD : CLR_REG(DIO_u8_PORTD_REG)  				;   break ;
			default 		  : Local_u8ErrorState = STD_TYPES_NOK   	;   break ;
			}
			break ;

			default : Local_u8ErrorState = STD_TYPES_NOK   				;	break ;
	}

	return Local_u8ErrorState ;

}

u8 DIO_u8SetPortValue 	( u8 Copy_u8PortID , u8 Copy_u8PortValue )
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	if(Copy_u8PortValue <=255)
	{		
		switch(Copy_u8PortID)
		{
		case DIO_u8_PORTA : DIO_u8_PORTA_REG = Copy_u8PortValue ; break ;
		case DIO_u8_PORTB : DIO_u8_PORTB_REG = Copy_u8PortValue ; break ;
		case DIO_u8_PORTC : DIO_u8_PORTC_REG = Copy_u8PortValue ; break ;
		case DIO_u8_PORTD : DIO_u8_PORTD_REG = Copy_u8PortValue ; break ;
		default			  : Local_u8ErrorState = STD_TYPES_NOK	; break ;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}
	return Local_u8ErrorState ;
}

u8 DIO_u8GetPortValue 			( u8 Copy_u8PortID , u8 * Copy_Pu8ReturnedPortValue )
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	if(Copy_Pu8ReturnedPortValue !=NULL)
	{	
		switch (Copy_u8PortID)
		{
		case DIO_u8_PORTA : *Copy_Pu8ReturnedPortValue = DIO_u8_PINA_REG ; 	break ;
		case DIO_u8_PORTB : *Copy_Pu8ReturnedPortValue = DIO_u8_PINB_REG ; 	break ;
		case DIO_u8_PORTC : *Copy_Pu8ReturnedPortValue = DIO_u8_PINC_REG ; 	break ;
		case DIO_u8_PORTD : *Copy_Pu8ReturnedPortValue = DIO_u8_PIND_REG ; 	break ;
		default 		  : Local_u8ErrorState = STD_TYPES_NOK 		     ; 	break ;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}

	return Local_u8ErrorState ;
}

u8  DIO_u8TogglePinValue				(u8 Copy_u8PortID , u8 Copy_u8PinID )
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	if(Copy_u8PinID <= DIO_u8_PIN7)
	{
		switch(Copy_u8PortID)
		{
		case DIO_u8_PORTA :TOG_BIT(DIO_u8_PORTA_REG , Copy_u8PinID) ;  break ;
		case DIO_u8_PORTB :TOG_BIT(DIO_u8_PORTB_REG , Copy_u8PinID) ;  break ;
		case DIO_u8_PORTC :TOG_BIT(DIO_u8_PORTC_REG , Copy_u8PinID) ;  break ;
		case DIO_u8_PORTD :TOG_BIT(DIO_u8_PORTD_REG , Copy_u8PinID) ;  break ;
		default 		  : Local_u8ErrorState = STD_TYPES_NOK      ;  break ;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}



