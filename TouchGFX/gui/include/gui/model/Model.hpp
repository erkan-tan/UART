#ifndef MODEL_HPP
#define MODEL_HPP

#ifndef SIMULATOR

#include <cmsis_os2.h>
#include "main.h"

#endif

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
