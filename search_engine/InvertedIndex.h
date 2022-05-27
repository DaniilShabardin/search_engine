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

	void UpdateDocumentBase(vector<string> input_docs); //Обновить или заполнить базу документов

	vector<Entry> GetWordCount(const string& word); //Определяет количество вхождений слова word в загруженной базе документов

private:

	ConverterJSON data;

	vector<string> docs = data.GetTextDocuments();

	map<string, vector<Entry>> freq_dictionary;
};