#include <bits/stdc++.h>

using namespace std;
int a[100005];
int cmp(int a,int b){
	return a > b;
}
int main(){
	int n;

	cin >> n;
	for(int i  =0; i < n; ++i)
		cin >> a[i];
	sort(a,a+n);
	for(int i = 0; i < n; ++i)
		cout << a[i] << " ";
	return 0;
}