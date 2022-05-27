#include"InvertedIndex.h"

void InvertedIndex::UpdateDocumentBase(vector<string> input_docs) {

	vector<string> paths = file_paths();

	for (int i = 0; i < paths.size(); i++) {

		ofstream file(paths[i]);

		file << input_docs[i];

		file.close();
	}
}

vector<Entry> InvertedIndex::GetWordCount(const string& word) {

	vector<vector<string>> texts = unique_words(docs);

	vector<vector<Entry>> information;

	Entry NEW;

	for (int i = 0; i < texts.size(); i++) {

		for (int y = 0; y < texts[i].size(); y++) {

			if (freq_dictionary.count(texts[i][y]) == 0) {

				NEW.doc_id = i;

				NEW.count = 1;

				information.push_back(vector<Entry>());

				information.back().push_back(NEW);

				freq_dictionary[texts[i][y]] = information.back();
			}

			else if (freq_dictionary[texts[i][y]].back().doc_id == i) freq_dictionary[texts[i][y]].back().count++;

			else {

				NEW.doc_id = i;

				NEW.count = 1;

				freq_dictionary[texts[i][y]].push_back(NEW);
			}
		}
	}

	vector<Entry> WORD = freq_dictionary[word];

	freq_dictionary.clear();

	return WORD;
}