
#ifndef LOGGER
#define LOGGER
#include <fstream>
#include <iostream>

#define INFOLOG(fmt, ...) std::cout << fmt << std::endl;
#define ERRORLOG(fmt, ...) std::cout << fmt << std::endl;

#endif // LOGGER