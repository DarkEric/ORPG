#include "Consol.h"

#include <stdlib.h>
#include <conio.h>
#include <windows.h>
void SetConsoleFont(int m)
{
    typedef BOOL(WINAPI *SETCONSOLEFONT)(HANDLE, DWORD);
    SETCONSOLEFONT SetConsoleFont;
    HMODULE hmod = GetModuleHandleA("KERNEL32.DLL");
    SetConsoleFont = (SETCONSOLEFONT)GetProcAddress(hmod, "SetConsoleFont");
    if (!SetConsoleFont)  exit(1);//io?ii iiaia?aou ?acia? o?eooa - Win7x64 = 9
    SetConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE), m);
}

void SetConsoleText(int m){
    if (m == 1){
        HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hwnd, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    }
    else
        if (m == 2){
        HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hwnd, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        }
        else if (m==3){
            HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hwnd, 0 | FOREGROUND_INTENSITY);
        }else if(m==4){
            HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hwnd, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
        }
}
