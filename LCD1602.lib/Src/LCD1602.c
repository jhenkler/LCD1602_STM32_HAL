#include "LCD1602_conf.h"
#include "LCD1602.h"
#include "stm32f4xx_hal.h"


uint8_t _eight_bit_mode;
uint8_t _entry_mode;
uint8_t _display_mode;
uint8_t _cursor_shift_mode;
uint8_t _function_mode;


// Start up function, uses function mode (_function_mode), does not get used again.
void lcd_start(Display_options display_options_var, Visiblity_options visiblity_options_var, Entry_options entry_options_var)
{
    delay_us(60000); // Wait for 60ms
    set_modes();
    set_display_options(display_options_var);
    set_visiblity_options(visiblity_options_var);
    set_entry_options(entry_options_var);

    if(display_options_var.four_bit_mode) four_bit_start_up();
    else eight_bit_start_up(_function_mode);

    // This start up sequence is described in the HD 44780 data sheet
    command(_function_mode);
    command(_display_mode);
    lcd_display_clear();
    command(_entry_mode);
}

static void set_modes()
{
    _entry_mode = LCD_ENTRY_MODE;
    _display_mode = LCD_DISPLAY;
    _cursor_shift_mode = LCD_CURSOR_SHIFT;
    _function_mode = LCD_FUNCTION;
}

static void set_display_options(Display_options display_options_var)
{
    // Check for nonsense inputs
    if(display_options_var.one_line == display_options_var.two_line) return;
    if(display_options_var.four_bit_mode == display_options_var.eight_bit_mode) return;
    if(display_options_var.font_5x8 == display_options_var.font_5x10) return;

    if(display_options_var.one_line == 1) _function_mode |= LCD_ONE_LINE;
    else _function_mode |= LCD_TWO_LINES;

    if(display_options_var.four_bit_mode == 1)
    {
        _function_mode |= LCD_4BIT;
        _eight_bit_mode = 0;
    }
    else
    {
        _function_mode |= LCD_8BIT;
        _eight_bit_mode = 1;
    }

    if(display_options_var.font_5x8 == 1) _function_mode |= LCD_5x8_FONT;
    else _function_mode |= LCD_5x10_FONT;

}

static void set_visiblity_options(Visiblity_options visiblity_options_var)
{
    // Check for nonsense inputs
    if(visiblity_options_var.display_on == visiblity_options_var.display_off) return;
    if(visiblity_options_var.show_cursor == visiblity_options_var.hide_cursor) return;
    if(visiblity_options_var.blinking_cursor == visiblity_options_var.solid_cursor) return;

    if(visiblity_options_var.display_on == 1) _display_mode |= LCD_DISPLAY_ON;
    else _display_mode |= LCD_DISPLAY_OFF;

    if(visiblity_options_var.show_cursor == 1) _display_mode |= LCD_CURSOR_ON;
    else _display_mode |= LCD_CURSOR_OFF;

    if(visiblity_options_var.solid_cursor == 1) _display_mode |= LCD_BLINK_OFF;
    else _display_mode |= LCD_BLINK_ON;
}

static void set_entry_options(Entry_options entry_options_var)
{
    // Check for nonsense inputs
    if(entry_options_var.left_alignment == entry_options_var.right_alignment) return;
    if(entry_options_var.left_to_right == entry_options_var.right_to_left) return;

    if(entry_options_var.left_alignment == 1) _entry_mode |= LCD_ENTRY_LEFT;
    else _entry_mode = LCD_ENTRY_RIGHT;

    if(entry_options_var.left_to_right == 1) _entry_mode |= LCD_ENTRY_SHIFT_DECREMENT;
    else _entry_mode = LCD_ENTRY_SHIFT_INCREMENT;
}

static void four_bit_start_up()
{
    // This start up sequence is described in the HD 44780 data sheet
    write_four_bits(0x03);
    delay_us(5000); // Wait for 5ms
    write_four_bits(0x03);
    delay_us(5000); // Wait for 5ms
    write_four_bits(0x03);
    delay_us(200); // Wait for 200us
    write_four_bits(0x02);
}

static void eight_bit_start_up(uint8_t function_mode)
{
    // This start up sequence is described in the HD 44780 data sheet
    command(_function_mode);
    delay_us(5000); // Wait for 5ms

    command(_function_mode);
    delay_us(200); // Wait for 200us

    command(_function_mode);
}

// Stand alone functions
void lcd_display_clear()
{
    command(LCD_CLEAR_DISPLAY);
    delay_us(2000);
}

void return_home()
{
    command(LCD_RETURN_HOME);
}


// Display mode functions (_display_mode)
void lcd_display_on()
{
    _display_mode |= LCD_DISPLAY_ON;
    command(_display_mode);
}

void lcd_display_off()
{
    _display_mode &= ~LCD_DISPLAY_ON;
    command(_display_mode);
}

void lcd_blink_on()
{
    _display_mode |= (LCD_BLINK_ON);
    command(_display_mode);
}

void lcd_blink_off()
{
    _display_mode &= ~(LCD_BLINK_ON);
    command(_display_mode);
}

void lcd_show_cursor()
{
    _display_mode |= (LCD_CURSOR_ON);
    command(_display_mode);
}

