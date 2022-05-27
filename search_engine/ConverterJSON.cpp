#include"ConverterJSON.h"

vector<string> ConverterJSON::GetTextDocuments() { 

	vector<string>paths = file_paths();

	vector<string>files;

	for (int i = 0; i < paths.size(); i++) {

		ifstream file_contents(paths[i]);

		string information_from_path;

		if (file_contents.is_open()) {

			getline(file_contents, information_from_path);

			files.push_back(information_from_path);

			file_contents.close();
		}

		else {

			files.push_back("");

			cout << paths[i] << " file is missing" << endl;
		}
	}

	return files;
} 

int ConverterJSON::GetResponsesLimit() { 

	ifstream file("config.json");

	nlohmann::json information;

	file >> information;

	int max_responses = information["config"]["max_responses"];

	file.close();

	return max_responses;
}

vector<string> ConverterJSON::GetRequests() {

	ifstream file("requests.json");

	nlohmann::json information;

	vector<string> requests;

	file >> information;

	for (int i = 0; i < information["requests"].size(); i++) {

		requests.push_back(information["requests"][i]);
	}

	file.close();

	return requests;
}

void ConverterJSON::putAnswers(vector<std::vector<std::pair<int, float>>>answers) {

	vector<string> result(answers.size());

	vector<int> docid(answers.size());

	ofstream file("answers.json");

	nlohmann::ordered_json a;

	for (int i = 0; i < answers.size(); i++) {

		for (int y = 0; y < answers[i].size(); y++) {

			if (answers[i][y].second > 0) docid[i]++;
		}

		if (docid[i] > 0) result[i] = "true";

		else result[i] = "false";
	}

	for (int i = 0; i < answers.size(); i++) {

		if (i + 1 <= 9) a["answers"]["request00" + to_string(i + 1)]["result"] = result[i];

		else if (i + 1 <= 99) a["answers"]["request0" + to_string(i + 1)]["result"] = result[i];

		else if (i + 1 <= 999) a["answers"]["request" + to_string(i + 1)]["result"] = result[i];

		for (int y = 0; y < answers[i].size(); y++) {

			if (docid[i] > 1) { 

				if (answers[i][y].second > 0) {

					if (i + 1 <= 9) a["answers"]["request00" + to_string(i + 1)]["relevance"]["docid: " + to_string(answers[i][y].first)] = answers[i][y].second;

					else if (i + 1 <= 99) a["answers"]["request0" + to_string(i + 1)]["relevance"]["docid: " + to_string(answers[i][y].first)] = answers[i][y].second;

					else if (i + 1 <= 999) a["answers"]["request" + to_string(i + 1)]["relevance"]["docid: " + to_string(answers[i][y].first)] = answers[i][y].second;
				}
			}

			else {

				if (answers[i][y].second > 0) {

					if (i + 1 <= 9) a["answers"]["request00" + to_string(i + 1)]["docid: 0, rank"] = answers[i][y].second;

					else if (i + 1 <= 99) a["answers"]["request0" + to_string(i + 1)]["docid: 0, rank"] = answers[i][y].second;

					else if (i + 1 <= 999) a["answers"]["request" + to_string(i + 1)]["docid: 0, rank"] = answers[i][y].second;
				}
			}
		}
	}

	file << a.dump(4);

	file.close();
}