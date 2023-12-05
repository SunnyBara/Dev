package controllers

import (
	"encoding/json"
	"fmt"
	"io"
	"log"
	"net/http"

	database "example.com/data-access/Database"
	"example.com/data-access/Token"
	"example.com/data-access/models"
)

func Login(w http.ResponseWriter, r *http.Request) {
	body, err := io.ReadAll(r.Body)
	var user models.User
	err = json.Unmarshal(body, &user)
	if err != nil {
		log.Fatal(err)
	}
	userindb := database.ParseUser(database.GetInfo(user.User_name, "user"))
	if user.User_password == userindb.User_password {
		tokenString, err := Token.CreateToken(userindb)
		if err != nil {
			fmt.Println("Error creating token:", err)
			return
		}
		w.Header().Set("Authorization", "Bearer "+tokenString)
		w.WriteHeader(http.StatusOK)
	} else {
		w.WriteHeader(http.StatusNotFound)
		w.Write([]byte("Password invalid"))
	}
	json.NewEncoder(w).Encode(user)

}
