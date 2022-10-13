#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std; 

vector<int> outComma(istream& in, string& line);
vector<int> fuelForEachPos(vector<int> crabsPos);

int main()
{
	string line;
	vector<int> pos;

	ifstream in("E:\\Input7.txt");
	if (in.is_open())
	{
		pos = outComma(in, line);
	}
	in.close();

	vector<int> fuel;
	fuel = fuelForEachPos(pos);

	int minfuel = *min_element(fuel.begin(), fuel.end());

	cout << minfuel << endl;

	return 0;
}

vector<int> outComma(istream& in, string& line)
{
	vector<int> ans;
	getline(in, line);
	stringstream ss(line);
	while (ss.good())
	{
		string sub;
		getline(ss, sub, ',');
		ans.push_back(stoi(sub));
	}
	return ans;
}

vector<int> fuelForEachPos(vector<int> crabsPos) //func for pt2
{
	int posnum = *max_element(crabsPos.begin(), crabsPos.end());
	vector<int> fuelforpos(posnum + 1, 0);

	for (int i = 0; i < fuelforpos.size(); i++)
	{
		for (int j = 0; j < crabsPos.size(); j++)
		{
			fuelforpos[i] += abs(i - crabsPos[j]) * (abs(i - crabsPos[j]) + 1) / 2; 
			// for pt1 substitute this with fuelforpos[i] += abs(crabsPos[j]-i); 
			// overall code could be easier for just pt1 (it was)
		}
	}
	return fuelforpos;
}