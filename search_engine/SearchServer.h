#pragma once

#include"SearchServer.h"

#include"InvertedIndex.h"

#include"RelativeIndex.h"

class SearchServer {

public:

	SearchServer(InvertedIndex& idx) : _index(idx) { };

	vector<vector<RelativeIndex>> search(const vector<string>& queries_input);

private:

	InvertedIndex _index;
};
