package main

import (
	"net/http"

	database "example.com/data-access/Database"
)

func main() {
	database.Connection()
	defer database.Db().Close()

	router := InitializeRouter()
	http.ListenAndServe(":8080", router)

	return
}
