
#include "lib/STD_Types.h"
#include "lib/BIT_MATH.h"
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/GIE_DRIVER/GIE_Interface.h"
#include "MCAL/Timers/Timers_Interface.h"
#include "MCAL/USART/USART_Interface.h"
#include <util/delay.h>
#include "HAL/Warning_System/Wrning_System_Interface.h"
#include "HAL/Rooms_Light/Rooms_Light_Interface.h"
#include "HAL/DC_Fan/Fan_Interface.h"
#include "HAL/CLCD/CLCD_interface.h"
#include "HAL/Servo/Servo_Interface.h"
#include "HAL/LM35/LM32_INTERFACE.h"
#include "HAL/HC_05/HC_05_Interface.h"
#include "HAL/LDR/LDR_Interface.h"

int main() {
	u8 usernameAttempts = 0;
	u8 passwordAttempts = 0;
	u8 MAX_USERNAME_ATTEMPTS = 3;
	u8 MAX_PASSWORD_ATTEMPTS = 3;
	u16 BLOCK_TIME = 10;
	u8 options;
	u16 LDR;

	BluetoothModule_Init();
	Warning_LED_Init();
	Warning_Buzzer_Init();
	Servo_voidInit();
	CLCD_voidInitPins();
	ADC_voidInit();
	RoomLights_Init();
	Fan_Init();
	TIM0_voidNormalMode();
	TIM0_voidCTCMode();
	USART_voidInit();
	LM_35_Init();
	LDR_Init();

	USART_voidRecieveString("start");
	CLCD_voidInit();
	CLCD_voidGoToXy(0, 0);
	CLCD_voidSendString("Hello :)");
	_delay_ms(1000);

	USART_voidSendString("Welcome to the Smart Home\r\n");
	_delay_ms(2000);
	CLCD_voidClear();
	CLCD_voidSendString("Sent Welcome Msg");
	_delay_ms(2000);
	CLCD_voidClear();

	u8 receivedString[100];
	u8 password[100];
	u8 *Users[] = {"sara", "nada", "nouran", "Lara", "Mohamed", "Zienab", "Ahmed", "Asmaa", "Mariam", "Fatma"};
	u8 *Passwords[] = {"1111", "2222", "3333", "4444", "5555", "6666", "7777", "8888", "9999", "1234"};
	u16 UsersSize = sizeof(Users) / sizeof(Users[0]);
	u16 userIndex;
	TIM0_NormalSetCallBack(&LM35_FireAlarmSystem);
	TIM0_CTCSetCallBack(&LDR_GardenLights);
	GIE_voidEnable();
	u16 TempValue = LM35_u16_TempValue();
	CLCD_voidClear();
	CLCD_voidGoToXy(0, 0);
	CLCD_voidSendString("Temperature:");
	CLCD_voidGoToXy(0, 12);
	CLCD_voidSendNumber(TempValue);
	CLCD_voidGoToXy(0, 14);
	CLCD_voidSendString("C");
	_delay_ms(2000);

	LDR = LDR_u16_LDRValue();
	CLCD_voidClear();
	CLCD_voidGoToXy(0, 0);
	CLCD_voidSendString("LDR:");
	CLCD_voidGoToXy(0, 5);
	CLCD_voidSendNumber(LDR);
	_delay_ms(2000);

	while (1) {
		if (usernameAttempts >= MAX_USERNAME_ATTEMPTS) {
			Warning_LED_On();
			Warning_Buzzer_On();
			CLCD_voidClear();
			CLCD_voidSendString("Too many");
			CLCD_voidGoToXy(1, 0);
			CLCD_voidSendString("username attempts");
			DisplayCountdown(BLOCK_TIME);
			Warning_LED_Off();
			Warning_Buzzer_Off();
			usernameAttempts = 0; // Reset username attempts counter
			continue;
		}

		CLCD_voidClear();
		CLCD_voidSendString("Enter your");
		CLCD_voidGoToXy(1, 0);
		CLCD_voidSendString("username:");

		USART_voidRecieveString(receivedString);

		CLCD_voidClear();
		CLCD_voidSendString("Received:");
		CLCD_voidGoToXy(1, 0);
		CLCD_voidSendString(receivedString);
		_delay_ms(2000);
		userIndex = Check_UserName(receivedString, Users, UsersSize);

		if (userIndex != -1) {
			usernameAttempts = 0; // Reset username attempts counter

			while (1) {
				if (passwordAttempts >= MAX_PASSWORD_ATTEMPTS) {
					Warning_LED_On();
					Warning_Buzzer_On();
					CLCD_voidClear();
					CLCD_voidSendString("Too many");
					CLCD_voidGoToXy(1, 0);
					CLCD_voidSendString("password attempts");
					DisplayCountdown(BLOCK_TIME);
					Warning_LED_Off();
					Warning_Buzzer_Off();
					passwordAttempts = 0; // Reset password attempts counter
					break;
				}

				CLCD_voidClear();
				CLCD_voidSendString("Enter Your Pass:");
				USART_voidRecieveString(password);

				CLCD_voidClear();
				CLCD_voidSendString("Pass:");
				CLCD_voidGoToXy(1, 0);
				CLCD_voidSendString("****");
				_delay_ms(2000);

				if (compareString(password, Passwords[userIndex])) {
					CLCD_voidClear();
					CLCD_voidSendString("Access Granted");
					passwordAttempts = 0; // Reset password attempts counter
					_delay_ms(2000);

					// Option selection loop
					while (1) {
						USART_voidSendString("Your Options:\r\n");
						USART_voidSendString("A- Turn On Room 1 Lights\r\n");
						USART_voidSendString("B- Turn Off Room 1 Lights\r\n");
						USART_voidSendString("C- Turn On Room 2 Lights\r\n");
						USART_voidSendString("D- Turn Off Room 2 Lights\r\n");
						USART_voidSendString("E- Turn On Room 3 Lights\r\n");
						USART_voidSendString("F- Turn Off Room 3 Lights\r\n");
						USART_voidSendString("G- Open the Door\r\n");
						USART_voidSendString("H- Close the Door\r\n");
						USART_voidSendString("P- Open the Fan\r\n");
						USART_voidSendString("S- Close the Fan\r\n");
						USART_voidSendString("J- Logout\r\n");
						CLCD_voidClear();
						CLCD_voidGoToXy(0, 4);
						CLCD_voidSendString("Enter Your");
						CLCD_voidGoToXy(1, 5);
						CLCD_voidSendString("option:");

						options = USART_voidRecieveByte(); // Wait for user option

						switch (options) {
						case 'A':
							Room1_Light_On();
							CLCD_voidClear();
							CLCD_voidGoToXy(0, 5);
							CLCD_voidSendString("Room 1");
							CLCD_voidGoToXy(1, 0);
							CLCD_voidSendString("Light is On");
							_delay_ms(2000);
							break;
						case 'B':
							Room1_Light_Off();
							CLCD_voidClear();
							CLCD_voidGoToXy(0, 5);
							CLCD_voidSendString("Room 1");
							CLCD_voidGoToXy(1, 0);
							CLCD_voidSendString("Light is Off");
							_delay_ms(2000);
							break;
						case 'C':
							Room2_Light_On();
							CLCD_voidClear();
							CLCD_voidGoToXy(0, 5);
							CLCD_voidSendString("Room 2");
							CLCD_voidGoToXy(1, 0);
							CLCD_voidSendString("Light is On");
							_delay_ms(2000);
							break;
						case 'D':
							Room2_Light_Off();
							CLCD_voidClear();
							CLCD_voidGoToXy(0, 5);
							CLCD_voidSendString("Room 2");
							CLCD_voidGoToXy(1, 0);
							CLCD_voidSendString("Light is Off");
							_delay_ms(2000);
							break;
						case 'E':
							Room3_Light_On();
							CLCD_voidClear();
							CLCD_voidGoToXy(0, 5);
							CLCD_voidSendString("Room 3");
							CLCD_voidGoToXy(1, 0);
							CLCD_voidSendString("Light is On");
							_delay_ms(2000);
							break;
						case 'F':
							Room3_Light_Off();
							CLCD_voidClear();
							CLCD_voidGoToXy(0, 5);
							CLCD_voidSendString("Room 3");
							CLCD_voidGoToXy(1, 0);
							CLCD_voidSendString("Light is Off");
							_delay_ms(2000);
							break;
						case 'G':
							Open_Door();
							CLCD_voidClear();
							CLCD_voidSendString("Door is Opened");
							_delay_ms(2000);
							break;
						case 'H':
							Close_Door();
							CLCD_voidClear();
							CLCD_voidSendString("Door is Closed");
							_delay_ms(2000);
							break;
						case 'P':
							Fan_On();
							CLCD_voidClear();
							CLCD_voidSendString("Fan is Opened");
							_delay_ms(2000);
							break;
						case 'S':
							Fan_Off();
							CLCD_voidClear();
							CLCD_voidSendString("Fan is Closed");
							_delay_ms(2000);
							break;
						default:
							CLCD_voidClear();
							CLCD_voidSendString("Invalid Option");
							_delay_ms(2000);
							break;
						}

						if (options == 'J') {
							break; // Break the outer while loop and prompt for username again
						}
					}

					// Exit the password attempt loop
					break;
				} else {
					CLCD_voidClear();
					CLCD_voidSendString("Invalid Pass");
					passwordAttempts++;
				}
				_delay_ms(2000);
			}
		} else {
			CLCD_voidClear();
			CLCD_voidSendString("Invalid User");
			usernameAttempts++;
			_delay_ms(2000);
		}
	}
}
