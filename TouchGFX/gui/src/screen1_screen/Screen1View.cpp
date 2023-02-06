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

void Screen1View::displayBuffer(DataTypeDef *buffer)
{
    // if (buffer[0] == 0)
    // {
    //     return;
    // }

    if (uartMsgBuf[0] == 0)
    {
        return;
    }

    // memset(&textArea1Buffer, 0, TEXTAREA1_SIZE);
    // Unicode::fromUTF8(buffer, textArea1Buffer, TEXTAREA1_SIZE);
    // Unicode::strncpy(textArea1Buffer, (char*)buffer, 16);
    Unicode::strncpy(textArea1Buffer, (char *)uartMsgBuf, TEXTAREA1_SIZE);
    textArea1.invalidate();

    // textArea1Buffer[TEXTAREA1_SIZE - 1] = '\0';
    // memcpy(textArea2Buffer, buffer, TEXTAREA2_SIZE);
    Unicode::fromUTF8(&(buffer->Value) , textArea2Buffer, TEXTAREA2_SIZE-2);
    textArea2Buffer[TEXTAREA2_SIZE - 1] = '\0';

    // if (buffer->Value == 'a')
    // {
    //     Unicode::snprintf(textArea2Buffer, TEXTAREA2_SIZE, "INDEEED!");
    // }
    // Unicode::strncpy(textArea2Buffer, buffer, TEXTAREA2_SIZE);
    textArea2.invalidate();
}

void Screen1View::displayBufferT(uint8_t msg[])
{
    // if (buffer[0] == 0)
    // {
    //     return;
    // }

    if (uartMsgBuf[0] == 0)
    {
        return;
    }

    // memset(&textArea1Buffer, 0, TEXTAREA1_SIZE);
    // Unicode::fromUTF8(buffer, textArea1Buffer, TEXTAREA1_SIZE);
    // Unicode::strncpy(textArea1Buffer, (char*)buffer, 16);
    Unicode::strncpy(textArea1Buffer, (char *)uartMsgBuf, TEXTAREA1_SIZE);
    textArea1.invalidate();

    // textArea1Buffer[TEXTAREA1_SIZE - 1] = '\0';
    // memcpy(textArea2Buffer, buffer, sizeof(buffer));
    // Unicode::fromUTF8(&(buffer->Value) , textArea2Buffer, TEXTAREA2_SIZE-2);
    // textArea2Buffer[TEXTAREA2_SIZE - 1] = '\0';
    Unicode::strncpy(textArea2Buffer, (char *)msg, TEXTAREA2_SIZE);

    if (msg[1] == 'E')
    {
        Unicode::snprintf(textArea3Buffer, TEXTAREA3_SIZE, "INDEEED!");
    }else{
        
        Unicode::snprintf(textArea3Buffer, TEXTAREA3_SIZE, "Test!");
    }
    // Unicode::strncpy(textArea2Buffer, buffer, TEXTAREA2_SIZE);
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