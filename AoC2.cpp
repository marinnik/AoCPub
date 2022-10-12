#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Command
{
	string dir;
	int unt;
	Command(string d, int u) : dir(d), unt(u){}
};

int main()
{
	vector<Command> comms;

	ifstream in("E:\\input1.txt");
	string dir;
	int unt;

	if (in.is_open())
	{
		while (in >> dir >> unt)
		{
			comms.push_back(Command(dir, unt));
		}
	}
	in.close();

	int depth = 0;
	int horiz = 0;
	int aim = 0; 

	for (int i = 0; i < comms.size(); i++)
	{
		if (comms[i].dir == "forward")
		{
			horiz += comms[i].unt;
			depth += aim*comms[i].unt;
		}
		else if (comms[i].dir == "up")
		{
			aim -= comms[i].unt;
		}
		else
		{
			aim += comms[i].unt;
		}
	}

	cout << "Answer is " << depth * horiz << endl;

	return 0;
}