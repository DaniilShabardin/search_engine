#include"ConverterJSON.h"

#include"InvertedIndex.h"

#include"SearchServer.h"

#include<Windows.h>

using namespace std;

void check();

int main() {

	SetConsoleCP(1251);

	SetConsoleOutputCP(1251);

	check();

	InvertedIndex index;

	ConverterJSON a;

	SearchServer b(index);

	b.search(a.GetRequests());
}