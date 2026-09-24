#include <iostream>
#define USE_OS

class error : public std::exception {
private:
    std::string msg;

public:
    explicit error(const char *_msg_) : msg(_msg_) {}

    const char *toString() {
        return msg.c_str();
    }
};

template<class T>
class ArrayList {
private:
    T *data;
    int len;

public:
    ArrayList(int length) {
        if (length < 0)
            throw error("invalid length");

        len = length;
        data = new T[len];
    }

    ArrayList(T* arr, int length) {
        if (length < 0)
            throw error("invalid length");

        len = length;
        data = new T[len];

        for (int i = 0; i < len; ++i)
            data[i] = arr[i];
    }

    ArrayList(const ArrayList &other) {
        len = other.len;
        data = new T[len];
        for (int i = 0; i < len; i++)
            data[i] = other.data[i];
    }

    int size() const {return len;}

    ~ArrayList() {
        delete[] data;
    }

    T &operator[](int index) {
        if (index < 0 || index >= len)
            throw error("index out of bound");

        return data[index];
    }

    const T &operator[](int index) const {
        if (index < 0 || index >= len)
            throw error("index out of bound");

        return data[index];
    }

    // 这里没有引用！
    ArrayList operator+(const ArrayList &other) const {
        ArrayList re(len + other.len);

        for (int i = 0; i < len; i++) 
            re[i] = data[i];
        for (int i = 0; i < other.len; i++)
            re[i + len] = other.data[i];

        return re;
    }

    ArrayList &operator=(const ArrayList &other) {
        if (this == &other)
            return *this;
        
        delete[] data;
        len = other.len;
        data = new T[len];

        for (int i = 0; i < len; i++) {
            data[i] = other.data[i];
        }

        return *this;
    }

    bool operator==(const ArrayList &other) const {
        if (len != other.len)
            return false;

        for (int i = 0; i < len; i++) {
            if (data[i] != other.data[i]) {
                return false;
            }
        }

        return true;
    }

    bool operator!=(const ArrayList &other) const {
        return !((*this) == other);
    }

    
};

template <class T>
std::ostream &operator<<(std::ostream &os, const ArrayList<T> &list) {
    for (int i = 0; i < list.size(); ++i) {
        if (i != 0)
            os << ' ';
        os << list[i];
    }
    return os;
}

int main() {
    return 0;
}
