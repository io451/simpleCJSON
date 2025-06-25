
# Simple сJSON

A very simple and lightweight library, that can help easily read JSON data.

Based on [cJSON](https://github.com/DaveGamble/cJSON) library.

sJSON has been written for my other project [New Order](https://github.com/io451/neworder)





## Installation

Download cJSON and put in your include folder.

Download sJS.c and sJS.h files and put them in your include folder with cJSON. 
    
## Usage/Examples

```C
#include <stdio.h>
#include "sJS.h" // You don't need to include cJSON, cJSON is included in sJSON header file

int main(void)
{
    char *str = sJSGetStringValue("file.json","block","string");
    printf("String: %s",str);
    return 0;
}
```

