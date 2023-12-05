package database

import (
	"database/sql"
	"encoding/json"
	"fmt"
	"log"
	"net/http"
	"reflect"

	"github.com/go-sql-driver/mysql"
)

var db *sql.DB

func Connection() {

	cfg := mysql.Config{
		User:   "root",
		Passwd: "root",
		Net:    "tcp",
		Addr:   "127.0.0.1",
		DBName: "API",
	}

	var err error
	//	for i := 0; i < 2; i++ {
	db, err = sql.Open("mysql", cfg.FormatDSN())
	fmt.Printf(" Delais de connection %v\n", err)
	//		time.Sleep(10 * time.Second)
	//	}

	pingErr := Db().Ping()
	if pingErr != nil {
		log.Fatal(pingErr)
	}
	fmt.Println("Connected!")
	return
}

func Db() *sql.DB {
	return db
}

func GetInfo(item interface{}, table string) *sql.Row {
	var query string = "SELECT * FROM " + table + "s WHERE "
	if reflect.ValueOf(item).Kind().String() == "string" {
		query += table + "_name"
	} else {
		query += "id"
	}
	query += " = ?;"
	row := Db().QueryRow(query, item)
	fmt.Printf("item = %v\nrow = %v\n query =%v", item, row, query)
	return row

}

func DeleteItem(item interface{}, table string) (int64, error) {
	var query string = "DELETE FROM " + table + "s WHERE "

	if reflect.ValueOf(item).Kind().String() == "string" {
		query += table + "_name"
	} else {
		query += "id"
	}
	query += " = ?"
	result, err := Db().Exec(query, item)
	if err != nil {
		return 0, fmt.Errorf("error in Exec delete %v", err)
	}
	row, err := result.RowsAffected()
	return row, nil
}

func GetAllItem(table string) *sql.Rows {
	var query string = "SELECT * FROM " + table + "s"
	rows, err := Db().Query(query)
	if err != nil {
		fmt.Printf("Error getting item from table %s", table)
	}
	return rows
}

func Jsonconverter(w http.ResponseWriter, r *http.Request, dataToConvert interface{}) {
	js, err := json.Marshal(dataToConvert)
	if err != nil {
		http.Error(w, "The server encountered a problem and could not process your request", http.StatusInternalServerError)
	}
	w.Write(js)
	return
}
