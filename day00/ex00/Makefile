F_CPU = 115200
MCU = atmega328p
PORT = /dev/ttyUSB0

CC = avr-gcc
C_FLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Wall -Os
LDFLAGS = -mmcu=$(MCU)
OBJCOPY = avr-objcopy
OBJCOPY_FLAGS = -j .text -j .data -O ihex
AVRDUDE = avrdude

SRC_DIR = src
BUILD_DIR = build

SRC = $(SRC_DIR)/main.c
HEX = $(SRC:.c=.hex)
TARGET = main


all: hex flash

$(BUILD_DIR):
	mkdir -pv $(BUILD_DIR)

hex: $(BUILD_DIR)
	$(CC) $(C_FLAGS) -o $(BUILD_DIR)/$(TARGET).bin $(SRC)
	$(OBJCOPY) $(OBJCOPY_FLAGS) $(BUILD_DIR)/$(TARGET).bin $(BUILD_DIR)/$(TARGET).hex

flash: hex
	$(AVRDUDE) -p $(MCU) -P $(PORT) -b $(F_CPU) -c arduino -U flash:w:$(BUILD_DIR)/$(TARGET).hex


clean:
	rm -rf $(BUILD_DIR)

re: clean all

.PHONY: all clean fclean re
.SILENT:
