#@copyright: Abdelrahman
CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m4 
INCS=-I .
LIBS= 
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
Project_name = Unit3_lab4_cortexM4

all: $(Project_name).bin
	@echo "BUILD IS DONE"
	

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

$(Project_name).exe: $(AsOBJ) $(OBJ)
	$(CC)ld.exe  -T linker_script.ld $(LIBS) $(AsOBJ) $(OBJ) -o $@ -Map=Map_file.map

clean_all:
	rm *.o *.elf *.bin
clean:
	rm *.elf *.bin