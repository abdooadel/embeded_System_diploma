#@copyright: Abdelrahman
CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m3 -gdwarf-2
INCS=-I .
LIBS= 
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
Project_name = Project

all: $(Project_name).elf
	@echo "BUILD IS DONE"
	

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

$(Project_name).elf: $(AsOBJ) $(OBJ)
	$(CC)ld.exe  -T linker_script.ld $(LIBS) $(AsOBJ) $(OBJ) -o $@ -Map=Map_file.map

	

clean_all:
	rm *.o *.elf *.bin
clean:
	rm *.elf *.bin