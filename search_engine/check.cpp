#include"libraries.h"

void check() {

	ifstream file("config.json");

	nlohmann::json information;

	vector<string>files;

	file >> information;

	cout << "Название поискового движка " << information["config"]["name"] << endl;

	try {

		if (file.is_open() == false) {

			throw exception("config file is missing");
		}

		if (information.find("config") == information.end()) {

			throw exception("config file is empty");
		}
	}

	catch (exception& error) {

		cout << "\nERROR: " << error.what() << endl;

		exit(1);
	}

	if (information["config"]["max_responses"] == "") {

		information["config"]["max_responses"] = 5;
	}

	file.close();
}