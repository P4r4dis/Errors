#pragma once

#include <string>

class NasaError
{
    private:
        std::string _message;

    public:
        NasaError(std::string const &message, std::string const &component = "Unknown");

        std::string const &getComponent() const;
};

class MissionCriticalError
{
    public:
        MissionCriticalError(std::string const &message, std::string const &component = "Unknown");
};

class LifeCriticalError
{
    public:
        LifeCriticalError(std::string const &message, std::string const &component = "Unknown");
};

class UserError
{
    public:
        UserError(std::string const &message, std::string const &component = "Unknown");
};

class CommunicationError
{
    public:
        CommunicationError(std::string const &message);
};
