#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class VecException {
    private:
        string mes;
        int index1;
        int index2;
    public:
        VecException(const string& msg) : mes(msg) {}
        VecException(const string& msg, const int& l1, const int& l2) : mes(msg), index1(l1), index2(l2) {}
        VecException(const string& msg, const int& size) : mes(msg), index1(size) {}
        
        const string& getMessage() const { return mes; }
        const int& getIndex1() const { return index1; }
        const int& getIndex2() const { return index2; }
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
        Vec operator+ (const Vec& other) const;
        Vec operator- (const Vec& other) const;
        Vec operator* (double num) const;
        friend Vec operator* (double num, const Vec& other);
        Vec& operator= (const Vec& other);
        bool operator== (const Vec& other) const;
        friend ostream& operator<< (ostream& os, const Vec& vec);
        double& operator[] (int i);
};

Vec::Vec(int length, double* values) : len(length) {
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
    v = new double[len];
    for (int i = 0; i < len; ++i) {
        v[i] = other.v[i];
    }
}

Vec::~Vec() {
    delete[] v;
}

void Vec::set(double arg, int num) {
    if (num >= 0 && num < len) {
        v[num] = arg;
    }
}

double Vec::get(int num) const {
    if (num >= 0 && num < len) {
        return v[num];
    }
    return 0.0;
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

Vec Vec::operator+ (const Vec& other) const {
    Vec result(len);
    if (len != other.len) {
        throw VecException("addition of vectors of different lengths", len, other.len);
    }
    for (int i = 0; i < len; i++) {
        result.v[i] = v[i] + other.v[i];
    }
    return result;
}

Vec Vec::operator- (const Vec& other) const {
    Vec result(len);
    if (len != other.len) {
        throw VecException("subtraction of vectors of different lengths", len, other.len);
    }
    for (int i = 0; i < len; i++) {
        result.v[i] = v[i] - other.v[i];
    }
    return result;
}

Vec Vec::operator* (double num) const {
    Vec result(len);
    for (int i = 0; i < len; ++i) {
        result.v[i] = v[i] * num;
    }
    return result;
}

Vec operator* (double num, const Vec& other) {
    return other * num;
}

Vec& Vec::operator= (const Vec& other) {
    if (this != &other) {
        if (len != other.len) {
            delete[] v;
            len = other.len;
            v = new double[len];
        }
        for (int i = 0; i < len; i++) {
            v[i] = other.v[i];
        }
    }
    return *this;
}

bool Vec::operator== (const Vec& other) const {
    if (len != other.len) {
        return false;
    }
    for (int i = 0; i < len; i++) {
        if (v[i] != other.v[i]) {
            return false;
        }
    }
    return true;
}

ostream& operator<< (ostream& os, const Vec& vec) {
    os << "(";
    for (int i = 0; i < vec.len; ++i) {
        os << vec.v[i];
        if (i < vec.len - 1) {
            os << ",";
        }
    }
    os << ")";
    return os;
}

double& Vec::operator[] (int i) {
    if (i < 0 || i >= len) {
        throw VecException("incorrect indexing", i);
    }
    return v[i];
}

/*void error() {
    Vec v1(5), v2(3), v3(4);
    v3 = v1 - v2;
}*/


void error() {
    Vec v(5);
    double a = v[7];
}
int main() {
    try {
        error();
    } catch (const VecException& e) {
        string str = e.getMessage();

        if (str == "addition of vectors of different lengths") {
            cerr << "Exception: " << str << ": " << e.getIndex1() << " " << e.getIndex2() << endl;
        } else if (str == "subtraction of vectors of different lengths") {
            cerr << "Exception: " << str << ": " << e.getIndex1() << " " << e.getIndex2() << endl;
        } else if (str == "incorrect indexing") {
            cerr << "Exception: " << str << ": " << e.getIndex1() << endl;
        }

        return 2;
    } catch (...) { 
        cerr << "Exception: unknown error" << endl;
        return 2;
    }

    return 0;
}