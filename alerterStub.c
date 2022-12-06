#include <stdio.h>

int networkAlertStub(float celcius) 
{    
    if(celcius <= 200)
    {
        return 200;
    }
    else
    {
        return 500;
    }
}
