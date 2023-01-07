#include "String.h"

#include <cassert>
#include <cstring>
#include <memory>

namespace CommonNS
{
    //静态变量定义
    const size_t String::npos = -1;

    String::const_iterator String::begin() const
    {
        return _str;
    }

    String::const_iterator String::end() const
    {
        return _str + _size;
    }

    String::iterator String::begin()
    {
        return _str;
    }

    String::iterator String::end()
    {
        return _str + _size;
    }

    String::String(const char* s = "")
        : _size(strlen(s)),
        _capacity(_size)
    {
        _str = new char[_capacity + 1];
        strcpy(_str, s);
    }

    String::String(const String& s)
        : _str(nullptr),
        _size(0),
        _capacity(0)
    {
        String tmp(s._str);
        swap(tmp);
    }

    String::~String()
    {
        delete[] _str;
        _str = nullptr;
        _size = _capacity = 0;
    }

    String& String::operator=(String s)
    {
        swap(s);
        return *this;
    }

    char& String::operator[](size_t pos)
    {
        assert(pos < _size);

        return *(_str + pos);
    }

    const char& String::operator[](size_t pos) const
    {
        assert(pos < _size);
        return *(_str + pos);
    }

    const char* String::c_str() const
    {
        return _str;
    }

    void String::reserve(size_t n)
    {
        if (n > _capacity)
        {
            char* tmp = new char[n + 1];
            strcpy(tmp, _str);
            delete[] _str;
            _str = tmp;
            _capacity = n;
        }
    }

    void String::push_back(char n)
    {
        if (_size == _capacity)
        {
            reserve(_capacity == 0 ? 4 : _capacity * 2);
        }
        _str[_size++] = n;
        _str[_size] = '\0';
    }

    String& String::operator+=(char n)
    {
        push_back(n);
        return *this;
    }

    void String::append(const char* str)
    {
        size_t len = _size + strlen(str);
        if (len > _capacity)
        {
            reserve(len);
        }
        strcpy(_str + _size, str);
        _size = len;
    }

    String& String::operator+=(const char* str)
    {
        append(str);
    }

    void String::resize(size_t n, char c = '\0')
    {
        if (n > _capacity)
        {
            reserve(n);
        }
        for (size_t i = _size; i < n; ++i)
        {
            _str[i] = c;
        }
        _size = n;
        _str[_size] = '\0';
    }

    size_t String::size() const
    {
        return _size;
    }

    size_t String::capacity() const
    {
        return _capacity;
    }

    bool String::empty()
    {
        return 0 == _size;
    }

    bool String::operator>(const String& s)
    {
        return strcmp(_str, s.c_str());
    }

    bool String::operator==(const String& s)
    {
        return strcmp(_str, s.c_str()) == 0;
    }

    bool String::operator!=(const String& s)
    {
        return !(*this == s);
    }

    bool String::operator>=(const String& s)
    {
        return *this > s || *this == s;
    }

    bool String::operator<(const String& s)
    {
        return !(*this >= s);
    }

    bool String::operator<=(const String& s)
    {
        return !(*this > s);
    }

    String& String::insert(size_t pos, const char* str)
    {
        assert(pos <= _size);
        size_t len = strlen(str);
        if (len + _size > _capacity)
        {
            reserve(len + _size);
        }

        size_t end = _size + len;
        while (end != pos + len - 1)
        {
            _str[end] = _str[end - len];
            --end;
        }

        strncpy(_str + pos, str, len);
        _size += len;
        return *this;
    }

    String& String::eraser(size_t pos, size_t len = npos)
    {
        assert(pos < _size);

        if (len == npos || pos + len >= _size)
        {
            _str[pos] = '\0';
            _size = pos;
        }
        else
        {
            size_t begin = pos + len;
            while (begin <= _size)
            {
                _str[begin - len] = _str[begin];
                begin++;
            }
            _size = _size - len;
        }
        return *this;
    }

    void String::clear()
    {
        _size = 0;
        _str[0] = '\0';
        _capacity = 0;
    }

    void String::swap(String& s)
    {
        std::swap(_str, s._str);
        std::swap(_size, s._size);
        std::swap(_capacity, s._capacity);
    }

    size_t String::find(char c, size_t pos = 0) const
    {
        while (pos < _size)
        {
            if (_str[pos] == c)
            {
                return pos;
            }
            ++pos;
        }
        return npos;
    }

    size_t String::find(char* s, size_t pos = 0) const
    {
        const char* p = strstr(_str + pos, s);
        if (p == nullptr)
        {
            return npos;
        }
        else
        {
            return p - _str;
        }
    }
}