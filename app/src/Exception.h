#pragma once

#include <exception>

class LoadGuiException : public std::exception {
public:
    LoadGuiException(const char* str) : str(str){}

    virtual const char* what() const throw(){
        return str;
    }

private:
    const char* str;
};

class FunctionAbsentException : public std::exception {
public:
    FunctionAbsentException(const char* str) : str(str){}

    virtual const char* what() const throw(){
        return str;
    }

private:
    const char* str;
};