void lcd_hide_cursor()
{
    _display_mode &= ~(LCD_CURSOR_ON);
    command(_display_mode);
}


// Cursor shift functions (_cursor_shift_mode)

void lcd_scroll_right()
{
    _cursor_shift_mode = (LCD_CURSOR_SHIFT | LCD_DISPLAY_MOVE | LCD_MOVE_RIGHT);
    command(_cursor_shift_mode);
}

void lcd_scroll_left()
{
    _cursor_shift_mode = (LCD_CURSOR_SHIFT | LCD_DISPLAY_MOVE | LCD_MOVE_LEFT);
    command(_cursor_shift_mode);
}

void lcd_shift_cursor_right()
{
    _cursor_shift_mode = (LCD_CURSOR_SHIFT | LCD_CURSOR_MOVE | LCD_MOVE_RIGHT);
    command(_cursor_shift_mode);
}

void lcd_shift_cursor_left()
{
    _cursor_shift_mode = (LCD_CURSOR_SHIFT | LCD_CURSOR_MOVE | LCD_MOVE_LEFT);
}


// CG ram function
/**
  * @brief Sets CG RAM address.
  * 
  * @note This function will do nothing if the value than 0x3F is given.
  * 
  * @param value is expected to be given in hex value, such as 0x03. This parameters range is 0x00 through 0x3F.
  * 
  * @retval None.
  */
void lcd_create_custom_character(uint8_t value, uint8_t charmap[])
{
    if(value > 0x0F) return;
    //value &= 0x7;
    command(LCD_SETCGRAM | value);
    for(int i = 0; i < 8; i++)
    {
        lcd_write_character(charmap[i]);
    }
}


// DD ram functions
/**
  * @brief Sets DD RAM address.
  * 
  * @note This function will do nothing if the value than 0x7F is given.
  * 
  * @param value is expected to be given in hex value, such as 0x03. This parameters range is 0x00 through 0x7F.
  * 
  * @retval None.
  */
void lcd_set_cursor_location(uint8_t value)
{
    if(value > 0x7F) return;
    command(LCD_SETDDRAM | value);
}

/**
  * @brief Sets what is shown on screen.
  * 
  * @note This function will do nothing on character overflow.
  * 
  * @param string is expected to be in characters. If one line was choosen, then a maximum characters that can be entered is 16. 
  * If two lines was choosen, then the maximum characters that can be entered is 32.
  * 
  * @retval None.
  */
void lcd_write(char string[])
{
    int8_t max_size;
    int array_size;
    if(_function_mode & LCD_TWO_LINES) max_size = 32;
    if(_function_mode & LCD_ONE_LINE) max_size = 16;
    array_size = strlen(string);
    if(array_size > max_size) return;

    for(int i = 0; i < array_size; i++)
    {
        lcd_write_character(string[i]);
    }
}

// User function, just calls lcd_write_character
void lcd_print_custom_character(uint8_t value)
{
    lcd_write_character(value);
}


// GPIO output functions
static void lcd_write_character(uint8_t value)
{
    HAL_GPIO_WritePin(GPIO_PORT, PIN_RS, 1);
    command(value);
    HAL_GPIO_WritePin(GPIO_PORT, PIN_RS, 0);
}

static void command(uint8_t value)
{
    if(_eight_bit_mode == 0)
    {
        write_four_bits(value >> 4);
        write_four_bits(value);
    }
    else write_eight_bits(value);
}

static void write_four_bits(uint8_t value)
{
    HAL_GPIO_WritePin(GPIO_PORT, PIN_D4, (value & 0x01));
    HAL_GPIO_WritePin(GPIO_PORT, PIN_D5, (value & 0x02));
    HAL_GPIO_WritePin(GPIO_PORT, PIN_D6, (value & 0x04));
    HAL_GPIO_WritePin(GPIO_PORT, PIN_D7, (value & 0x08));
    
    pulse_enable();
}

static void write_eight_bits(uint8_t value)
{
    HAL_GPIO_WritePin(GPIO_PORT, PIN_D0, (value & 0x01));
    HAL_GPIO_WritePin(GPIO_PORT, PIN_D1, (value & 0x02));
    HAL_GPIO_WritePin(GPIO_PORT, PIN_D2, (value & 0x04));
    HAL_GPIO_WritePin(GPIO_PORT, PIN_D3, (value & 0x08));
    HAL_GPIO_WritePin(GPIO_PORT, PIN_D4, (value & 0x10));
    HAL_GPIO_WritePin(GPIO_PORT, PIN_D5, (value & 0x20));
    HAL_GPIO_WritePin(GPIO_PORT, PIN_D6, (value & 0x40));
    HAL_GPIO_WritePin(GPIO_PORT, PIN_D7, (value & 0x80));

    pulse_enable();
}

static void pulse_enable()
{
    HAL_GPIO_WritePin(GPIO_PORT, ENABLE_PIN, 0);
    delay_us(1);
    HAL_GPIO_WritePin(GPIO_PORT, ENABLE_PIN, 1);
    delay_us(1);
    HAL_GPIO_WritePin(GPIO_PORT, ENABLE_PIN, 0);
    delay_us(100);
}
