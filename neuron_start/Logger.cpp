#include "Logger.h"
#include <iostream>


Logger::Logger():
    _outStream(&std::cout),
    _isOwner(false)
{
}

Logger::~Logger()
{
    setStream(nullptr, false);
}

void Logger::setStream(std::ostream *stream, bool isOwner)
{
    if (_isOwner)
        delete _outStream;
    _outStream = stream;
    _isOwner = isOwner;
}
