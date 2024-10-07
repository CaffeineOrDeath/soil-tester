# Generic CMake for AVR
# Adapted from https://www.kuon.ch/post/2018-07-11-avr-cmake/

cmake_minimum_required(VERSION 3.12)

project(soil-sampler C)

## Libs
add_subdirectory(./arduino ./arduino/build)
add_subdirectory(./centrifuge ./centrifuge/build)
add_subdirectory(./injector ./injector/build)
add_subdirectory(./pump ./pump/build)
add_subdirectory(./sampler ./sampler/build)

## AVR Settings
set(F_CPU 16000000UL)
set(MCU avr5)
#set(BAUD 9600)
add_definitions(-DFCPU=${FCPU})

## Progs
set(AVRCPP   avr-g++)
set(AVRC     avr-gcc)
set(AVRSTRIP avr-strip)
set(OBJCOPY  avr-objcopy)
set(OBJDUMP  avr-objdump)
set(AVRSIZE  avr-size)
set(AVRDUDE  avrdude)

## AVR Fuses
## will return to this at a later time, hardware requirements still need to be
## settled to know which Fuses are needed or even if they need to be changed

## AVR GCC Tools
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_CXX_COMPILER ${AVRCPP})
set(CMAKE_C_COMPILER ${AVRC})
set(CMAKE_ASM_COMPILER ${AVRC})

## Flags
set(CSTANDARD "-std=gnu99")
set(CDEBUG    "-ggdb -O0")
set(CWARN     "-Wall -Wstrict-prototypes -Wl,--gc-sections -Wl,--relax")
set(CTUNING   "-funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -ffunction-sections -fdata-sections")
set(COPT      "-Os -lm -lprintf_flt")
set(CMCU      "-mmcu=${MCU} -nodevicespecs")
set(CDEFS     "-DF_CPU=${F_CPU}") #-DBAUD=${BAUD}

set(CFLAGS "${CDEBUG} ${CDEFS} ${COPT} ${CWARN} ${CSTANDARD} ${CTUNING}")
set(CXXFLAGS "${CMCU} ${CDEBUG} ${CDEFS} ${COPT} ${CTUNING}")

set(CMAKE_C_FLAGS   "${CFLAGS}")
set(CMAKE_CXX_FLAGS "${CXXFLAGS}")
set(CMAKE_ASM_FLAGS   "${CFLAGS}")

## Exe
add_executable(${CMAKE_PROJECT_NAME} ./main.c)
target_link_libraries(${CMAKE_PROJECT_NAME}
    SysArd
    Centrifuge
    Injector
    Pump
    Sampler
)
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE "-mmcu=atmega328p")
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES OUTPUT_NAME ${CMAKE_PROJECT_NAME}.elf)

add_custom_target(strip ALL ${AVRSTRIP} "${CMAKE_PROJECT_NAME}.elf" DEPENDS ${CMAKE_PROJECT_NAME})
add_custom_target(hex ALL ${OBJCOPY} -R .eeprom -O ihex "${CMAKE_PROJECT_NAME}.elf" "${CMAKE_PROJECT_NAME}.hex" DEPENDS strip)
add_custom_target(eeprom ${OBJCOPY} -j .eeprom --change-section-lma .eeprom=0 -O ihex "${CMAKE_PROJECT_NAME}.elf" "${CMAKE_PROJECT_NAME}.eeprom" DEPENDS strip) 

## Burn fuses
# add_custom_target(fuses avrdude -c ${PROG_TYPE} -p ${MCU}  -U lfuse:w:${L_FUSE}:m -U hfuse:w:${H_FUSE}:m -U efuse:w:${E_FUSE}:m -U lock:w:${LOCK_BIT}:m )

# Clean extra files
set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES "${CMAKE_PROJECT_NAME}.hex; ${CMAKE_PROJECT_NAME}.eeprom;${CMAKE_PROJECT_NAME}.lst")

