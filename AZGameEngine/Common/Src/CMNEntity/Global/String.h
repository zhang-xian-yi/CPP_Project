#pragma once
#include <Common/ExportMarcoDefine.h>

namespace CommonNS
{
    //��дString ��ֹģ���ڲ�ʹ�ñ�׼ģ���ʱ��Ҫ����String,��ʱδѰ�ҵ�����ģ��std::string�ķ���

    class CommonDLLAPI String
    {
    public:
        typedef char* iterator;
        typedef const char* const_iterator;
    public:
        //��������ʼ
        const_iterator begin() const;

        const_iterator end() const;

        iterator begin();

        iterator end();

        String(const char* s = "");

        String(const String& s);

        ~String();

        String& operator=(String s);
        //[] д��
        char& operator[](size_t pos);
        //[] ��ȡ
        const char& operator[](size_t pos)const;

        const char* c_str() const;

        void reserve(size_t n);

        void push_back(char n);

        String& operator+=(char n);

        void append(const char* str);

        String& operator+=(const char* str);

        void resize(size_t n, char c = '\0');

        size_t size() const;

        size_t capacity() const;

        bool empty();

        bool operator>(const String& s);

        bool operator==(const String& s);

        bool operator!=(const String& s);

        bool operator>=(const String& s);

        bool operator<(const String& s);

        bool operator<=(const String& s);

        String& insert(size_t pos, const char* str);

        String& eraser(size_t pos, size_t len = npos);

        void clear();

        void swap(String& s);

        size_t find(char c, size_t pos = 0) const;

        size_t find(char* s, size_t pos = 0) const;

    private:
        char* _str;
        size_t _size;
        size_t _capacity;
        const static size_t npos;
    };
}

