#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <touchgfx/hal/Types.hpp>

#ifndef SIMULATOR
#include <cmsis_os2.h>
#include "main.h"

extern "C"
{
    extern uint8_t aRxBuffer[RXBUFFERSIZE];
    extern uint8_t isRxData;

}
#endif

Model::Model() : modelListener(0)
{
}

void Model::tick()
{
    if (isRxData)
    {
        modelListener->displayBuffer(aRxBuffer);
        isRxData = 0;
    }
    
}
