This is a HAL display driver for LCD1602. it has an eight and four bit mode. The settings for the display can be modified useing the struct declartions in main.c. The struct definitions can be found in the LCD1602_conf.h file. This display also allows for 8 custom characters, those can be moddified in main.c. 

Below is the schemtic for the four bit connection:
![LCD1602_4bit](https://github.com/jhenkler/LCD1602_STM32_HAL/assets/147257321/013f96b0-e780-4a6f-9447-2f223dbea1dc)
![1000002773](https://github.com/jhenkler/LCD1602_STM32_HAL/assets/147257321/d54bc253-71f1-41d0-ac63-7002c0ba7115)

Eight bit schemtic:
![LCD1602_8bit](https://github.com/jhenkler/LCD1602_STM32_HAL/assets/147257321/b76acee7-d6c7-4201-8af6-b5f4bc987f7b)
![1000002775](https://github.com/jhenkler/LCD1602_STM32_HAL/assets/147257321/5dcc155b-4ae9-4215-9090-c36dfefd0d21)


This should be useable with minor modifications for other HAL enabled devices. The timer and GPIO settings would need to be moddified. The GPIO defintions can be found in the LCD1602.h file.
