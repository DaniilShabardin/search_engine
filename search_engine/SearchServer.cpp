#include"SearchServer.h"

vector<vector<RelativeIndex>>SearchServer::search(const vector<string>& queries_input){

	vector<vector<string>> a = unique_words(queries_input);

	vector<vector<RelativeIndex>>GG(a.size());

	vector<vector<Entry>> A;

	vector<Entry> b;

	for (int i = 0; i < a.size(); i++) {

		for (int y = 0; y < a[i].size(); y++) {

			if (y < a[i].size() - 1) {

				if (a[i][y] == a[i][y + 1]) {

					a[i].erase(a[i].begin() + y);

					y--;
				}
			}
		}
	}

	for (int i = 0; i < a.size(); i++) {

		for (int y = 0; y < a[i].size(); y++) {

			b = _index.GetWordCount(a[i][y]);

			for (int z = 0; z < b.size(); z++) {

				bool proverka = false;

				RelativeIndex c;

				for (int s = 0; s < GG[i].size(); s++) {

					if (b[z].doc_id == GG[i][s].doc_id) {

						GG[i][s].rank += b[z].count;

						proverka = true;
					}
				}

				if (proverka == false) {

					c.doc_id = b[z].doc_id;

					c.rank = b[z].count;

					GG[i].push_back(c);
				}
			}
		}
	}
	
	for (int i = 0; i < GG.size(); i++) {

		for (int y = 0; y < GG[i].size(); y++) {

			GG[i][y].rank /= 10;
		}
	}

	return GG;
}
