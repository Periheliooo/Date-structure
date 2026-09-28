#ifndef EVIL_HPP
#define EVIL_HPP

#include <iostream>
using namespace std;

class Evil{
private:
    int st, ed, val;
    int *data;

public:
//构造函数
//下标运算符重载
//赋值运算符重载
//前缀++重载
//后缀++重载
//输出重载
//析构函数
    Evil(int s = 0, int e = 0, int v = 0)
        : st(s), ed(e), val(v) {data = new int[ed - st + 1]();}

    Evil(const Evil& other) {
        st = other.st;
        ed = other.ed;
        val = other.val;
        data = new int[ed - st + 1];
        for (int i = 0; i < ed-st+1; i++) {
            data[i] = other.data[i];
        }
    }

    int& operator[](int i) {
        if (i < st || i > ed)
            return data[0];
        return data[i - st];
    }


    Evil& operator=(const Evil& other) {
        if (this == &other)
            return *this;

        int* newData = new int[other.ed - other.st + 1];
        for (int i = 0; i <= other.ed - other.st; ++i)
            newData[i] = other.data[i];
        delete[] data;

        st = other.st;
        ed = other.ed;
        if (val < other.val)
            val = other.val;
        data = newData;
        return *this;
    }

    /*
    Evil& operator++();     // ++a
    Evil operator++(int);   // a++
    */
    Evil& operator++() {
        val++;
        return *this;
    }

    Evil operator++(int) {
        Evil re = *this;
        val++;
        return re;
    }

    ~Evil() {
        delete[] data;
    }

    void Print(){
        cout << val << " ";
        for(int i = 0;i < ed-st+1;++i)
            cout << data[i] <<" ";
        cout << endl;
    }

    friend ostream &operator<<(ostream& os, const Evil& e) {
        os << e.val;
        for (int i = 0; i < e.ed - e.st + 1; ++i)
            os << " " << e.data[i];
        os << '\n';
        return os;
    }
};

#endif//EVIL_HPP    