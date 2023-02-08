#include <gui/screen1_screen/Screen1View.hpp>
#include <cstring>

#ifndef SIMULATOR
#include "main.h"

extern "C"
{
    extern uint8_t uartMsgBuf[RXBUFFERSIZE];
}
#endif

Screen1View::Screen1View()
{
}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::displayMsg(uint8_t msg[])
{
    Unicode::UnicodeChar key[RXBUFFERSIZE];
    Unicode::snprintf(key, RXBUFFERSIZE, "Apple");

    if (uartMsgBuf[0] == 0)
    {
        return;
    }
    // Accessing uartMsgBuf directly imported
    Unicode::strncpy(textArea1Buffer, (char *)uartMsgBuf, TEXTAREA1_SIZE);
    // Accessing msg from MVP!
    Unicode::strncpy(textArea2Buffer, (char *)msg, TEXTAREA2_SIZE);

    // if (msg[1] == 'E')
    // {
    //     Unicode::snprintf(textArea3Buffer, TEXTAREA3_SIZE, "msg[0] == 'E'!!");
    // }else{

    //     Unicode::snprintf(textArea3Buffer, TEXTAREA3_SIZE, "msg[1] != 'E'!!");
    // }

    if (Unicode::strncmp(key, textArea2Buffer, RXBUFFERSIZE) == 0)
    {
        Unicode::snprintf(textArea3Buffer, TEXTAREA3_SIZE, "Key and message match!");
    }
    else
    {
        Unicode::snprintf(textArea3Buffer, TEXTAREA3_SIZE, "Key and message unmatch! (%s)", key);
    }
    textArea3.setWideTextAction(touchgfx::WIDE_TEXT_WORDWRAP);

    textArea1.invalidate();
    textArea2.invalidate();
    textArea3.invalidate();
}

void Screen1View::buttonClicked()
{
    memset(textArea1Buffer, 0, TEXTAREA1_SIZE);
    textArea1.invalidate();
    memset(textArea2Buffer, 0, TEXTAREA1_SIZE);
    textArea2.invalidate();
}