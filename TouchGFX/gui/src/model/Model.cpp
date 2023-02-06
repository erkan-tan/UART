#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <touchgfx/hal/Types.hpp>
#include <cstring>

#ifndef SIMULATOR
// #include <cmsis_os2.h>
// #include "main.h"

extern "C"
{
    extern uint8_t aRxBuffer[RXBUFFERSIZE];
    extern uint8_t isRxData;
    extern uint8_t messageReceived;
    extern osMessageQueueId_t myMsgQueueHandle;
}
#endif

Model::Model() : modelListener(0)
{
}

void Model::tick()
{
#ifndef SIMULATOR
    static uint8_t *msgHandler;
    static uint8_t msg[RXBUFFERSIZE];
    static DataTypeDef *message;

    if (myMsgQueueHandle != NULL)
    {
        if (osMessageQueueGet(myMsgQueueHandle, &msg, NULL, 0) == osOK)
        {
            // strncpy(msg, (char*)msgHandler,RXBUFFERSIZE);
            // modelListener->displayBuffer(message);
            modelListener->displayBufferT(msg);
            
            // memset(msgHandler, 0, 16);
            // messageReceived = 1;
        }
    }


#endif /* SIMULATOR */

}
