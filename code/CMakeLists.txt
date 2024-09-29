cmake_minimum_required(VERSION 3.12)

project(soil-sampler)
set(PRODUCT_NAME soil)

add_subdirectory(./arduino ./arduino/build)
add_subdirectory(./centrifuge ./centrifuge/build)
add_subdirectory(./injector ./injector/build)
add_subdirectory(./pump ./pump/build)
add_subdirectory(./sampler ./sampler/build)

## AVR Settings
set(F_CPU 8000000UL)
set(MCU atmega328p)
set(BAUD 9600)
set(PROG_TYPE avrispmkII)

## AVR Fuses
## will return to this at a later time, hardware requirements still need to be
## settled

## AVR GCC Tools
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_CXX_COMPILER avr-g++)
set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_ASM_COMPILER avr-gcc)

## Compiler Definitions
add_definitions(
    -DF_CPU=${F_CPU}
    -DBAUD=${BAUD}
)

## Linker Flags
set(CMAKE_EXE_LINKER_FLAGS -mmcu=${MCU})

## Compiler Options
## long list
add_compile_options(
    -mmcu=${MCU}
    -std=gnu99 #c99
    -Os
    -Wall
    -Wno-main
    -pedantic
    -Wstrict-prototypes
    -Werror
    -Wfatal-errors
    -Wl,--relax,--gc-sections
    -g
    -gdwarf-2
    -funsigned-bitfields
    -fpack-struct
    -fshort-enums
    -ffunction-sections
    -fdata-sections
    -fno-split-wide-types
    -fno-tree-scev-cprop
)

add_executable(${PRODUCT_NAME} ./main.c)
target_link_libraries(${PRODUCT_NAME}
    SysArd
    Centrifuge
    Injector
    Pump
    Sampler
)

set_target_properties(${PRODUCT_NAME} PROPERTIES OUTPUT_NAME ${PRODUCT_NAME}.elf)
add_custom_target(strip ALL avr-strip ${PRODUCT_NAME}.elf DEPENDS ${PRODUCT_NAME})
# Transform binary into hex file, we ignore the eeprom segments in the step
add_custom_target(hex ALL avr-objcopy -R .eeprom -O ihex ${PRODUCT_NAME}.elf ${PRODUCT_NAME}.hex DEPENDS strip)
# Transform binary into hex file, this is the eeprom part (empty if you don't
# use eeprom static variables)
add_custom_target(eeprom avr-objcopy -j .eeprom  --set-section-flags=.eeprom="alloc,load"  --change-section-lma .eeprom=0 -O ihex ${PRODUCT_NAME}.elf ${PRODUCT_NAME}.eep DEPENDS strip)

# Upload the firmware with avrdude
add_custom_target(upload avrdude  -c ${PROG_TYPE} -p ${MCU} -U flash:w:${PRODUCT_NAME}.hex DEPENDS hex)

# Upload the eeprom with avrdude
add_custom_target(upload_eeprom avrdude -c ${PROG_TYPE} -p ${MCU}  -U eeprom:w:${PRODUCT_NAME}.eep DEPENDS eeprom)

# Burn fuses
# add_custom_target(fuses avrdude -c ${PROG_TYPE} -p ${MCU}  -U lfuse:w:${L_FUSE}:m -U hfuse:w:${H_FUSE}:m -U efuse:w:${E_FUSE}:m -U lock:w:${LOCK_BIT}:m )

# Clean extra files
set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES "${PRODUCT_NAME}.hex;${PRODUCT_NAME}.eeprom;${PRODUCT_NAME}.lst")


