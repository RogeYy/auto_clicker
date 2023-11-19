#include <iostream>
#include <Windows.h>

struct AutoMain {
    bool A;
    bool U;
    bool T;
    bool O;
};


bool RIGHTAUTOCLICK = false, LEFTAUTOCLICK = false, ONECLICK = true, FIRSTSKILLCLICK = false;
AutoMain automain;


bool LeftButton()
{
    return (GetKeyState(VK_LBUTTON) & 0x8000);
}

bool RightButton()
{
    return (GetKeyState(VK_RBUTTON) & 0x8000);
}

void ClickLeftButton() 
{
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}
void ClickRightButton() 
{
    mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
}
void ClickMouse2()
{
    keybd_event('A', 0, 0, 0);
    keybd_event('A', 0, KEYEVENTF_KEYUP, 0);
}
void UppAllButton()
{
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
}
void OneLeftClickButton() 
{
}

int main()
{

    while (true)
    {
        OneLeftClickButton();
        if (GetKeyState(VK_XBUTTON2) & 0x8000 && RightButton())
        {
            RIGHTAUTOCLICK = true;
        } 
        if (GetKeyState(VK_XBUTTON2) & 0x8000 && LeftButton())
        {
            LEFTAUTOCLICK = true;
        }
        if (GetKeyState(VK_UP) & 0x8000)
        {
            FIRSTSKILLCLICK = true;
        }
        if (GetKeyState(VK_XBUTTON1) & 0x8000)
        {
            RIGHTAUTOCLICK = false;
            LEFTAUTOCLICK = false;
            FIRSTSKILLCLICK = false;
            UppAllButton();
        }

        if (RIGHTAUTOCLICK)
        { 
            ClickRightButton();
            Sleep(100);
        }
        if (LEFTAUTOCLICK)
        {
            ClickLeftButton();
            Sleep(40);
        }
        if (FIRSTSKILLCLICK)
        {
            ClickMouse2();
            Sleep(230);
        }
    }
}