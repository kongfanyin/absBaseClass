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
		cout<<"�������û�����";
		getline(cin, temp);
		cout << "�������˻�����";
		cin >> tempnum;
		cout << "�����뵱ǰ��";
		cin >> tempbal;
		cout << "�������˻����ͣ�1 ���    2 ���ÿ���\n";
		while (cin>>kind&&(kind!=1&&kind!=2))
		{
			cout << "ѡ���˻����ͣ�������1��2��";
		}
		if (kind == '1')
		{
			p_client[i] = new Brass(temp, tempnum, tempbal);
		}
		else 
		{
			double trate, tmaxl;
			cout << "�����뵱ǰԤ֧���ʣ�";
			cin >> trate;
			cout << "�������˻����͸֧��ȣ�";
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
		delete p_client[i];//�ͷ��ڴ�
	}
	cout << "Done.";
	return 0;
}