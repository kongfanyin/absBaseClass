#include "acctabc.h"

AcctABC::AcctABC(const string & s, long an, double bal)
{
	fullName = s;
	AcountNum = an;
	balance = bal;
}

void AcctABC::deposit(double m)
{
	if (m<0)
	{
		cout << "存钱值不能为负值,操作取消\n";
	}
	else
	{
		balance += m;
	}
}

void AcctABC::WithDraw(double mx)
{
	balance -= mx;
}

void AcctABC::ViewAcct() const
{
	cout << "用户名：" << fullName << endl;
	cout << "卡号：" << AcountNum << endl;
	cout << "当前余额：$" << balance << endl;
}

//protected method
AcctABC::~AcctABC()
{

}

AcctABC::Formatting AcctABC::setF() const
{
	//set up ###.##
	Formatting f;
	f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
	f.pr = cout.precision(2);
	return f;
}

void AcctABC::restore(Formatting & f) const
{
	cout.setf(f.flag, ios_base::floatfield);
	cout.precision(f.pr);
}
//brass methods

Brass::Brass(const string & s, long n, double m):AcctABC(s,n,m)
{
	
}

void Brass::WithDraw(double m)
{
	if (m<0)
	{
		cout << "取钱值不能为负值，交易取消\n";
	}
	else if (m<=Balance())
	{
		AcctABC::WithDraw(m);
	}
	else
	{
		cout << "余额不足，请重试。\n";
	}
}

void Brass::ViewAcct() const
{
	Formatting f = setF();
	cout << "客户名称：" << FullName() << endl;
	cout << "客户账号：" << AcctNum() << endl;
	cout << "账户余额：" << Balance() << endl;

}

BrassPlus::BrassPlus(const string & s, long num, double bal, double max, double Rt)
{
}

void BrassPlus::ViewAcct() const
{
	Formatting f = setF();
	AcctABC::ViewAcct();
	cout << "客户最大预支额度：" << MaxLoan << endl;
	cout << "逾期利率：" << rate * 100 << "%.\n";
	cout << "当前透支额：" << owesbank << endl;
	restore(f);
}

void BrassPlus::WithDraw(double m)
{
	Formatting f = setF();
	double bal = Balance();
	if (m<=bal)
	{
		AcctABC::WithDraw(m);
	}
	else if (m<bal+MaxLoan-owesbank)
	{
		double advance = m - bal;
		owesbank += advance * (1 + rate);
		cout << "bank advance: $" << advance << endl;
		cout << "finance charge: " << advance * rate << endl;
		deposit(advance);
		AcctABC::WithDraw(m);
	}
	else
	{
		cout << "额度超限，交易取消";
	}
	restore(f);
}
