#include<iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
		
	int count = 0;

	for (int i = 0; i < prices.size()-1; i++)
	{
		for (int j = i+1; j < prices.size(); j++)
		{
			count++;
			if (prices[i] > prices[j])
				break;			
		}
		answer.push_back(count);
		count = 0;
	}

	answer.push_back(0);
	
	return answer;
}

int main()
{
	vector<int> p{ 1,2,3,2,3 };
	
	p = solution(p);
	for (auto i : p)
		cout << i << endl;

	return 0;
}