#include<vector>

#include<string>

using namespace std;

vector<vector<string>>unique_words(vector<string> docs) {

	vector<vector<string>>texts;

	for (int i = 0; i < docs.size(); i++) {

		texts.push_back(vector<string>());

		string text;

		for (int y = 0; y <= docs[i].size(); y++) {

			if (docs[i][y] != ' ' && y != docs[i].size()) text += docs[i][y];
			
			else {

				texts[i].push_back(text);

				text.clear();
			}
		}
	}

	return texts;
}