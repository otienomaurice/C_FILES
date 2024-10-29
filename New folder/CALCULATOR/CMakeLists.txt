cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(CALCULATOR)
pico_sdk_init()
add_executable(CALCULATOR)

pico_generate_pio_header(CALCULATOR ${CMAKE_CURRENT_LIST_DIR}/SPIPIO.pio)

# pull in common dependencies
target_link_libraries(CALCULATOR pico_stdlib
    hardware_adc
    hardware_gpio hardware_pio
    hardware_irq
    pico_bootsel_via_double_reset
)

target_sources(CALCULATOR PRIVATE
     main.c
     ts_lcd
     TouchScreen.c
     TFTMaster.c
     glcdfont.c
     button.c
     timer.c
     display.c
     touchin_validation.c    
     calculator.c                     
     global.c
     calculator_fsm.c 

)

# create map/bin/hex file etc.
pico_add_extra_outputs(CALCULATOR)
