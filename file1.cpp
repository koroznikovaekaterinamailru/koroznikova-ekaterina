#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v = {-7, -4, 0, 1, 3};
	vector<int> v1(5);
	for(int i=0;i<v.size();i++)
	{
		v1[i]=v[i]*v[i];
	}
	int temp;
	 for (int i = 0; i < v1.size(); i++)
	 {
	 	for (int j = i+1; j < v1.size(); j++) 
	 	{
	 		if (v1 [i] > v1 [j])
	 		{
	 			temp = v1 [i];
	 			v1 [i] = v1 [j];
	 			v1 [j] = temp;
	 		}
	 	}
	 }
	
	for(int i=0;i<v1.size();i++)
	cout<<v1[i]<<endl;
	
}
