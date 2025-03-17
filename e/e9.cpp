#include <iostream>
using namespace std;

class Vector_2d{
	public:
		Vector_2d(double x = 0.,double y = 0.){
			x_ = x;
			y_ = y;
		}
		void print(const char*str)const;
		Vector_2d operator+(const Vector_2d & op) const;
		Vector_2d operator-(const Vector_2d & op) const{
			return Vector_2d(x_ - op.x_,y_ - op.y_);//simple way
		}
		const Vector_2d& operator=(const Vector_2d & op);//fast,because don't need to do 2 copy
		const Vector_2d& operator+=(const Vector_2d& op);
		Vector_2d operator*(double a) const;
		friend Vector_2d operator*(double a,const Vector_2d & op);//внешняя функций
	private:
		double x_,y_;
};
const Vector_2d& Vector_2d::operator=(const Vector_2d & op){
	x_ =op.x_;
	y_ =op.y_;
	return *this;
}
Vector_2d Vector_2d::operator+(const Vector_2d & op) const{
	Vector_2d tmp;
	tmp.x_ = x_ + op.x_;
	tmp.y_ = y_ + op.y_;
	return tmp;
}
const Vector_2d& Vector_2d::operator+=(const Vector_2d & op){
	x_ += op.x_;
	y_ += op.y_;
	return *this;
}
Vector_2d operator*(double a,const Vector_2d & op){
	return Vector_2d(op.x_*a,op.y_*a);
}
Vector_2d Vector_2d::operator*(double a) const{
	return Vector_2d(x_*a,y_*a);
}
void Vector_2d::print(const char*str = 0)const{
	if(str) cout << str << " = ";
	cout << "(" << x_ << "," << y_ << ")" << endl;
}