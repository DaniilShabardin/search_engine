#pragma once

#include"ConverterJSON.h"

#include"Entry.h"

#include<iostream>

#include<vector>

#include<map>

using namespace std;

vector<vector<string>>unique_words(vector<string> docs);

class InvertedIndex {

public:

	InvertedIndex() = default;

	void UpdateDocumentBase(vector<string> input_docs); //�������� ��� ��������� ���� ����������

	vector<Entry> GetWordCount(const string& word); //���������� ���������� ��������� ����� word � ����������� ���� ����������

private:

	ConverterJSON data;

	vector<string> docs = data.GetTextDocuments();

	map<string, vector<Entry>> freq_dictionary;
};