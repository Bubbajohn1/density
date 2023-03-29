#include <core/logger.h>
#include <core/asserts.h>

int main(void)
{
    DFATAL("Test message");
    DERROR("Test Message");
    DWARN("Test message");
    DINFO("Test Message");
    DDEBUG("Test message");
    DTRACE("Test Message");

    return 0;
}
