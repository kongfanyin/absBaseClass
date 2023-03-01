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
		cout << "��Ǯֵ����Ϊ��ֵ,����ȡ��\n";
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
	cout << "�û�����" << fullName << endl;
	cout << "���ţ�" << AcountNum << endl;
	cout << "��ǰ��$" << balance << endl;
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
		cout << "ȡǮֵ����Ϊ��ֵ������ȡ��\n";
	}
	else if (m<=Balance())
	{
		AcctABC::WithDraw(m);
	}
	else
	{
		cout << "���㣬�����ԡ�\n";
	}
}

void Brass::ViewAcct() const
{
	Formatting f = setF();
	cout << "�ͻ����ƣ�" << FullName() << endl;
	cout << "�ͻ��˺ţ�" << AcctNum() << endl;
	cout << "�˻���" << Balance() << endl;

}

BrassPlus::BrassPlus(const string & s, long num, double bal, double max, double Rt)
{
}

void BrassPlus::ViewAcct() const
{
	Formatting f = setF();
	AcctABC::ViewAcct();
	cout << "�ͻ����Ԥ֧��ȣ�" << MaxLoan << endl;
	cout << "�������ʣ�" << rate * 100 << "%.\n";
	cout << "��ǰ͸֧�" << owesbank << endl;
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
		cout << "��ȳ��ޣ�����ȡ��";
	}
	restore(f);
}
