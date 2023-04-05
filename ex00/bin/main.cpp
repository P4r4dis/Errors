#include "../include/Errors.hpp"
#include <iostream>

int main(void)
{
    try
    {
        throw MissionCriticalError("Power failure");
    }
    catch (const NasaError& e)
    {
        std::cerr << "Error message: " << e.what() << std::endl;
        std::cerr << "Component name: " << e.getComponent() << std::endl;
    }
    try
    {
        throw LifeCriticalError("LifeCriticalError failure");
    }
    catch (const NasaError& e)
    {
        std::cerr << "Error message: " << e.what() << std::endl;
        std::cerr << "Component name: " << e.getComponent() << std::endl;
    }
    try
    {
        throw UserError("UserError failure", "UserError component");
    }
    catch (const NasaError& e)
    {
        std::cerr << "Error message: " << e.what() << std::endl;
        std::cerr << "Component name: " << e.getComponent() << std::endl;
    }
        try
    {
        throw CommunicationError("CommunicationError failure");
    }
    catch (const NasaError& e)
    {
        std::cerr << "Error message: " << e.what() << std::endl;
        std::cerr << "Component name: " << e.getComponent() << std::endl;
    }
    return 0;
}