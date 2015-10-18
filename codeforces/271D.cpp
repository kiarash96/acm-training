#include <iostream>
#include <string>
using namespace std;

string str, good;
int K, ans = 0;

struct Node {
	char ch;
	bool isWord;
	Node *child, *sib;

	Node(const char ch = 0) : ch(ch), isWord(false), child(NULL), sib(NULL) { }
	~Node() { delete child; delete sib; }
};

inline Node* insert(Node *root, const char ch) {
	Node *node = NULL;
	if (root->child == NULL) // Insert as child
		root->child = node = new Node(ch);
	else { 				   	 // Insert as next sibling
		Node *last;
		for (last = root->child; last->ch != ch && last->sib != NULL; last = last->sib);
		if (last->ch != ch)
			last->sib = node = new Node(ch);
		else
			node = last;
	}

	if (!node->isWord) {
		node->isWord = true;
		ans ++;
	}

	return node;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> str >> good >> K;

	Node *root = new Node();
	for (int s = 0; s <= (int) str.size(); s ++) {
		Node *cur = root;
		int bad = 0;

		for (int end = s; end < (int) str.size(); end ++) {
			bad += (good[str[end] - 'a'] == '0');

			if (bad <= K)
				cur = insert(cur, str[end]);
			else
				break;
		}
	}

	cout << ans << endl;

	delete root;
	return 0;
}
