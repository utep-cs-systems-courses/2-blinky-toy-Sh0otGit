# makfile configuration
COMMON_OBJECTS  =   
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: main.elf 

#additional rules for files
main.elf: ${COMMON_OBJECTS} main.o p1_interrupt_handler.o buzzer.o stateMachines.o led.o switches.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ ../timerLib/libTimer.a 

load: main.elf
	msp430loader.sh main.elf

clean:
	rm -f *.o *.elf

stateMachines.o: stateMachines.c stateMachines.h
led.o: led.c led.h
switches.o: switches.c switches.h
buzzer.o: buzzer.c buzzer.h
p1_interrupt_handler.o: p1_interrupt_handler.c
