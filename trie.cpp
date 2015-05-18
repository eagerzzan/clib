#include <iostream>

using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode
{
	bool leaf;
	TrieNode *children[ALPHABET_SIZE];

	TrieNode() : leaf(false)
	{
		memset(children, 0, sizeof(TrieNode));
	}

	~TrieNode()
	{
		for (int i = 0; i < ALPHABET_SIZE; i++)
			if (children[i])
				delete children[i];
	}
};

void insert(TrieNode &root, const string k)
{
	TrieNode *r = &root;
	int i;

	for (i = 0; i < k.length(); i++)
	{
		int cn = k[i] - 'a';

		if (r->children[cn] == NULL)
			r->children[cn] = new TrieNode();

		r = r->children[cn];
	}

	r->leaf = true;
}

TrieNode* search(TrieNode &root, const string k)
{
	TrieNode *r = &root;
	int i;

	for (i = 0; i < k.length(); i++)
	{
		int cn = k[i] - 'a';

		if (r->children[cn] == NULL)
			return NULL;
		else
			r = r->children[cn];
	}

	if (r->leaf) return r;
	else return NULL;
}

int main()
{
	const char *words[] = {"troy", "tray", "trie", "xray", "trim", "troyan"};
	int s = sizeof(words) / sizeof(words[0]);
	string str;

	TrieNode root;

	for (int i = 0; i < s; i++)
	{
		str = words[i];
		insert(root, str);
	}

	insert(root, "");

	for (int i = 0; i < s; i++)
	{
		str = words[i];
		cout << "Search : " << search(root, str) << endl;
	}

	cout << "TSearch : " << (search(root, "t") == NULL ? "Not Found" : "Found") << endl;
	cout << "TSearch : " << search(root, "") << endl;
	cout << "TSearch : " << search(root, "troyan") << endl;
	cout << "TSearch : " << search(root, "troy") << endl;

	return 0;
}
