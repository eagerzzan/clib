#include <iostream>
#include <string>

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
	static const char *words[] = {"troy", "tray", "trie", "xray", "trim", "troyan"};

	int s = sizeof(words) / sizeof(words[0]);

	TrieNode root;

	for (int i = 0; i < s; i++)
	{
		if (words[i])
		{
			cout << "Words : " << words[i] << endl;
			insert(root, string(words[i]));
		}
	}

	insert(root, "");

	for (int i = 0; i < s; i++)
	{
		if (words[i])
			cout << "Search : " << words[i] << ", result : " << search(root, string(words[i])) << endl;
	}

	cout << "TSearch : " << (search(root, "t") == NULL ? "Not Found" : "Found") << endl;
	cout << "TSearch : " << search(root, "") << endl;
	cout << "TSearch : " << search(root, "troyan") << endl;
	cout << "TSearch : " << search(root, "troy") << endl;

	return 0;
}
