#include "board_test.hpp"

Note createTestNote()
{
	Note my_note;

	my_note.m_sTitle = "Title 1";
	my_note.m_sText = "Text 1";
	my_note.m_sTags.push_back("Tag 1");
	my_note.m_sTags.push_back("Tag 2");

	return my_note;
}


Board createTestBoard()
{
	Board my_board;
	
	Note my_note = createTestNote();
	
	my_board.addNote(my_note.m_sTitle, my_note.m_sText, my_note.m_sTags);
	
	return my_board;
}

bool testAddNote()
{	
	int indexNote = 0;
	
	Note my_note = createTestNote();
	
	Board my_board = createTestBoard();
	
	bool error = false;
	
	if ((my_board.searchByTitle(my_note.m_sTitle)) != indexNote)
		error = true;
	
	if ((my_board.searchByText(my_note.m_sText)) != indexNote)
		error = true;
	
	
	for (int i=0; i<my_note.m_sTags.size(); i++)
	{
		if ((my_board.searchByTag(my_note.m_sTags.at(i))) != indexNote)
			error = true;
	}
	
	return error;
}

bool testDelNote()
{
	Note my_note = createTestNote();
	
	Board my_board = createTestBoard();
	
	int index = my_board.indexNotFound;
	
	bool error = false;
	
	if (my_board.deleteNote(0))
		error = true;
	
	if ((my_board.searchByTitle(my_note.m_sTitle)) != index)
		error = true;
	
	if ((my_board.searchByText(my_note.m_sText)) != index)
		error = true;
	
	for (int i=0; i<my_note.m_sTags.size(); i++)
	{
		if ((my_board.searchByTag(my_note.m_sTags.at(i))) != index)
			error = true;
	}
	
	return error;
}