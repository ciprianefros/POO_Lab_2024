#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

ifstream in("input.txt");


struct cmp
{
	bool operator()(pair<string, int> a, pair<string, int> b)
	{
		if (a.second == b.second)
		{
			return a.first > b.first;
		}
		return a.second < b.second;
	}
};
bool delimitator(char c, string exp);



int main() {

	string prop;

	unsigned int length = 0;

	string semne = ".,!?;: ";

	vector<string> v;

	getline(in, prop);

	transform(prop.begin(), prop.end(), prop.begin(), ::tolower);

	for (int i = 0; i < prop.length(); i++)
	{
		char ch = prop.at(i);

		if (delimitator(ch, semne)) {
			string cuvant = prop.substr(length, i - length);
			length = i + 1;
			if (cuvant.length() > 0)
			{
				v.push_back(cuvant);
			}
		}
	}

	vector<string> uniq;
	map<string, int> mp;

	for (auto str : v)
	{
		if (mp[str] == 0)
		{
			uniq.push_back(str);
		}
		mp[str]++;
	}

	vector<pair<string, int>> cuvinteUnice;
	for (auto str : uniq)
	{
		cuvinteUnice.push_back(make_pair(str, mp[str]));
	}
	
	priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
	for (auto pr : cuvinteUnice)
	{
		pq.push(pr);
	}

	while (!pq.empty())
	{
		cout << pq.top().first << " => " << pq.top().second << "\n";
		pq.pop();
	}

	return 0;

}

bool delimitator(char c, string exp)
{
	for (auto i : exp)
	{
		if (c == i)
		{
			return true;
		}
	}
	return false;
}
