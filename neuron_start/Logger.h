#pragma once
#include <iostream>

class Logger
{
public:
    Logger();
    virtual ~Logger();

    void setStream(std::wostream* stream, bool isOwner);

    template<typename T>
    const Logger& operator << (const T& object) const;

private:
    std::wostream* _outStream;
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
