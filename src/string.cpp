#include "MyString.h"
#include <stdexcept>

char String::npos = '\0';

String::String() {
    str_ = new char[1];
    *str_ = '\0';
    size_ = 0;
}

String::String(const char *str) {
    unsigned i = 0;
    const char *p = str;
    while (*(p++) != '\0') {
        ++i;
    }
    char *p_ = str_ = new char[i+1];
    size_ = i;
    for (unsigned j = 0; j <= i; ++j) {
        *(p_++) = *(str++);
    }
}

String::String(const char *str, unsigned count) {
    str_ = new char[count+1];
    char *p = str_;
    size_ = count;
    for (unsigned i = 0; i <= count; ++i) {
        *(p++) = *(str++);
    }
}

String::String(char ch, unsigned count) {
    str_ = new char[count+1];
    char *p = str_;
    size_ = count;
    for (unsigned i = 0; i < count; ++i) {
        *(p++) = ch;
    }
    *(p++) = '\0';
}

String::String(const String &other) {
    char *po = other.str_;
    char *pt = str_= new char[other.size_+1];
    size_ = other.size_;
    for(unsigned i = 0; i < size_; ++i) {
        *(pt++) = *(po++);
    }
    *pt = *po;
}

String::String(String &&other) {
    str_ = other.str_;
    size_ = other.size_;
    other.str_ = &String::npos;
    other.size_ = 0;
}

String::~String() {
    if (str_ != &String::npos) {
        delete[] str_;
    }
}

String &String::operator=(const String &other){
    if (other.size_ > size_) {
        delete [] str_;
        str_ = new char[other.size_+1];
        size_ = other.size_;
    }
    char *po = other.str_;
    char *pt = str_;
    size_ = other.size_;
    for(unsigned i = 0; i < size_; ++i) {
        *(pt++) = *(po++);
    }
    *pt = '\0';
    return *this;
}

String &String::operator=(String &&other){
    delete [] str_;
    str_ = other.str_;
    size_ = other.size_;
    other.str_ = &String::npos;
    other.size_ = 0;
    return *this;
}

String &String::operator+=(const String &suffix) {
    char *str;
    char *tmp = str_;
    char *pt = str = new char[size_+suffix.size_+1];
    char *ps = suffix.str_;
    for(unsigned i = 0; i < size_; ++i) {
        *(pt++) = *(tmp++);
    }
    for(unsigned i = 0; i < suffix.size_; ++i) {
        *(pt++) = *(ps++);
    }
    *pt= '\0';
    delete [] str_;
    size_+= suffix.size_;
    str_ = str;
    return *this;
}

String &String::operator+=(const char *suffix) {
    unsigned size = 0;
    const char *ps = suffix;
    while(*(ps++) != '\0') {
        ++size;
    }
    char *str;
    char *tmp = str_;
    char *pt = str = new char[size_+size+1];
    ps = suffix;
    for(unsigned i = 0; i < size_; ++i) {
        *(pt++) = *(tmp++);
    }
    for(unsigned i = 0; i < size; ++i) {
        *(pt++) = *(ps++);
    }
    *pt = '\0';
    delete [] str_;
    size_+= size;
    str_ = str;
    return *this;
}

String &String::operator+=(char suffix) {
    char *str;
    char *tmp = str_;
    char *pt = str = new char[size_+2];
    char ps = suffix;
    for(unsigned i = 0; i < size_; ++i) {
        *(pt++) = *(tmp++);
    }
    *(pt++) = ps;
    *pt = '\0';
    delete [] str_;
    size_= size_ + 1;
    str_ = str;
    return *this;
}

void String::swap(String &other) {
    char *tmp;
    unsigned size;
    tmp = str_;
    size = size_;
    str_ = other.str_;
    size_ = other.size_;
    other.str_ = tmp;
    other.size_ = size;
}

char &String::operator[](unsigned pos) {
    return *(str_ + pos);
}

const char String::operator[](unsigned pos) const {
    return *(str_ + pos);
}

char &String::at(unsigned pos) {
    if (pos >= size_) {
        throw std::out_of_range("");
    }
    char *pt = str_ + pos;
    return *(pt);
}

const char String::at(unsigned pos) const {
    if (pos >= size_) {
        throw std::out_of_range("");
    }
    char *pt = str_ + pos;
    return *(pt);
}

const char *String::data() const {
    return str_;
}

unsigned String::size() const {
    char *p = this->str_;
    unsigned i = 0;
    while(*(p++) != '\0') {
        ++i;
    }
    return i;
}

bool operator==(const String &lhs, const String &rhs) {
    if (lhs.size_ == rhs.size_) {
        char *pl = lhs.str_;
        char *pr = rhs.str_;
        for(unsigned i = 0; i <= lhs.size_; ++i) {
            if (*(pl++) != *(pr++)) return false;
        }
        return true;
    }
    return false;
}

bool operator<(const String &lhs, const String &rhs) {
    unsigned size;
    lhs.size_ <= rhs.size_ ? size = lhs.size_ : size = rhs.size_;
    for(unsigned i = 0; i < size; ++i) {
        if (*(lhs.str_ + i) < *(rhs.str_ + i)) {
            return true;
        } else if (*(lhs.str_ + i) > *(rhs.str_ + i)) {
            return false;
        }
    }
    return false;
}

String operator+(const String &lhs, const String &rhs) {
    return String(lhs) += rhs;
}

String operator+(const String &lhs, const char *rhs) {
    return String(lhs) += rhs;
}

String operator+(const char *lhs, const String &rhs) {
    return String(rhs) += lhs;
}

bool operator!=(const String &lhs, const String &rhs) {
    return !(lhs == rhs);
}

bool operator<=(const String &lhs, const String &rhs) {
    return (lhs == rhs) || (lhs < rhs);
}

bool operator>(const String &lhs, const String &rhs) {
    return !(lhs <= rhs);
}

bool operator>=(const String &lhs, const String &rhs) {
    return !(lhs < rhs);
}

std::ostream & operator << (std::ostream &stream, const String & A) {
    return stream << A.data();
}
