
#include "rgb_app.h"
#include "timer_captureTime.h"
int main(void);
int main(void)
{
    buttonInit(PORTD_ID, 0U);
    LedInit();
    wtimer2_Init();

    while(1)
    {
    }
}


