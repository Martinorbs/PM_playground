/******************************************************************************
    @file:  ad910x.h
 
    @brief: Defines digital pins and functions for the devices' SPI interface
            and printing data from SPI read to text-based user interface
-------------------------------------------------------------------------------
    Copyright (c) 2021 Analog Devices, Inc.
    All rights reserved.
 
    This software is proprietary to Analog Devices, Inc. and its licensors.
    By using this software you agree to the terms of the associated
    Analog Devices Software License Agreement.
 
    20210120-LWSC-CTSLA
******************************************************************************/

#ifndef __ad9102_h__
#define __ad9102_h__
#define DRIVER_MASTER_SPI Driver_SPI0
#define TRANSFER_BAUDRATE 115200U /* Transfer baudrate - 500k */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "fsl_spi_cmsis.h"
#include "pin_mux.h"
#include "board.h"


// Function to setup SPI
void spi_init( uint8_t reg_len, uint8_t mode, uint32_t hz);

// SPI write function
void spi_write( uint16_t addr, int16_t data );

// SPI read function
int16_t spi_read( uint16_t addr );

// Function to reset SPI register values
void reg_reset();

// Function to display register data
void print_data( uint16_t addr, uint16_t data );

// Function to write to SRAM
void update_sram( int16_t data[] );

// Function to display n SRAM data
void print_sram( uint16_t n );

// Function to write to device SPI registers and display updated register values
void update_regs();

// Function to start pattern generation
void start_pattern();

// Function to stop pattern generation
void stop_pattern();

#endif
