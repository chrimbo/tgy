;***********************************************************
;* Supercheap ebay china ESC                               *
;* 2015.03                                                 *
;***********************************************************

.equ	F_CPU		= 16000000
.equ	USE_INT0	= 1
.equ	USE_I2C		= 0
.equ	USE_UART	= 0
.equ	USE_ICP		= 0

.equ	DEAD_LOW_NS	= 2200
.equ	DEAD_HIGH_NS 	= 24000

;*********************
; PORT B definitions *
;*********************

.equ	INIT_PB		= 0
.equ	DIR_PB		= 0

;*********************
; PORT C definitions *
;*********************
.equ	mux_a		= 2
.equ	mux_b		= 3
.equ	mux_c		= 4
.equ	DIR_PC		= 0
.equ	INIT_PC		= (0)

;*********************
; PORT D definitions *
;*********************
.equ	AnFET		= 0
.equ	BnFET		= 1
.equ	CnFET		= 3
.equ	ApFET		= 5
.equ	BpFET		= 7
.equ	CpFET		= 4
.equ	rcp_in		= 2

.equ	INIT_PD		= 0
.equ	DIR_PD		= (1<<AnFET)+(1<<BnFET)+(1<<CnFET)+(1<<ApFET)+(1<<BpFET)+(1<<CpFET)

.equ	AnFET_port	= PORTD
.equ	BnFET_port	= PORTD
.equ	CnFET_port	= PORTD
.equ	ApFET_port	= PORTD
.equ	BpFET_port	= PORTD
.equ	CpFET_port	= PORTD

.MACRO RED_on
.ENDMACRO
.MACRO RED_off
.ENDMACRO
.MACRO GRN_on
.ENDMACRO
.MACRO GRN_off
.ENDMACRO
