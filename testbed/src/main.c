#include <core/logger.h>
#include <core/asserts.h>
#include <platform/platform.h>

int main(void)
{
    D_FATAL("Test message");
    D_ERROR("Test Message");
    D_WARN("Test message");
    D_INFO("Test Message");
    D_DEBUG("Test message");
    D_TRACE("Test Message");

    platform_state state;
    if (platform_startup(&state, "Test", 100, 100, 1280, 720))
    {
        while (TRUE)
        {
            platform_pump_messages(&state);
        }
    }
    platform_shutdown(&state);

    return 0;
}
