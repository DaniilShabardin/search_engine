#pragma once

#include"libraries.h"

class ConverterJSON {

public:

	ConverterJSON() = default;

	vector<string> GetTextDocuments();

	int GetResponsesLimit();

	vector<string> GetRequests();

	void putAnswers(/*vector<vector<pair<int, float>>>answers*/);
};