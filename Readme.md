Welcome to the HAL display driver for LCD1602, a versatile display solution offering both eight and four-bit modes. This driver empowers you to customize your LCD1602 display effortlessly, all thanks to the user-friendly struct declarations housed in the main.c file. For further reference, you can explore the struct definitions conveniently stored in the LCD1602_conf.h file. Notably, this driver also extends its capabilities by allowing you to create and modify up to 8 custom characters, easily managed within the main.c file.

Let's take a closer look at the connection schematics, ensuring you get your LCD1602 display up and running seamlessly:

Four-Bit Connection:
![LCD1602_4bit](https://github.com/jhenkler/LCD1602_STM32_HAL/assets/147257321/013f96b0-e780-4a6f-9447-2f223dbea1dc)
![1000002773](https://github.com/jhenkler/LCD1602_STM32_HAL/assets/147257321/d54bc253-71f1-41d0-ac63-7002c0ba7115)

Eight-Bit Connection:
![LCD1602_8bit](https://github.com/jhenkler/LCD1602_STM32_HAL/assets/147257321/b76acee7-d6c7-4201-8af6-b5f4bc987f7b)
![1000002775](https://github.com/jhenkler/LCD1602_STM32_HAL/assets/147257321/5dcc155b-4ae9-4215-9090-c36dfefd0d21)


This driver is designed to adapt effortlessly to other HAL-enabled devices with minor adjustments. Simply modify the timer and GPIO settings to seamlessly integrate with your specific hardware. GPIO definitions are conveniently located in the LCD1602.h file, making the process a breeze.
With this HAL display driver at your disposal, you're poised to unlock the full potential of your LCD1602 display and explore limitless possibilities with your HAL-enabled devices. Happy coding!
