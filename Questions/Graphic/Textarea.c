#include "graphics.h"  
#include "extgraph.h"  
#include "genlib.h"  
#include "simpio.h"  
#include "strlib.h"  
#include "conio.h"  
#include <stdio.h>  
#include <stdlib.h>  
#include <stddef.h>  
  
#include <windows.h>  
#include <olectl.h>  
#include <stdio.h>  
#include <mmsystem.h>  
#include <wingdi.h>  
#include <ole2.h>  
#include <ocidl.h>  
#include <winuser.h>  
  
#define TIMER_BLINK 1
#define Mseconds 500
  
static char Text[100];  
static int textlen = 0;  
static int location=-1;  
  
static bool isBlink = FALSE;    
static bool isDisplay = FALSE;   
  
void KeyboardEventProcess(int key, int event);  
void CharEventProcess(char c);  
void TimerEventProcess(int timerID);  
  
void Main()   
{  
    InitConsole();  
    InitGraphics();           
    MovePen(2, 4);  
    registerKeyboardEvent(KeyboardEventProcess);  
    registerCharEvent(CharEventProcess);  
    registerTimerEvent(TimerEventProcess);  
    if (isBlink) startTimer(TIMER_BLINK, Mseconds);  
    isBlink = !isBlink;  
    if (isBlink ) startTimer(TIMER_BLINK, Mseconds);  
    else cancelTimer(TIMER_BLINK);  
}  
  
void CharEventProcess(char key)  
{  
//  printf("textlen=%d,text=%s\n",textlen,Text);  
    if(textlen >= 99 || GetCurrentX() >= GetWindowWidth() - 0.2) 
    return;  
    if(key == VK_BACK || key == VK_DELETE)
    return;  
    if(key=='\r'){  
        SetEraseMode(TRUE);  
        if(isBlink && isDisplay){  
            DrawTextString("_");  
            MovePen(GetCurrentX() - TextStringWidth("_"), GetCurrentY());  
        }  
        InitConsole();  
        printf("%s\n", Text);  
        FreeConsole();  
        MovePen(GetCurrentX()-TextStringWidth(Text), GetCurrentY());  
        DrawTextString(Text);  
        SetEraseMode(FALSE);  
        MovePen(GetCurrentX() - TextStringWidth(Text), GetCurrentY());  
        textlen = 0;  
        location = -1;  
        Text[0] = '\0';  
    }  
    else{  
        char str[2] = {0,0};  
        str[0] = key;  
        if(location == textlen - 1){  
            Text[textlen++] = key;  
            Text[textlen] = '\0';  
            DrawTextString(str);  
            location++;  
        }  
        else{  
            int i;  
            string s1;  
            s1 = SubString(Text, location+1, textlen);   
            SetEraseMode(TRUE);  
            DrawTextString(s1);  
            SetEraseMode(FALSE);  
            MovePen(GetCurrentX() - TextStringWidth(s1), GetCurrentY());  
            DrawTextString(str);  
            DrawTextString(s1);  
            MovePen(GetCurrentX() - TextStringWidth(s1), GetCurrentY());  
            textlen++;  
            location++;  
            for(i = textlen;i >= location+1; i--){  
                Text[i] = Text[i - 1];  
            }  
            Text[location] = key;  
        }  
        if (isBlink && isDisplay){  
            SetEraseMode(TRUE);  
            MovePen(GetCurrentX() - TextStringWidth(str), GetCurrentY());  
            DrawTextString("_");  
            MovePen(GetCurrentX() - TextStringWidth("_"), GetCurrentY());  
            SetEraseMode(FALSE);  
            DrawTextString(str);  
        }  
        else{  
            MovePen(GetCurrentX() - TextStringWidth(str), GetCurrentY());  
            DrawTextString(str);  
        }  
    }     
}  
void KeyboardEventProcess(int key,int event)  
{  
    static char str[2] = {0,0};  
    switch(event){  
        case KEY_DOWN:  
            if(key == VK_DELETE || key == VK_BACK){  
                if(location<0)
                return;  
                int i;  
                SetEraseMode(TRUE);  
                if (isBlink && isDisplay) {  
                   MovePen(GetCurrentX(), GetCurrentY());  
                   DrawTextString("_");  
                   MovePen(GetCurrentX() - TextStringWidth("_"), GetCurrentY());  
                }  
                str[0] = Text[location];  
                MovePen(GetCurrentX() - TextStringWidth(str), GetCurrentY());  
                DrawTextString(str);  
                if(location == textlen)MovePen(GetCurrentX() - TextStringWidth(str), GetCurrentY());  
                else{  
                    string s1,s2;  
                    s1 = SubString(Text, location+1, textlen);  
                    s2 = SubString(Text, location, textlen);   
                    SetEraseMode(TRUE);  
                    DrawTextString(s1);  
                    SetEraseMode(FALSE);  
                    MovePen(GetCurrentX() - TextStringWidth(s2), GetCurrentY());  
                    DrawTextString(s1);  
                    MovePen(GetCurrentX() - TextStringWidth(s1), GetCurrentY());  
                }  
                for(i = location; i < textlen; i++){  
                    Text[i] = Text[i + 1];  
                }  
                Text[--textlen] = '\0';  
                location--;  
                SetEraseMode(FALSE);                      
            }  
            else if(key == VK_LEFT){  
                if(location < 0)
                return;  
                if (isBlink && isDisplay) {  
                    SetEraseMode(TRUE);  
                    MovePen(GetCurrentX(), GetCurrentY());  
                    DrawTextString("_");  
                    SetEraseMode(FALSE);  
                    MovePen(GetCurrentX() - TextStringWidth("_"), GetCurrentY());  
                }  
                str[0] = Text[location];  
                MovePen(GetCurrentX() - TextStringWidth(str), GetCurrentY());  
                location--;  
            }  
            else if(key == VK_RIGHT){  
                if(location >= textlen)
                return;   
                if (isBlink && isDisplay) {  
                    SetEraseMode(TRUE);  
                    MovePen(GetCurrentX(), GetCurrentY());  
                    DrawTextString("_");  
                    SetEraseMode(FALSE);  
                    MovePen(GetCurrentX() - TextStringWidth("_"), GetCurrentY());  
                }  
                str[0] = Text[location+1];  
                MovePen(GetCurrentX() + TextStringWidth(str), GetCurrentY());  
                location++;  
            }  
    }  
}  
  
void TimerEventProcess(int timerID)  
{  
    double x, y;  
    bool erasemode;  
    switch (timerID) {  
        case TIMER_BLINK:  
        if (!isBlink) return;  
        erasemode = GetEraseMode();  
        x = GetCurrentX();  
        y = GetCurrentY();  
        SetEraseMode(isDisplay);  
        DrawTextString("_");  
        MovePen(x, y);  
        if(textlen-1 != location){  
            char str[2] = {0,0};  
            str[0] = Text[location+1];  
            SetEraseMode(FALSE);  
            DrawTextString(str);  
            MovePen(x,y);  
        }  
          SetEraseMode(erasemode);  
          isDisplay = !isDisplay;  
          break;  
        default:  
          break;  
      }  
}  
