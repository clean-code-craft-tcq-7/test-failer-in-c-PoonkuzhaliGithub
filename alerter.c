#include <stdio.h>
#include <assert.h>

typedef enum
{
    prod,
    Test
} Environment;
int alertFailureCount = 0;

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

int networkAlertProd(float celcius)
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

float SelectAlertEnvironment(float celcius, Environment environment_e)
{
   float calculated_Value;
    
   if(environment_e == prod)
   {
     calculated_Value = networkAlertProd(celcius);
   }
   else
   {
     calculated_Value = networkAlertStub(celcius);
   }
   return calculated_Value;
}

float convertFarenheitToCelcius(float farenheit)
{
    float celcius = ((farenheit - 32) * 5 )/ 9;
    
    return celcius;
}

void alertInCelcius(float farenheit, Environment environment_e) 
{
    float celcius = convertFarenheitToCelcius(farenheit);    
    int returnCode = SelectAlertEnvironment(celcius,environment_e);    
    if (returnCode != 200) 
    {
        alertFailureCount += 1;      
    }   
}

int main() {
    alertInCelcius(303.6,,Test);
    assert(alertFailureCount == 0);
    alertInCelcius(303.6,prod);
    assert(alertFailureCount == 0);
    alertInCelcius(505.5,prod);
    assert(alertFailureCount == 1);
    alertInCelcius(505.5,Test);
    assert(alertFailureCount == 1);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
