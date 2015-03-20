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
;.equ			= 7
;.equ			= 6
;.equ			= 5	(sck)
;.equ			= 4	(miso)
;.equ	ApFET		= 3	;o (mosi)
;.equ	BpFET		= 2	;o
;.equ	CpFET		= 1	;o
;.equ	rcp_in		= 0	;i r/c pulse input

.equ	INIT_PB		= 0
.equ	DIR_PB		= 0
;.equ	DIR_PB		= (1<<ApFET)+(1<<BpFET)+(1<<CpFET)

;.equ	ApFET_port	= PORTB
;.equ	BpFET_port	= PORTB
;.equ	CpFET_port	= PORTB

;*********************
; PORT C definitions *
;*********************
;.equ	mux_voltage	= 7	; ADC7 voltage input
;.equ			= 6	; ADC6
;.equ	i2c_clk		= 5	; ADC5/SCL
;.equ	i2c_data	= 4	; ADC4/SDA
;.equ	mux_temperature	= 3	; ADC3 temperature input
;.equ	mux_c		= 2	; ADC2 phase input
;.equ	mux_b		= 1	; ADC1 phase input
;.equ	mux_a		= 0	; ADC0 phase input

;.equ	O_POWER		= 18
;.equ	O_GROUND	= 1

;.equ	INIT_PC		= (1<<i2c_clk)+(1<<i2c_data)
;.equ	DIR_PC		= 0
.equ	mux_a		= 2
.equ	mux_b		= 3
.equ	mux_c		= 4
.equ	DIR_PC		= 0
.equ	INIT_PC		= (0)

;*********************
; PORT D definitions *
;*********************
;.equ	WarnLED		= 2
;.equ	AnFET		= 3
;.equ	BnFET		= 4
;.equ	CnFET		= 5
;.equ	StatLED		= 7
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
;	sbi	PORTD, WarnLED
.ENDMACRO
.MACRO RED_off
;	cbi	PORTD, WarnLED
.ENDMACRO
.MACRO GRN_on
;	cbi	PORTD, StatLED
.ENDMACRO
.MACRO GRN_off
;	sbi	PORTD, StatLED
.ENDMACRO
