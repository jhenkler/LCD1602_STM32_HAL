Welcome to the HAL display driver for LCD1602, a versatile display solution offering both eight and four-bit modes. This driver empowers you to customize your LCD1602 display effortlessly, all thanks to the user-friendly struct declarations housed in the main.c file. For further reference, you can explore the struct definitions conveniently stored in the LCD1602_conf.h file. Notably, this driver also extends its capabilities by allowing you to create and modify up to 8 custom characters, easily managed within the main.c file.

Let's take a closer look at the connection schematics, ensuring you get your LCD1602 display up and running seamlessly:

Four-Bit Connection:
![LCD1602_4bit](https://github.com/jhenkler/LCD1602_STM32_HAL/assets/147257321/79c4c517-5c79-4c95-91bf-23ec41cfd6da)
![1000002773](https://github.com/jhenkler/LCD1602_STM32_HAL/assets/147257321/44228eb5-22ae-401a-9f87-e3fa7f7ec748)

Eight-Bit Connection:
![LCD1602_8bit](https://github.com/jhenkler/LCD1602_STM32_HAL/assets/147257321/763b9ecc-e389-49f3-8d3c-4004b22febd1)
![1000002775](https://github.com/jhenkler/LCD1602_STM32_HAL/assets/147257321/3a01199e-f5a3-4aa5-8bde-542882a33372)


This driver is designed to adapt effortlessly to other HAL-enabled devices with minor adjustments. Simply modify the timer and GPIO settings to seamlessly integrate with your specific hardware. GPIO definitions are conveniently located in the LCD1602.h file, making the process a breeze.
With this HAL display driver at your disposal, you're poised to unlock the full potential of your LCD1602 display and explore limitless possibilities with your HAL-enabled devices. Happy coding!
