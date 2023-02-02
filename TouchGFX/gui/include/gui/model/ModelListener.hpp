#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>
#include <touchgfx/hal/Types.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}
    virtual void displayBuffer(uint8_t* buffer) {}
    void bind(Model* m)
    {
        model = m;
    }
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
