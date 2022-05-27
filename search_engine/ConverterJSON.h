#pragma once

#include"nlohmann/json.hpp"

#include<iostream>

#include<vector>

#include<fstream>

#include<string>

using namespace std;

vector<string>file_paths();

class ConverterJSON {

public:

	ConverterJSON() = default;

	vector<string> GetTextDocuments(); //Получения содержимого файлов

	int GetResponsesLimit(); //Считывает поле max_responses

	vector<string> GetRequests(); //Получения запросов из файла requests.json

	void putAnswers(vector<std::vector<std::pair<int, float>>>answers);//Положить в файл answers.json результаты поисковых запросов
};