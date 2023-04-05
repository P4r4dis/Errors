#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include <iostream>
#include "../test_include/test_Errors.hpp"

void    redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Errors, test_Errors_MissionCriticalError, .init = redirect_all_stdout)
{
try
    {
        // Mission critical error with default component name
        throw MissionCriticalError("Power failure");
    }
    catch (const NasaError& e)
    {
        std::cerr << "Error message: " << e.what() << std::endl;
        std::cerr << "Component name: " << e.getComponent() << std::endl;
    }
    cr_assert_stderr_eq_str("Error message: Power failure\n"
    "Component name: Unknown\n");
}

Test(Errors, test_Errors_LifeCriticalError, .init = redirect_all_stdout)
{
    try
    {
        // Mission critical error with default component name
        throw LifeCriticalError("LifeCriticalError failure");
    }
    catch (const NasaError& e)
    {
        std::cerr << "Error message: " << e.what() << std::endl;
        std::cerr << "Component name: " << e.getComponent() << std::endl;
    }
    cr_assert_stderr_eq_str("Error message: LifeCriticalError failure\n"
    "Component name: Unknown\n");
}

Test(Errors, test_Errors_UserError, .init = redirect_all_stdout)
{
    try
    {
        // Mission critical error with default component name
        throw UserError("UserError failure", "UserError component");
    }
    catch (const NasaError& e)
    {
        std::cerr << "Error message: " << e.what() << std::endl;
        std::cerr << "Component name: " << e.getComponent() << std::endl;
    }
    cr_assert_stderr_eq_str("Error message: UserError failure\n"
    "Component name: UserError component\n");
}

Test(Errors, test_Errors_CommunicationError, .init = redirect_all_stdout)
{
    try
    {
        // Mission critical error with default component name
        throw CommunicationError("CommunicationError failure");
    }
    catch (const NasaError& e)
    {
        std::cerr << "Error message: " << e.what() << std::endl;
        std::cerr << "Component name: " << e.getComponent() << std::endl;
    }
    cr_assert_stderr_eq_str("Error message: CommunicationError failure\n"
    "Component name: CommunicationDevice\n");
}