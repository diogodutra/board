#ifndef STORYBOARD_H
#define STORYBOARD_H

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include "note.hpp"

using namespace std;
 
class Storyboard
{
public:
	const int indexNotFound = -1;
	
	void addNote(string title, string text, vector<string> tags);
	bool deleteNote(int indexNote);
	
	int searchByTitle(string title);
	int searchByText(string text);
	int searchByTags(string tag);
	
	bool printNote(int indexNote);
	void printAllNotes();
	
private:
	vector<Note> notes = {};
};

#endif