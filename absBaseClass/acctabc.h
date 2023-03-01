#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#ifndef ACCTABC_H
#define ACCTABC_H
#include<iostream>
#include<string>
using std::string;
using std::endl;
using std::cout;
using std::cin;
using std::ios_base;
class AcctABC
{
public:
	AcctABC(const string &s="nullbody",long an=-1,double bal=0.0);
	void deposit(double m);
	virtual void WithDraw(double mx)=0;//pure virtual function 纯虚函数
	double Balance()const { return balance; };
	virtual void ViewAcct()const = 0;
	virtual ~AcctABC();

private:
	string fullName;
	long AcountNum;
	double balance;
protected:
	struct Formatting
	{
		std::ios_base::fmtflags flag;
		std::streamsize pr;
	};
	const std::string & FullName()const { return fullName; }
	long AcctNum()const { return AcountNum; }
	Formatting setF()const;
	void restore(Formatting &f)const;	

};
//派生储蓄卡类
class Brass:public AcctABC
{
public:
	Brass(const string &s="nullbody",long n=0,double m=0);
	virtual void WithDraw(double m);
	virtual void ViewAcct()const;
	virtual ~Brass() {};
};
//派生信用卡类
class BrassPlus :public AcctABC
{
public:
	BrassPlus(const string &s="nullbody",long num=0,double bal=0,double max=200,double Rt=0.11);
	virtual ~BrassPlus() {};
	virtual void ViewAcct()const;
	virtual void  WithDraw(double m);
	void resetMax(double m) { MaxLoan = m; }
	void resetRate(double r) { rate = r; }
	void reserOwe() { owesbank = 0; }
private:
	double MaxLoan;
	double rate;
	double owesbank;
};


#endif // !ACCTABC_H

