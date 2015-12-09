#pragma once
#include <iostream>
#include <stdexcept>

class Logger
{
public:
    Logger();
    virtual ~Logger();

    void setStream(std::ostream* stream, bool isOwner);

    template<typename T>
    const Logger& operator << (const T& object) const;

private:
    std::ostream*  _outStream;
    bool           _isOwner;
};

template <typename T>
const Logger& Logger::operator<<(const T& object) const
{
    if (!_outStream)
        throw std::runtime_error("No stream set for Logger class");
    (*_outStream) << object;
    return *this;
}
