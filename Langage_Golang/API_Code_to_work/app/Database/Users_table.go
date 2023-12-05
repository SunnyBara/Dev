package database

import (
	"database/sql"

	"fmt"

	"example.com/data-access/models"
)

func AddUser(new_User models.User) (int64, error) {
	result, err := Db().Exec("INSERT INTO Users (user_name,user_password,user_admin) VALUES (?, ?, ?)", new_User.User_name, new_User.User_password, new_User.User_admin)
	if err != nil {
		return 0, fmt.Errorf("addUser: %v", err)
	}
	id, err := result.LastInsertId()
	if err != nil {
		return 0, fmt.Errorf("addUser: %v", err)
	}
	return id, nil
}

func ParseUser(row models.Scanner) models.User {
	var new_User models.User
	row.Scan(&new_User.Id,
		&new_User.User_name,
		&new_User.User_password,
		&new_User.User_admin,
		&new_User.User_age,
		&new_User.User_gender,
		&new_User.User_weight,
		&new_User.User_height)
	return new_User
}

func BuildListOfUser(rows *sql.Rows) []models.User {
	var ListOfUser []models.User
	defer rows.Close()
	for rows.Next() {
		var user models.User = ParseUser(rows)
		ListOfUser = append(ListOfUser, user)
	}
	return ListOfUser
}
func ChangeUser(user models.User) (int64, error) {
	fmt.Printf("user : %v \n ", user)
	result, err := Db().Exec("UPDATE Users SET user_name = ?, user_password = ?, user_admin = ? WHERE id = ?", user.User_name, user.User_password, user.User_admin, user.Id)
	if err != nil {
		return 0, fmt.Errorf("ChangeUser: %v", err)
	}
	id, err := result.LastInsertId()
	if err != nil {
		return 0, fmt.Errorf("ChangeUser: %v", err)
	}
	return id, nil
}
