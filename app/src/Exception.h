#pragma once

#include <exception>

class LoadGuiException : public std::exception {
public:
    LoadGuiException(const char* str) : m_str(str) {}

    virtual const char* what() const noexcept {
        return m_str;
    }

private:
    const char* m_str;
};

class FunctionAbsentException : public std::exception {
public:
    FunctionAbsentException(const char* str) : m_str(str) {}

    virtual const char* what() const noexcept {
        return m_str;
    }

private:
    const char* m_str;
};
