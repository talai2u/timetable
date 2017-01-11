#include "utils.h"
#include <iostream>

utils::utils()
{
}

utils::~utils()
{
}

string utils::getPathApp(){
    char result[ PATH_MAX ];
    
    ssize_t count = readlink( "/proc/self/exe", result , PATH_MAX );
        
  
    return string( result, (count > 0) ? count : 0 )+"/";
}




