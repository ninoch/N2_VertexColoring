#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
// #define cin fin
// #define cout fout 
using namespace std;

const int MAX_N = 30;
ifstream fin("input.txt");
ofstream fout("output.txt");
int n, k = 3;
int color[MAX_N], f[MAX_N];
vector<int> arr[MAX_N], ff;
multiset<int> used[MAX_N];
int usedColors[MAX_N][2], colSize[MAX_N];

void readInput() { 
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int u, v;
		cin >> u;
		char ch;
		cin >> ch;
		for(int i = 0; i < k; i++)
		{
			cin >> v;
			arr[u - 1].push_back(v - 1);
		}
	}
}

void preProcess(int T) {
	ff.clear();
	memset(f, 0, sizeof f);
	memset(color, 0, sizeof color);
	for(int i = 0; i < T; i++)
	{
		f[i] = i + 1;
		ff.push_back(i);
	}
	ff.push_back(n);
	for(int i = 0; i < n; i++)
		used[i].clear();
}

vector<int> checkAdjs(int ind, int T) {
	vector<int> useThisColors;
	for(int i = 0; i < T; i++)
		useThisColors.push_back(i + 1);
	for(int i = 0; i < arr[ind].size(); i++)
	{
		if(colSize[arr[ind][i]] > 2)
		{
			useThisColors.clear();
			break;
		}
		if(colSize[arr[ind][i]] == 2)
		{
			if(useThisColors.size() == T)
			{
				useThisColors.clear();
				for(int j = 0; j < 2; j++)
					useThisColors.push_back(usedColors[arr[ind][i]][j]);
			}
			else 
			{	
				int a = arr[ind][i];
				for(int i = useThisColors.size() - 1; i >= 0; i--)
					if(useThisColors[i] != usedColors[a][0] && useThisColors[i] != usedColors[a][1])
						useThisColors.erase(useThisColors.begin() + i);
				if(useThisColors.size() == 0)
					break;
			}
			
		}
	}
	return useThisColors;
}

void updateColor(int ind, int col) {
	if(col != 0)
	{
		for(int i = 0; i < arr[ind].size(); i++)
		{
			if(used[arr[ind][i]].find(col) == used[arr[ind][i]].end())
			{
				usedColors[arr[ind][i]][colSize[arr[ind][i]] % 2] = col;
				colSize[arr[ind][i]] ++;
			}
			used[arr[ind][i]].insert(col);
		}
	}
	else
	{
		for(int i = 0; i < arr[ind].size(); i++)
		{
			used[arr[ind][i]].erase(used[arr[ind][i]].find(color[ind]));
			if(used[arr[ind][i]].find(color[ind]) == used[arr[ind][i]].end())
			{
				colSize[arr[ind][i]] --;
				usedColors[arr[ind][i]][colSize[arr[ind][i]] % 2] = 0;
			}
		}
	}
	color[ind] = col;
}

void showInfo(int ind, vector<int> useThisColors) {
	cerr << endl << endl << "*************" << endl;
	cerr << "F: ";
	for(int i = 0; i < n; i ++)
		cerr << f[i] << " ";
	cerr << endl;
	cerr << "IND: " << ind << " Size: " << useThisColors.size() << endl;
	for(int i = 0; i < ind; i++)
		cerr << color[i] << " ";
	cerr << endl;
	cerr << "USED COLORS " << endl;
	for(int i = 0; i < n; i++)
	{
		cerr << i << ": " ;
		for(set<int>::iterator it = used[i].begin(); it != used[i].end(); it++)
			cerr << (*it) << " " ;
		cerr << "---> ";
		for(int j = 0; j < colSize[i]; j++)
			cerr << usedColors[i][j] << " ";
		cerr << endl;
	}
	cerr << "USED THIS COLORS: ";
	for(int i = 0; i < useThisColors.size(); i++)
		cerr << useThisColors[i] << " ";
	cerr << endl;
	
}

bool func(int ind, int cols) {
	if(ind == n)
		return true;
	vector<int> useThisColors = checkAdjs(ind, max(cols, f[ind]));
	// showInfo(ind, useThisColors);
	if(useThisColors.size() == 0)
		return false;
	if(f[ind] != 0)
	{ 
		if(find(useThisColors.begin(), useThisColors.end(), f[ind]) == useThisColors.end())
			return false;
		else
		{
			updateColor(ind, f[ind]);
			if(func(ind + 1, f[ind]))
				return true;
			updateColor(ind, 0);
			return false;
		}
	}
	else // f[ind] == 0
	{
		for(int i = 0; i < useThisColors.size(); i++)
		{
			updateColor(ind, useThisColors[i]);
			if(func(ind + 1, cols))
				return true;
			updateColor(ind, 0);
		}
		return false;
	}
	return false;
}

bool hasNextState(int t) { 
	bool flag = false;
	for(int x = t - 1; x >= 0; x--)
	{
		if(ff[x] + 1 != ff[x + 1])
		{
			ff[x] ++;
			for(int y = x + 1; y < t; y++)
				ff[y] = ff[x] + ( y - x );
			flag = true;
			break;
		}
	}
	memset(f, 0, sizeof f);
	for(int x = 0; x < t; x++)
		f[ff[x]] = x + 1;
	return flag;
}

int main() {
	// Read
	readInput();
	// Solve
	int T = 1;
	for(int i = n; i > 1; i--)
	{
		preProcess(i);
			
		do
		{
			if(func(0, 1))
			{
				T = i;
				break;
			}
		}while(hasNextState(i));
		if(T != 1)
			break;
	}
	// Write
	cout << T << endl;
	for(int i = 0; i < n; i++)
		cout << color[i] << " "; 
	cout << endl;
	return 0;
}
