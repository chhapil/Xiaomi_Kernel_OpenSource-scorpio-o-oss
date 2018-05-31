/*
 * Synaptics DSX touchscreen driver
 *
 * Copyright (C) 2012-2015 Synaptics Incorporated. All rights reserved.
 *
 * Copyright (C) 2012 Alexandra Chin <alexandra.chin@tw.synaptics.com>
 * Copyright (C) 2012 Scott Lin <scott.lin@tw.synaptics.com>
 * Copyright (C) 2018 XiaoMi, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * INFORMATION CONTAINED IN THIS DOCUMENT IS PROVIDED "AS-IS," AND SYNAPTICS
 * EXPRESSLY DISCLAIMS ALL EXPRESS AND IMPLIED WARRANTIES, INCLUDING ANY
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE,
 * AND ANY WARRANTIES OF NON-INFRINGEMENT OF ANY INTELLECTUAL PROPERTY RIGHTS.
 * IN NO EVENT SHALL SYNAPTICS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, PUNITIVE, OR CONSEQUENTIAL DAMAGES ARISING OUT OF OR IN CONNECTION
 * WITH THE USE OF THE INFORMATION CONTAINED IN THIS DOCUMENT, HOWEVER CAUSED
 * AND BASED ON ANY THEORY OF LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * NEGLIGENCE OR OTHER TORTIOUS ACTION, AND EVEN IF SYNAPTICS WAS ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE. IF A TRIBUNAL OF COMPETENT JURISDICTION DOES
 * NOT PERMIT THE DISCLAIMER OF DIRECT DAMAGES OR ANY OTHER DAMAGES, SYNAPTICS'
 * TOTAL CUMULATIVE LIABILITY TO ANY PARTY SHALL NOT EXCEED ONE HUNDRED U.S.
 * DOLLARS.
 */

#ifndef _SYNAPTICS_DSX_H_
#define _SYNAPTICS_DSX_H_

#define PLATFORM_DRIVER_NAME "synaptics_dsx"
#define PLATFORM_DRIVER_FORCE "synaptics_force"
#define STYLUS_DRIVER_NAME "synaptics_dsx_stylus"
#define ACTIVE_PEN_DRIVER_NAME "synaptics_dsx_active_pen"
#define PROXIMITY_DRIVER_NAME "synaptics_dsx_proximity"
#define GESTURE_DRIVER_NAME "synaptics_dsx_gesture"
#define I2C_DRIVER_NAME "synaptics_dsx_i2c"
#define I2C_DRIVER_FORCE "synaptics_dsx_force"
#define SPI_DRIVER_NAME "synaptics_dsx_spi"

/*
 * struct synaptics_dsx_button_map - button map
 * @nbuttons: number of buttons
 * @map: pointer to array of button codes
 */
struct synaptics_dsx_button_map {
	unsigned char nbuttons;
	unsigned int *map;
};

struct synaptics_dsx_config_info {
	int chip_id;
	unsigned char *tp_ids;
	const char *fw_name;
};

enum synaptics_dsx_lockdown_area {
	LOCKDOWN_AREA_PRODUCT_ID = 0,
	LOCKDOWN_AREA_GUEST_SERIALIZATION = 1,
	LOCKDOWN_AREA_UNKNOWN = 0xFF,
};

/*
 * struct synaptics_dsx_board_data - DSX board data
 * @x_flip: x flip flag
 * @y_flip: y flip flag
 * @swap_axes: swap axes flag
 * @irq_gpio: attention interrupt GPIO
 * @irq_on_state: attention interrupt active state
 * @power_gpio: power switch GPIO
 * @power_on_state: power switch active state
 * @reset_gpio: reset GPIO
 * @reset_on_state: reset active state
 * @max_y_for_2d: maximum y value for 2D area when virtual buttons are present
 * @irq_flags: IRQ flags
 * @i2c_addr: I2C slave address
 * @ub_i2c_addr: microbootloader mode I2C slave address
 * @device_descriptor_addr: HID device descriptor address
 * @panel_x: x-axis resolution of display panel
 * @panel_y: y-axis resolution of display panel
 * @power_delay_ms: delay time to wait after powering up device
 * @reset_delay_ms: delay time to wait after resetting device
 * @reset_active_ms: reset active time
 * @byte_delay_us: delay time between two bytes of SPI data
 * @block_delay_us: delay time between two SPI transfers
 * @pwr_reg_name: pointer to name of regulator for power control
 * @lab_reg_name: pointer to name of regulator for LCD lab control
 * @ibb_reg_name: pointer to name of regulator for LCD ibb control
 * @disp_reg_name: pointer to name of regulator for LCD vddio control
 * @bus_reg_name: pointer to name of regulator for bus pullup control
 * @cap_button_map: pointer to 0D button map
 * @vir_button_map: pointer to virtual button map
 */
struct synaptics_dsx_board_data {
	bool x_flip;
	bool y_flip;
	bool swap_axes;
	int irq_gpio;
	int irq_on_state;
	int power_gpio;
	int power_on_state;
	int mdss_reset;
	int mdss_reset_state;
	int reset_gpio;
	int reset_on_state;
	int max_y_for_2d;
	int config_array_size;
	int tp_id_num;
	int chip_3330;
	int chip_3331;
	int chip_4322;
	int chip_4722;
	unsigned char *tp_id_bytes;
	unsigned long irq_flags;
	unsigned short i2c_addr;
	unsigned short ub_i2c_addr;
	unsigned short device_descriptor_addr;
	unsigned int panel_x;
	unsigned int panel_y;
	unsigned int power_delay_ms;
	unsigned int reset_delay_ms;
	unsigned int reset_active_ms;
	unsigned int byte_delay_us;
	unsigned int block_delay_us;
	bool cut_off_power;
	bool captouch_use;
	bool power_ctrl;
	const char *pwr_reg_name;
	const char *lab_reg_name;
	const char *ibb_reg_name;
	const char *disp_reg_name;
	const char *bus_reg_name;
	const char *power_gpio_name;
	const char *reset_gpio_name;
	const char *irq_gpio_name;
	const char *backup_fw_name;
	const char *short_test25;
	const char *short_test26;
	struct synaptics_dsx_button_map *cap_button_map;
	struct synaptics_dsx_button_map *vir_button_map;
	struct synaptics_dsx_config_info *config_array;
	enum synaptics_dsx_lockdown_area lockdown_area;
};

#endif
