#include <gui/screen1_screen/Screen1View.hpp>
#include <cstring>

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

void Screen1View::displayBuffer(uint8_t* buffer)
{
    // Unicode::UnicodeChar temp[30];
    Unicode::fromUTF8(buffer, textArea1Buffer, TEXTAREA1_SIZE);
    // Unicode::strncpy(textArea1Buffer, temp, TEXTAREA1_SIZE);
    textArea1.invalidate();
    memset(buffer, '\0', 5);
}

void Screen1View::buttonClicked()
{
    memset(textArea1Buffer, 0, TEXTAREA1_SIZE);
    textArea1.invalidate();
}