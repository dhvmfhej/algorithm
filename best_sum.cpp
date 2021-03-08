#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
vector<int> ans;
int M, n, in;

void best_sum(int m, vector<int> list) {
	if (!m &&(!ans.size() || ans.size()>list.size())) {
		ans = list;
	}
	if (m > 0) {
		for (int i = 0; i < v.size(); i++) {
			vector<int> newlist = list;
			newlist.push_back(v[i]);
			best_sum(m - v[i], newlist);
		}
	}
	return;
}

int main() {
	cin >> M >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &in);
		v.push_back(in);
	}
	vector<int> vec;
	best_sum(M, vec);
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
}