#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <touchgfx/hal/Types.hpp>
#include <cstring>

#ifndef SIMULATOR

extern "C"
{
    extern osMessageQueueId_t myMsgQueueHandle;
}
#endif

Model::Model() : modelListener(0)
{
}

void Model::tick()
{
#ifndef SIMULATOR
    static uint8_t msg[RXBUFFERSIZE];

    if (myMsgQueueHandle != NULL)
    {
        if (osMessageQueueGet(myMsgQueueHandle, &msg, NULL, 0) == osOK)
        {
            modelListener->displayMsg(msg);
        }
    }


#endif /* SIMULATOR */

}
