#include"nlohmann/json.hpp"

#include<fstream>

#include<vector>

using namespace std;

vector<string>file_paths() {

	ifstream file("config.json");

	nlohmann::json information;

	vector<string>paths;

	file >> information;

	for (int i = 0; i < information["files"].size(); i++) paths.push_back(information["files"][i]);
	
	file.close();

	return paths;
}