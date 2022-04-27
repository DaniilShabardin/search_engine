#include"class.h"

vector<string> ConverterJSON::GetTextDocuments() {

	ifstream file("config.json");

	nlohmann::json information;

	vector<string>files;

	file >> information;

	for (int i = 0; i < information["files"].size(); i++) {

		string path = information["files"][i];

		string information_from_path;

		ifstream file_contents(path);

		if (file_contents.is_open() == false) {

			files.push_back("");

			cout << path << " file is missing" << endl;
		}

		else {

			files.push_back("");

			do {

				getline(file_contents, information_from_path);

				files[i] += information_from_path;

			} while (file_contents.eof());
		}
	}

	file.close();

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

void ConverterJSON::putAnswers(/*vector<vector<pair<int, float>>>answers*/) {

	ofstream file("answers.json");

	nlohmann::json answers;

	vector<string>files = GetTextDocuments();

	int max_responses = GetResponsesLimit();

	vector<string> requests = GetRequests();



	file.close();
}