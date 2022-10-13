#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

vector<int> getCoords(string& line);


int main()
{
	vector<vector<int>> B;

	vector<int> str;
	vector<int> ans;
	string line;

	int N = 0;
	int a;
	ifstream in("E:\\Input5.txt");
	if (in.is_open())
	{
		while (getline(in, line))
		{
			ans = getCoords(line);
			if (ans[0] == ans[2])
			{
				int a = 0;
				a = abs(ans[3] - ans[1]);
				while (a != -1)
				{
					vector<int> A;
					A.push_back(ans[0]);				//literaly could be a func but i'm lazy
					A.push_back(min(ans[3], ans[1]) + a);
					A.push_back(1);
					int s = 0;
					for (int j = 0; j < B.size(); j++)
					{
						
						if (B[j][0] == A[0] && B[j][1] == A[1])
						{
							B[j][2] += 1;
							s++;
						}
					}
					if (s == 0)
					{
						B.push_back(A);
					}
					a--;
				}
			}
			else if(ans[1] == ans[3])
			{
				int a = 0;
				a = abs(ans[2] - ans[0]);
				while (a != -1)
				{
					vector<int> A;
					A.push_back(min(ans[0], ans[2]) + a); //same
					A.push_back(ans[1]);
					A.push_back(1);
					int s = 0;
					for (int i = 0; i < B.size(); i++)
					{

						if (B[i][0] == A[0] && B[i][1] == A[1])
						{
							B[i][2] += 1;
							s++;
						}
					}
					if (s == 0)
					{
						B.push_back(A);
					}
					a--;
				}
			}
			else if (abs(ans[2] - ans[0]) == abs(ans[3] - ans[1]))
			{
				int a = 0;
				a = abs(ans[2] - ans[0]);
				while (a != -1)
				{
					vector<int> A;				// aaaaand same
					if (ans[2] > ans[0])
					{
						if (ans[3] > ans[1])
						{	
							A.push_back(ans[0] + a);
							A.push_back(ans[1] + a);
							A.push_back(1);
						}
						else
						{
							A.push_back(ans[0] + a);
							A.push_back(ans[1] - a);
							A.push_back(1);
						}
					}
					else
					{
						if (ans[3] > ans[1])
						{
							A.push_back(ans[0] - a);
							A.push_back(ans[1] + a);
							A.push_back(1);
						}
						else
						{
							A.push_back(ans[0] - a);
							A.push_back(ans[1] - a);
							A.push_back(1);
						}
					}
					int s = 0;
					for (int i = 0; i < B.size(); i++)
					{

						if (B[i][0] == A[0] && B[i][1] == A[1])
						{
							B[i][2] += 1;
							s++;
						}
					}
					if (s == 0)
					{
						B.push_back(A);
					}
					a--;
				}
			}
		}
	}
	in.close();

	for (int i = 0; i < B.size(); i++)  //and same
	{
		if (B[i][2] >= 2)
		{
			N++;
		}
	}
	std::cout << N << endl;
}


vector<int> getCoords(string& line)
{
	string coord;
	vector<int> ans;
	stringstream ss(line);
	while (ss.good())
	{
		string sub;
		getline(ss, sub, ' ');
		coord += sub;
		replace(coord.begin(), coord.end(), '>', ',');
	}
	stringstream aa(coord);
	while (aa.good())
	{
		string sub;
		getline(aa, sub, ',');
		ans.push_back(stoi(sub));
	}
	return ans;
}