#include "../include/Errors.hpp"

NasaError::NasaError(std::string const &message, std::string const &component) noexcept
    :   _message(message),
        _component(component)
{}

std::string const &NasaError::getComponent(void) const
{
    return _component;
}

const char *NasaError::what(void) const noexcept
{
    return _message.data();    
}
//////////////////////////////////////////////////////////////////////////////
MissionCriticalError::MissionCriticalError(std::string const &message, std::string const &component)
    :   NasaError(message, component)
{}
//////////////////////////////////////////////////////////////////////////////
LifeCriticalError::LifeCriticalError(std::string const &message, std::string const &component)
    :   NasaError(message, component)
{}
//////////////////////////////////////////////////////////////////////////////
UserError::UserError(std::string const &message, std::string const &component)
    :   NasaError(message, component)
{}
//////////////////////////////////////////////////////////////////////////////
CommunicationError::CommunicationError(std::string const &message)
    :   NasaError(message, "CommunicationDevice")
{}

std::string const &CommunicationError::getComponent(void) const
{
    return NasaError::getComponent();
}