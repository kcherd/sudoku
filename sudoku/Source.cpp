#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
struct Sq_1
{
	int a, b;
};
Sq_1 Square(int, int);
void main()
{
	setlocale(LC_ALL, "RUS");
	char Abc[18];  // ������, � ������� ������������ �������� ������ �� ����� � ������
	int s = 0, a = 0, n = 1, b = 0, pr, num = 1, num1 = 1, a_1 = 0, b_1 = 0, t1 = 1;           //pr - ������
	int n1 = 0;
	char ans1 = '+', ans3;
	int ans2, an = 1, s1, s2, sum1 = 0, j_1 = 0;
	Sq_1 sq;
	vector <int> buff, Lack0, Lack1, Nm;                  //Lack0 - ������ � �������� �����, � ������� ��� �����, Lack1 - ������ � ������������ �������, Nm - ������ � ���������� ������� ��� ���������� ��������
	vector <vector<int>> v2, v3; //v2 - ������ � ������� �������� �� ������, � ������� �������� � ������� ���� ���������, v3 - ������, � ������� ������������ �������� ������������� ������

	cout << "���� ������ �������� ������, ������� +. ���� ������ �������� ������� ������ ������, �� �������� ���� ������ � ���� in.txt � �������� !" << endl;
	cin >> ans1;

	if (ans1 == '+')
	{
		while (ans1 != '-')
		{
			cout << "����� ������� ���������: 1, 2?" << endl;
			cin >> ans2;
			if (ans2 == 1)
			{
				if (an == 1)
				{
					s1 = 0;
					s2 = 9;
				}
				else if (an == 2)
				{
					s1 = 9;
					s2 = 18;
				}
				else
				{
					s1 = 18;
					s2 = 27;
				}
			}
			else if (ans2 == 2)
			{
				if (an == 1)
				{
					s1 = 27;
					s2 = 36;
				}
				else if (an == 2)
				{
					s1 = 36;
					s2 = 45;
				}
				else
				{
					s1 = 45;
					s2 = 54;
				}
			}

			ifstream f("Text.txt");
			if (!f.is_open())
				cout << "���� �� ��������" << endl;
			else
			{
				while (s < s1)          // ������� �� ������� ����
				{
					f.getline(Abc, 18);
					s++;
				}
				while (s >= s1 && s < s2) //���������� ������ ���� � ������ v2
				{

					for (int i = 0; i < 9; i++)
					{
						f >> a;
						buff.push_back(a);
					}
					s++;
					v2.push_back(buff);
					buff.clear();
				}
			}
			f.close();

			ofstream f2("Out.txt");   // ���������� ���� � ����, � ������� ��� ����� ������ ������������
			for (int i = 0; i < 9; i++)
			{
				while (j_1 < 8)
				{
					f2 << v2[i][j_1] << " ";
					j_1++;
				}
				f2 << v2[i][j_1];
				f2 << endl;
				j_1 = 0;
			}
			f2.close();
			cout << "������� � ���� Out.txt � ��������� ����. ��� �������� ������� +" << endl;
			cin >> ans3;
			while (n > 0)  //������� ������
			{
				n = 0;
				for (int i = 0; i < 9; i++)
				{
					for (int i1 = 1; i1 < 10; i1++)        //����������� ����������� ����. ���� ��������� ����� �� 1 �� 9
					{
						while (n1 < 9 && b != 1)    //���� ��������� �������� �������
						{
							if (v2[i][n1] == i1)
								b = 1;
							n1++;
						}
						if (b == 0)              //���� �� ���� ����� � ������� �� ����� i1, �� ��� ����� ���������� � ������ � ������������ �������
						{
							pr = i1;
							Lack1.push_back(pr);
						}
						b = 0;
						n1 = 0;
					}
					for (int j = 0; j < 9; j++)
					{
						if (v2[i][j] == 0)                 //����������� ��������
						{
							Lack0.push_back(j);
						}
					}
					for (int m = 0; m < Lack0.size(); m++)         //���������� ��������
					{
						for (int c = 0; c < Lack1.size(); c++)     //���� ���� �� ������� � ������������ �������
						{
							for (int b1 = 0; b1 < 9; b1++)             //�������
							{
								if (v2[b1][Lack0[m]] == Lack1[c])          //�������� �������. ���� � ��� ���� ��� �����, �� 0, ���� ���, �� 1.
									num = 0;
							}

							sq = Square(i, Lack0[m]);                       //�������. sq �����, � ������� ���������� ��������
							for (int f = sq.a; f < (sq.a + 3); f++)              //�������� �������� (����� ��� � �������)
							{
								for (int w = sq.b; w < (sq.b + 3); w++)
								{
									if (v2[f][w] == Lack1[c])
										num1 = 0;
								}
							}

							if (num == num1 && num == 1) // ���� � � ������� � � ����� ��� �������� �����, �� ��� �������� � ������
								Nm.push_back(Lack1[c]);
							num = 1;
							num1 = 1;
						}
						if (Nm.size() == 1)    // ���� � ������� ������ ���� �����, �� ��� �������� �� ����� �������
							v2[i][Lack0[m]] = Nm[0];
						else
							n++;
						Nm.clear();
					}
					Lack0.clear();
					Lack1.clear();
				}
			}
			while (t1 != 0)                               //��������
			{
				t1 = 0;
				ifstream f3("Out.txt");
				if (!f3.is_open())
					cout << "���� �� ��������" << endl;
				else
					while (sum1 < 9)  // ������� ������������ ����������� �� �����
					{
						for (int i = 0; i < 9; i++)
						{
							f3 >> a;
							buff.push_back(a);
						}
						sum1++;
						v3.push_back(buff);
						buff.clear();
					}
				f3.close();
				while (a_1 < 9 && t1 != 1)  // ������� ��������������� ����������� ������������ � ������� ����������. ���� ���� ���� ����� �� �������, �� ��������� �������������� �� ������
				{
					while (b_1 < 9 && t1 != 1)
					{
						if (v2[a_1][b_1] != v3[a_1][b_1])
						{
							t1 = 1;
						}
						b_1++;
					}
					a_1++;
					b_1 = 0;
				}
				if (t1 == 0)
					cout << "��� �����" << endl;
				else
					cout << "���� ������. ��������� ��� ��� � ������� ���������. ��� �������� ������� +." << endl;
				cin >> ans3;
			}
			cout << "������ ������ ������(+,-)?" << endl;
			cin >> ans1;
			if (ans2 == '-')
				system("pause");
		}
		an++;
		cin >> ans1;
	}

	else if (ans1 == '!')
	{
		ifstream f4("in.txt"); // ���������� ������ �� �����
		if (!f4.is_open())
			cout << "���� �� ��������" << endl;
		else
			while (!f4.eof())
			{
				for (int i = 0; i < 9; i++)
				{
					f4 >> a;
					buff.push_back(a);
				}
				s++;
				v2.push_back(buff);
				buff.clear();
			}
		f4.close();
		while (n > 0)  // ������� ������
		{
			n = 0;
			for (int i = 0; i < 9; i++)
			{
				for (int i1 = 1; i1 < 10; i1++)        //����������� ����������� ����. ���� ��������� ����� �� 1 �� 9
				{
					while (n1 < 9 && b != 1)    //���� ��������� �������� �������
					{
						if (v2[i][n1] == i1)
							b = 1;
						n1++;
					}
					if (b == 0)              //���� �� ���� ����� � ������� �� ����� i1, �� ��� ����� ���������� � ������ � ������������ �������
					{
						pr = i1;
						Lack1.push_back(pr);
					}
					b = 0;
					n1 = 0;
				}
				for (int j = 0; j < 9; j++)
				{
					if (v2[i][j] == 0)                 //����������� ��������
					{
						Lack0.push_back(j);
					}
				}
				for (int m = 0; m < Lack0.size(); m++)         //���������� ��������
				{
					for (int c = 0; c < Lack1.size(); c++)     //���� ���� �� ������� � ������������ �������
					{
						for (int b1 = 0; b1 < 9; b1++)             //�������
						{
							if (v2[b1][Lack0[m]] == Lack1[c])          //�������� �������. ���� � ��� ���� ��� �����, �� 0, ���� ���, �� 1.
								num = 0;
						}

						sq = Square(i, Lack0[m]);                       //�������. sq �����, � ������� ���������� ��������
						for (int f = sq.a; f < (sq.a + 3); f++)              //�������� �������� (����� ��� � �������)
						{
							for (int w = sq.b; w < (sq.b + 3); w++)
							{
								if (v2[f][w] == Lack1[c])
									num1 = 0;
							}
						}

						if (num == num1 && num == 1) // ���� � � ������� � � ����� ��� �������� �����, �� ��� �������� � ������
							Nm.push_back(Lack1[c]);
						num = 1;
						num1 = 1;
					}
					if (Nm.size() == 1) // ���� � ������� ������ ���� �����, �� ��� �������� �� ����� �������
						v2[i][Lack0[m]] = Nm[0];
					else
						n++;
					Nm.clear();
				}
				Lack0.clear();
				Lack1.clear();
			}
		}

		for (int g = 0; g < 9; g++) // ����� ��������� �� �������
		{
			for (int g1 = 0; g1 < 9; g1++)
			{
				cout << v2[g][g1] << " ";
			}
			cout << endl;
		}
	}
	system("pause");
}
Sq_1 Square(int y, int x)
{
	Sq_1 n;
	if (x < 3 && y < 3)
	{
		n.a = 0;
		n.b = 0;
	}
	if (x > 2 && x < 6 && y < 3)
	{
		n.a = 0;
		n.b = 3;
	}
	if (x > 5 && y < 3)
	{
		n.a = 0;
		n.b = 6;
	}
	if (x < 3 && y>2 && y < 6)
	{
		n.a = 3;
		n.b = 0;
	}
	if (x > 2 && x < 6 && y>2 && y < 6)
	{
		n.a = 3;
		n.b = 3;
	}
	if (x > 5 && y > 2 && y < 6)
	{
		n.a = 3;
		n.b = 6;
	}
	if (x < 3 && y>5)
	{
		n.a = 6;
		n.b = 0;
	}
	if (x > 2 && x < 6 && y>5)
	{
		n.a = 6;
		n.b = 3;
	}
	if (x > 5 && y > 5)
	{
		n.a = 6;
		n.b = 6;
	}
	return n;
}
