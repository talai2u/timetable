#ifndef UTILS_H
#define UTILS_H

#include <limits.h>
#include <unistd.h>
#include <string>
#include <vector>


using namespace std;

class utils
{
public:
    utils();
    ~utils();
    
    static string getPathApp();
    
};

#endif // UTILS_H
