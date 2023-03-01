#define _CRT_SECURE_NO_WARNINGS 1
#ifndef ECLIPSE_H
#define ECLIPSE_H
class Ellipse
{
public:
	Ellipse(double x=0,double y=0);
	virtual ~Ellipse();
	void move(double nx, double ny) { x += nx; y += ny; }
	virtual double Area()const { return a* b*3.1415926; }
	virtual void rotate(double ang) { angle += ang; }
	virtual void scale(double sa, double sb);
private:
	//Õ÷‘≤÷––ƒ
	double x;
	double y;
	//Õ÷‘≤≥§÷·º∞∂Ã÷·
	double a;
	double b;
	double angle;

};
class circle:public Ellipse
{
public:
	circle();
	~circle();

private:

};



#endif // !ECLIPSE_H
