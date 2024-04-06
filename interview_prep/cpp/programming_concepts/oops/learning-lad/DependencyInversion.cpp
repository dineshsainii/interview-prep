#include <iostream>

//Abstract class
class LightBulb
{
    public:
        virtual void turnOn() = 0;
        virtual void turnOff() = 0;
        virtual ~LightBulb() {}
};

//Concrete implementation of light bulb
class IncandescentLightBulb : public LightBulb
{
    public:
        void turnOn() override
        {
            std::cout << "Turning on Incandescent light bulb" << std::endl;
        }

        void turnOff() override
        {
            std::cout << "Turning off incadescent light bulb" << std::endl;
        }
};

class ElectricPowerSwitch
{
    private:
        LightBulb &bulb;
    
    public:
        ElectricPowerSwitch(LightBulb &bulb) : bulb(bulb) {}

        void powerOn()
        {
            bulb.turnOn();
        }

        void powerOff()
        {
            bulb.turnOff();
        }
};

int main()
{
    IncandescentLightBulb bulb;
    ElectricPowerSwitch *powerSwitch = new ElectricPowerSwitch(bulb);
    powerSwitch->powerOn();
    powerSwitch->powerOff();

    delete powerSwitch;

    return 0;

}