#define _CRT_SECURE_NO_WARNINGS 1
#include"acctabc.h"


const int Clients = 4;
int main(char argc, char** argv)
{
	AcctABC* p_client[Clients];
	string temp;
	long tempnum;
	double tempbal;
	char kind;
	for (int i = 0; i <= Clients; i++)
	{
		cout<<"请输入用户名：";
		getline(cin, temp);
		cout << "请输入账户名：";
		cin >> tempnum;
		cout << "请输入当前余额：";
		cin >> tempbal;
		cout << "请输入账户类型：1 储蓄卡    2 信用卡。\n";
		while (cin>>kind&&(kind!=1&&kind!=2))
		{
			cout << "选择账户类型，请输入1或2。";
		}
		if (kind == '1')
		{
			p_client[i] = new Brass(temp, tempnum, tempbal);
		}
		else 
		{
			double trate, tmaxl;
			cout << "请输入当前预支利率：";
			cin >> trate;
			cout << "请输入账户最大透支额度：";
			cin >> tmaxl;
			p_client[i] = new BrassPlus(temp, tempnum, tempbal, trate, tmaxl);

		}
		while (cin.get()!='\n')
		{
			continue;
		}
	}
	cout << endl;
	for (int i = 0; i < Clients; i++)
	{
		p_client[i]->ViewAcct();
		cout << endl;
	}
	for (int i = 0; i <Clients; i++)
	{
		delete p_client[i];//释放内存
	}
	cout << "Done.";
	return 0;
}