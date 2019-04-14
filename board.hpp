#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include "note.hpp"

using namespace std;
 
class Board
{
public:
	const int indexNotFound = -1;
	
	void addNote(const string title
		, const string text
		, const vector<string> tags);
	void addNote(const Note note);
	bool deleteNote(const int indexNote);
	
	int searchByTitle(const string title);
	int searchByText(const string text);
	int searchByTag(const string tag);
	
	bool printNote(const int indexNote);
	void printAllNotes();
	
private:
	vector<Note> notes = {};
};

#endif