#include "storyboard.hpp"

void Storyboard::addNote(string title, string text, vector<string> tags)
{	
	Note new_note;
	
	new_note.m_sTitle = title;
	new_note.m_sText  = text;	
	new_note.m_sTags  = tags;	
	
	this->notes.push_back(new_note);
}

bool Storyboard::deleteNote(int indexNote)
{			
	bool error = false;
	
	if (this->notes.size() < indexNote)
	{
		error = true;
	}
	else
	{
		if (this->notes.at(indexNote).m_bDeleted)
		{
			error = true;
		}
		else
		{		
			this->notes.at(indexNote).m_bDeleted = true;
		}
	}
	
	return error;
}

int Storyboard::searchByTitle(string title)
{
	int index = this->indexNotFound;
	
	for (int i=0; i<this->notes.size(); i++)
	{
		if (!(this->notes.at(i).m_bDeleted))
		{
			if (!(title.compare(this->notes.at(i).m_sTitle) != 0))
			{
				index = i;
				break;
			}
		}
	}
	
	return index;
}

int Storyboard::searchByText(string text)
{
	int index = this->indexNotFound;
	
	for (int i=0; i<this->notes.size(); i++)
	{
		if (!(this->notes.at(i).m_bDeleted))
		{
			if (!(text.compare(this->notes.at(i).m_sText) != 0))
			{
				index = i;
				break;
			}
		}
	}
	
	return index;
}

int Storyboard::searchByTags(string tag)
{
	int index = this->indexNotFound;
	
	for (int i=0; i<this->notes.size(); i++)
	{
		if (!(this->notes.at(i).m_bDeleted))
		{
			for (int j=0; j<this->notes.at(i).m_sTags.size(); j++)
			{
				if (!(tag.compare(this->notes.at(i).m_sTags.at(j)) != 0))
				{
					index = i;
					break;
				}
			}
		}
	}
	
	return index;
}

bool Storyboard::printNote(int indexNote)
{
	bool error = false;
	
	if (! this->notes.at(indexNote).m_bDeleted)
	{
		cout << "Note # " << indexNote << endl;
		cout << "Title: " << this->notes.at(indexNote).m_sTitle << endl;
		cout << "Text : " << this->notes.at(indexNote).m_sText  << endl;
		cout << "Tags : ";
		
		for (int j=0; j<this->notes.at(indexNote).m_sTags.size(); j++)
		{
			cout << this->notes.at(indexNote).m_sTags.at(j) << " , ";
		}
		cout << endl;
	}
	else
	{
		error = true;
	}
	
	return error;
}

void Storyboard::printAllNotes()
{
	cout << "All notes:" << endl;
	
	for (int i=0; i<this->notes.size(); i++)
	{
		cout << endl;
		this->printNote(i);
	}
}