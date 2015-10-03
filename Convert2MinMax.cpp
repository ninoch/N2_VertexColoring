#include <iostream>
#include <fstream>
#include <vector>
#define cin fin
#define INF 1000 * 1000 * 1000
using namespace std;

const int MAX_N = 20;
ifstream fin("3regular_output.txt");
int maxt[MAX_N], mint[MAX_N];
vector<string> tmp, mins[MAX_N], maxs[MAX_N];

void showInfo(vector<string> vec, int v) {	
	bool noent = false;
	for(int j = 0; j < vec.size(); j++)
	{
		if(vec[j][0] == '-' || vec[j][0] == '*')
			cout << endl << vec[j] << endl;
		else
		{
			if(vec[j][0] == 'A')
				noent = true;
				
			cout << vec[j] << " " ;
			if((noent == false && j % 5 == 4) || (noent == true && vec.size() - j == v + 2))
				cout << endl;
		}	
	}
	cout << endl;
}

int main() { 
	for(int i = 0; i < MAX_N; i++)
	{
		mint[i] = INF;
		maxt[i] = -1 * INF;
	}
	// Read
	string str;
	while(cin >> str)
	{
		int n = 0;
		tmp.clear();
		tmp.push_back(str);
		while(str[0] != 'A')
		{
			cin >> str;
			
			tmp.push_back(str);
			if(str == ":")
				n ++;
		}
		cin >> str;
		tmp.push_back(str);
		cin >> str;
		tmp.push_back(str);
		
		int ans = atoi(str.c_str());
		for(int i = 0; i < n + 1; i++)
		{
			cin >> str;
			tmp.push_back(str);
		}
		
		
		if(ans < mint[n])
		{
			mint[n] = ans;
			mins[n].clear();
			for(int i = 0; i < tmp.size(); i++)
				mins[n].push_back(tmp[i]);
		}
		if(ans > maxt[n])
		{
			maxt[n] = ans;
			maxs[n].clear();
			for(int i = 0; i < tmp.size(); i++)
				maxs[n].push_back(tmp[i]);
		}
	}
	// Write
	for(int i = 4; i < MAX_N; i++)
	{
		cout << "# of vertecies: " << i << " min: " << mint[i] << endl;
		showInfo(mins[i], i);
		
		cout << "# of vertecies: " << i << " max: " << maxt[i] << endl;
		showInfo(maxs[i], i);
	}
	return 0;
}
