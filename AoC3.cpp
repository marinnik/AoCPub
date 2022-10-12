#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<cmath>

using namespace std;

vector<string> getOnPos(vector<string> m, int p, bool a);
int powerCons(vector<string> m);
int binToDec(vector<string> m);


int main()
{
	vector<string> v;

	ifstream in("E:\\input2.txt");
	string num;
	
	if (in.is_open())
	{
		while (in >> num)
		{
			v.push_back(num);
		}
	}
	in.close();

	vector<string> o = v;
	vector<string> d = v;

	
	for (int j = 0; j < num.size(); j++)
	{
		if (o.size() > 1)
		{
			o = getOnPos(o, j, true);
		}
	}
	
	for (int j = 0; j < num.size(); j++)
	{
		if (d.size() > 1)
		{
			d = getOnPos(d, j, false);
		}
	}


	//d = getOnPos(d, 0, false);
	//d = getOnPos(d, 1, false);
	//cout << d[0] << "\t" << d[1] << endl;
	//d = getOnPos(d, 2, false);
	//cout << d[0] << endl;

	cout << "Power consumption = " << powerCons(v) << endl;
	cout << "Oxygen generatior rating = " << binToDec(o) << endl;
	cout << "CO2 scrubber rating = " << binToDec(d) << endl;
	cout << "Life support rating = " << binToDec(o) * binToDec(d) << endl;

	return 0;
}

int binToDec(vector<string> m)
{
	string num = m[0];
	int n = 0;
	int pwr = num.size() - 1;

	for (int j = 0; j < num.size(); j++)
	{
		if (m[0][j] == '1')
		{
			n += pow(2, (pwr - j));
		}
	}
	return n;
}

int powerCons(vector<string> m)
{
	int gamma = 0;
	int eps = 0;

	string num = m[0];
	int n = 0;
	int pwr = num.size() - 1;

	for (int j = 0; j < num.size(); j++)
	{
		for (int i = 0; i < m.size(); i++)
		{
			if (m[i][j] == '1')
			{
				n++;
			}
		}
		if (n > (m.size() / 2))
		{
			gamma += pow(2, (pwr - j));
		}
		else
		{
			eps += pow(2, (pwr - j));
		}
		n = 0;
	}

	return gamma * eps;
}

vector<string> getOnPos(vector<string> m, int p, bool a)
{
	vector<string> one;
	vector<string> zero;

	int n = 0;
	int x = m.size();

	for (int i = 0; i < x; i++)
	{
		if (m[i][p] == '1')
		{
			n++;
			one.push_back(m[i]);
		}
		else
		{
			zero.push_back(m[i]);
		}
	}

	if (x % 2 == 1)
	{
		x += 1;
	}

	if (a)
	{
		if (n >= (x / 2))
		{
			return one;
		}
		else
		{
			return zero;
		}
	}
	else
	{
		if (n >= (x / 2))
		{
			return zero;
		}
		else
		{
			return one;
		}
	}

}
