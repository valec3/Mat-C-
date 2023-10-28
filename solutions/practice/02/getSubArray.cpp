#include<bits/stdc++.h>
using namespace std;

vector<int> findSubarray(int a[], int n) {
	int sumMax = 0;
	int start = 0, end = 0;
	int largest = 0;
	int sum = 0;
	vector<int> v;
	vector<vector<int>> v1;
	if (n == 1) {
		v.push_back(a[0]);
		return v;
	}
	for (int i = 0; i < n; i++) {
		if(a[i]>=0){
			sum += a[i];
			largest++;
			// cout<<sum<<" -> "<<a[i]<<"<<idx:"<<i<<endl;
		}
		cout<<"largo: "<<largest<<endl;
		if(a[i]<0 || i==n-1){
			if(sum>=sumMax){
				sumMax = sum;
				if(i==n-1){
					end = i;
					start = i-largest+1;
				}else{
					end = i-1;
					start = i-largest;
				}
				// start = i-largest;
				v1.push_back({start, end});
			}
			// cout<<start<<" "<<end<<endl;
			// cout<<sum<<" "<<endl;
			sum = 0;
			largest = 0;
		}
	}
	for(int i=0; i<v1.size(); i++){
		if(v1[i][1]-v1[i][0]>end-start){
			start = v1[i][0];
			end = v1[i][1];
		}
	}
	for (int i = start; i <= end; i++) {
		v.push_back(a[i]);
	}
	return v;
}

int main() {
    int a[] = {1, 2, 3, -9, 5, 6, 7};
    int n = sizeof(a) / sizeof(a[0]);
    vector<int> v = findSubarray(a, n);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}