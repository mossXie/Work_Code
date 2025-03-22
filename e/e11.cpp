#include <iostream>
#include <cmath>
using namespace std;

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
        friend ostream& operator<<(ostream& os, const Vec& vec);
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
    for (int i = 0; i < len; i++) {
        result.v[i] = v[i] + other.v[i];
    }
    return result;
}

Vec Vec::operator- (const Vec& other) const {
    Vec result(len);
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
    return v[i];
}

/*int main() {
    double y1[4] = {1, 2, 3, 4};
    double y2[4] = {-2, 1, 3, -3};

    Vec u(4, y1), v(4, y2);
    Vec w(4);

    cout << "u = " << u << endl;
    cout << "v = " << v << endl;
    w = u = u;
    cout << "w = u = " << w << endl;
    w = 4. * u + v * 3;
    cout << "w = 4.*u + v*3 = " << w << endl;
    w[2] = 3;
    w[0] = -1;
    cout << "w = " << w << endl;

    return 0;
}*/