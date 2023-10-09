#ifndef LCD1602_H
#define LCD1602_H

#include <inttypes.h>

// Based on the HD44780 data sheet 

#define LCD_CLEAR_DISPLAY 0x01
#define LCD_RETURN_HOME 0x02
#define LCD_ENTRY_MODE 0x04
#define LCD_DISPLAY 0x08
#define LCD_CURSOR_SHIFT 0x10
#define LCD_FUNCTION 0x20
#define LCD_SETCGRAM 0x40
#define LCD_SETDDRAM 0x80


// Entry mode
#define LCD_ENTRY_RIGHT 0x00
#define LCD_ENTRY_LEFT 0x02
#define LCD_ENTRY_SHIFT_INCREMENT 0x01
#define LCD_ENTRY_SHIFT_DECREMENT 0x00

// Display mode
#define LCD_DISPLAY_ON 0x04
#define LCD_DISPLAY_OFF 0x00
#define LCD_CURSOR_ON 0x02
#define LCD_CURSOR_OFF 0x00
#define LCD_BLINK_ON 0x01
#define LCD_BLINK_OFF 0x00

// Cursor shift mode
#define LCD_DISPLAY_MOVE 0x08
#define LCD_CURSOR_MOVE 0x00
#define LCD_MOVE_RIGHT 0x04
#define LCD_MOVE_LEFT 0x00

// Function mode
#define LCD_8BIT 0x10
#define LCD_4BIT 0x00
#define LCD_TWO_LINES 0x08
#define LCD_ONE_LINE 0x00
#define LCD_5x8_FONT 0x00
#define LCD_5x10_FONT 0x04

// Port definition
#define GPIO_PORT GPIOA

// Pin definitions
#define ENABLE_PIN GPIO_PIN_0
#define PIN_D0 GPIO_PIN_5
#define PIN_D1 GPIO_PIN_6
#define PIN_D2 GPIO_PIN_7
#define PIN_D3 GPIO_PIN_8
#define PIN_D4 GPIO_PIN_1
#define PIN_D5 GPIO_PIN_4
#define PIN_D6 GPIO_PIN_10
#define PIN_D7 GPIO_PIN_11
#define PIN_RS GPIO_PIN_9


// Variables
extern uint8_t _eight_bit_mode;
extern uint8_t _entry_mode;
extern uint8_t _display_mode;
extern uint8_t _cursor_shift_mode;
extern uint8_t _function_mode;


/* Prototypes */

// Start up functions
void lcd_start(Display_options, Visiblity_options, Entry_options);
static void set_modes();
static void set_display_options(Display_options);
static void set_visiblity_options(Visiblity_options);
static void set_entry_options(Entry_options);
static void four_bit_start_up();
static void eight_bit_start_up(uint8_t);

// Stand alone functions
void lcd_display_clear();
void lcd_return_home();

// Display mode functions
void lcd_display_on();
void lcd_display_off();
void lcd_blink_on();
void lcd_blink_off();
void lcd_show_cursor();
void lcd_hide_cursor();

// Cursor shift functions
void lcd_scroll_right();
void lcd_scroll_left();
void lcd_shift_cursor_right();
void lcd_shift_cursor_left();

// CG ram function
void lcd_create_custom_character(uint8_t, uint8_t []);

// DD ram functions
void lcd_set_cursor_location(uint8_t);
void lcd_write(char []);

// User function
void lcd_print_custom_character(uint8_t); 

//GPIO output functions
static void lcd_write_character(uint8_t);
static void command(uint8_t);
static void write_four_bits(uint8_t);
static void write_eight_bits(uint8_t);
static void pulse_enable();

#endif
