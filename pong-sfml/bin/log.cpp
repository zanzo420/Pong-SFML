#include "log.h"

#if _DEBUG
#include <iostream>
#endif

void log(char logged[])
{
#if _DEBUG
    std::cout << logged << std::endl;
#endif
}

