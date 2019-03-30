#ifndef NOTE_H
#define NOTE_H

#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

class Note
{
public:
	string m_sTitle = "";
	string m_sText = "";
	vector<string> m_sTags = {};
	bool m_bDeleted = false;
};

#endif 