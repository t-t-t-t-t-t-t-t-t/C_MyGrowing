#include<iostream>
#include<string>
using namespace std;
void solution(string middle, string post) {
	if (post.empty()) { return; }
	char root = post[post.length() - 1];
	cout << root;
	int k = middle.find(root);
	string child_mid_L = middle.substr(0, k);
	// Èç¹ûk==length·µ»Ø¿Õ 
	string child_mid_R = middle.substr(k + 1);
	string child_post_L = post.substr(0, k);
	string child_post_R = post.substr(k, post.length() - k - 1);
	solution(child_mid_L, child_post_L);
	solution(child_mid_R, child_post_R);
}
int main() {
	string middle, post;
	cin >> middle >> post;
	solution(middle, post);
	return 0;
}