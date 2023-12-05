package database

import (
	"database/sql"
	"fmt"

	"example.com/data-access/models"
)

func AddNotes(new_note models.Notes) (int64, error) {
	result, err := Db().Exec("INSERT INTO notes (note_message,user_id) VALUES (?,?)", new_note.Note_message, new_note.User_id)
	if err != nil {
		return 0, fmt.Errorf("AddProduct: %v", err)
	}
	id, err := result.LastInsertId()
	if err != nil {
		return 0, fmt.Errorf("AddProduct: %v", err)
	}
	return id, nil
}

func GetNotesbyUser(id float64) {
	var query string = "SELECT * FROM notes WHERE user_id = ? "
	rows, err := Db().Query(query)
	if err != nil {
		fmt.Printf("Error getting item from table notes")
	}
	BuildListOfNote(rows)
	return
}

func BuildListOfNote(rows *sql.Rows) []models.Notes {
	var ListOfNotes []models.Notes
	defer rows.Close()
	for rows.Next() {
		var note models.Notes = ParseNote(rows)
		ListOfNotes = append(ListOfNotes, note)
	}
	return ListOfNotes
}

func ParseNote(row models.Scanner) models.Notes {
	var new_Note models.Notes
	row.Scan(&new_Note.Id,
		&new_Note.Note_message,
		&new_Note.User_id)
	return new_Note
}
