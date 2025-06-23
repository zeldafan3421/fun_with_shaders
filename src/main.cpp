#include "application.h"

int main(void)
{
#if defined(DEBUG)
    SetTraceLogLevel(LOG_ALL);
#endif

    Application app;
    app.Run();
}