#include <iostream>
using namespace std;

int main() {
	int *arr;
	int n;
	cout << "How many data points?" << endl;
	cin >> n;
	arr = new int[n];
	for (int i = 0;i < n;i++) {
		cout << "Input number into data set." << endl;
		cin >> arr[i];
	}
	int max = *arr;
	for (int i = 0;i < n;i++) {
		cout << "current element of array: " << arr[i]<<endl;
		if (arr[i] > max)
			max = arr[i];
	}
	cout << "The max of your data set is: " << max;
	cin >> n;
		
	return 0;
}