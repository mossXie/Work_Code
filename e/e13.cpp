#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class VecException {
    private:
        string mes;
    public:
        VecException(const string& msg) : mes(msg) {}
        const string& getMessage() const { return mes; }
};

class Vec {
    private:
        double* v;
        int len;
    public:
        Vec(int length, double* values = nullptr);
        Vec(const Vec& other);
        ~Vec();
        void set(double arg, int num);
        double get(int num) const;
        double euc_norm() const;
        double max_norm() const;
        void print() const;
};

Vec::Vec(int length, double* values) : len(length) {
    if (len < 0) {
        throw VecException("length error");
    }
    v = new double[len];
    if (values) {
        for (int i = 0; i < len; i++) {
            v[i] = values[i];
        }
    } else {
        for (int i = 0; i < len; i++) {
            v[i] = 0.0;
        }
    }
}

Vec::Vec(const Vec& other) : len(other.len) {
    if (len < 0) {
        throw VecException("length error");
    }
    v = new double[len];
    for (int i = 0; i < len; ++i) {
        v[i] = other.v[i];
    }
}

Vec::~Vec() {
    delete[] v;
}

void Vec::set(double arg, int num) {
    if (num < 0 || num >= len) {
        throw VecException("coordinate error in set()");
    }
    v[num] = arg;
}

double Vec::get(int num) const {
    if (num < 0 || num >= len) {
        throw VecException("coordinate error in get()");
    }
    return v[num];
}

double Vec::euc_norm() const {
    double sum = 0.0;
    for (int i = 0; i < len; i++) {
        sum += v[i] * v[i];
    }
    return sqrt(sum);
}

double Vec::max_norm() const {
    double max_val = 0.0;
    for (int i = 0; i < len; i++) {
        if (abs(v[i]) > max_val) {
            max_val = abs(v[i]);
        }
    }
    return max_val;
}

void Vec::print() const {
    cout << "(";
    for (int i = 0; i < len; i++) {
        double value = v[i];
        if (value == value) {
            cout << value; 
        } else {
            cout << value; 
        }
        if (i < len - 1) {
            cout << ",";
        }
    }
    cout << ")" << endl;
}

void error() {
    double y1[3] = {1, 2, 3};
    double y2[5] = {2, 1, 0, 5, 7};
    Vec x(3, y1), y(5, y2), z(4);
    Vec u = x;
    y.print();
    x.print();
    z.print();
    u.print();
}

int main() {
    try {
        error();
    } catch (const VecException& e) {
        cerr << "Exception: " << e.getMessage() << endl;
        return 2;
    } catch (...) {
        cerr << "Exception: unknown error" << endl;
        return 2;
    }
    return 0;
}