#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include "note.hpp"

using namespace std;
 
class Storyboard
{
public:
	int indexNotFound = -1;
	
	void addNote(string title, string text, vector<string> tags);
	bool deleteNote(int index);
	int searchByTitle(string title);
	int searchByText(string text);
	int searchByTags(string tag);
	void printAllNotes();
	
private:
	vector<Note> notes = {};
};