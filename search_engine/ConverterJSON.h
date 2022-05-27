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

	vector<string> GetTextDocuments(); //��������� ����������� ������

	int GetResponsesLimit(); //��������� ���� max_responses

	vector<string> GetRequests(); //��������� �������� �� ����� requests.json

	void putAnswers(vector<std::vector<std::pair<int, float>>>answers);//�������� � ���� answers.json ���������� ��������� ��������
};