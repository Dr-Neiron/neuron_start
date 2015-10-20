#include "Logger.h"


Logger::Logger():
    _outStream(&std::wcout),
    _isOwner(false)
{
}

Logger::~Logger()
{
    setStream(nullptr, false);
}

void Logger::setStream(std::wostream* stream, bool isOwner)
{
    if (_isOwner)
        delete _outStream;
    _outStream = stream;
    _isOwner = isOwner;
}
