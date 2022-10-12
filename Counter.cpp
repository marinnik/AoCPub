#include <iostream>
#include <fstream>
#include <vector>

using namespace std;




int main()
{
	vector<int> v; //vector to store all the input numbers
	int depth; //storage for every number 

	ifstream in("E:\\input.txt");			//open input.txt file
	
	if (in.is_open())
	{
		while (in >> depth) //for all numbers in input file
		{
			v.push_back(depth); //add them to the v vector
		}
	}
	in.close();

	int n1 = 0; //amount of numbers which are larger than previous 
	int n2 = 0; //amount of sums which are larger tan previous
	int sum1 = 0; //sum of "first" 3 elems
	int sum2 = 0; //next sum

	for (int j = 1; j < 3; j++)			//max i = v.size()-1; so not to let i go out of v.size range
	{									//last elem of v in sum2 should be v[i] => first elem in sum1
		if (v[j] > v[j - 1])			//is v[i-3] => initializing i = 3
		{								//in order to check v[0] vs v[1] and v[1] vs v[2] another "for" cycle
			n1++;
		}
	}
	for (int i = 3; i < v.size(); i++)  
	{									
		if (v[i] > v[i - 1])			 
		{
			n1++;
		}
		sum1 = v[i - 3] + v[i - 2] + v[i - 1];
		sum2 = v[i - 2] + v[i - 1] + v[i];
		if (sum2 > sum1)
		{
			n2++;
		}
	}
	
	cout << "n1 = " << n1 << "\tn2 = " << n2 << endl;

	return 0;
}