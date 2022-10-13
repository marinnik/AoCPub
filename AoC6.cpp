#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

vector<long long> outComma(istream& in, string& line);
vector<long long> countFishesByDays(vector<long long> fishes);
vector<long long> fishAging(vector<long long> fishes);

int main()
{
	vector<long long> fish;
	int a;
	string line;

	ifstream in("E:\\Input6.txt");
	if (in.is_open())
	{
		fish = outComma(in, line);
	}
	in.close();

	vector<long long> fishbydays;
	fishbydays = countFishesByDays(fish);

	int day = 0;
	int days = 256;

	while (day < days)
	{
		fishbydays = fishAging(fishbydays);
		day++;
	}

	long long feesh = 0;
	for (int i = 0; i < fishbydays.size(); i++)
	{
		feesh += fishbydays[i];
		cout << feesh << endl;
	}

	

	/*
	int bitrhesgiven = 0;
	
	while (day < days)  //this part was real for pt1, but they decided to overload memory so yeah
	{
		for (int i = 0; i < fish.size(); i++)
		{
			if (fish[i] == 0)
			{
				fish[i] = 6;
				birthsgiven++;
			}
			else
			{
				fish[i]--;
			}
		}
		while (birthsgiven != 0)
		{
			fish.push_back(8);
			birthsgiven--;
		}
		day++;
	}
	cout << fish.size() << endl;*/

}


vector<long long> outComma(istream& in, string& line)
{
	vector<long long> ans;
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


vector<long long> countFishesByDays(vector<long long> fishes)
{
	vector<long long> count(9,0);
	for (int i = 0; i < fishes.size(); i++)
	{
		int j = 0;
		while (j < 9)
		{
			if (fishes[i] == j)
			{
				count[j]++;
			}
			j++;
		}
	}
	return count;
}

vector<long long> fishAging(vector<long long> fishes)
{
	long long newborns;
	newborns = fishes[0];
	for (int i = 0; i < 8; i++)
	{
		fishes[i] = fishes[i + 1];
	}
	fishes[6] += newborns;
	fishes[8] = newborns;
	return fishes;
}