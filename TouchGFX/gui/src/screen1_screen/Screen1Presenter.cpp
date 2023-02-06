#include <gui/screen1_screen/Screen1View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

Screen1Presenter::Screen1Presenter(Screen1View& v)
    : view(v)
{

}

void Screen1Presenter::activate()
{

}

void Screen1Presenter::deactivate()
{

}

void Screen1Presenter::displayBuffer(DataTypeDef* buffer)
{
    view.displayBuffer(buffer);
}

void Screen1Presenter::displayBufferT(uint8_t msg[])
{
    view.displayBufferT(msg);
}
