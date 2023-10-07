#ifndef INC_1602_CONF_H_
#define INC_1602_CONF_H_

#define GPIO_PORT GPIOA

#include <inttypes.h>


struct display_options
{
    uint8_t one_line;
    uint8_t two_line;
    uint8_t four_bit_mode;
    uint8_t eight_bit_mode;
    uint8_t font_5x8;
    uint8_t font_5x10;
};

typedef struct display_options Display_options;

struct visiblity_options
{
    uint8_t display_on;
    uint8_t display_off;
    uint8_t show_cursor;
    uint8_t hide_cursor;
    uint8_t blinking_cursor;
    uint8_t solid_cursor;
};

typedef struct visiblity_options Visiblity_options;

struct entry_options
{
    uint8_t left_alignment;
    uint8_t right_alignment;
    uint8_t left_to_right;
    uint8_t right_to_left;
};

typedef struct entry_options Entry_options;

// custom character, there is only 8 available 

extern uint8_t custom_character_1[8];
extern uint8_t custom_character_2[8];
extern uint8_t custom_character_3[8];
extern uint8_t custom_character_4[8];
extern uint8_t custom_character_5[8];
extern uint8_t custom_character_6[8];
extern uint8_t custom_character_7[8];
extern uint8_t custom_character_8[8];

#endif 
