package controllers

import (
	"encoding/json"
	"io"
	"log"
	"net/http"
	"strconv"

	database "example.com/data-access/Database"
	"example.com/data-access/middleware"
	"example.com/data-access/models"
	"github.com/gorilla/mux"
)

func GetUsers(w http.ResponseWriter, r *http.Request) {
	user, err := middleware.ExtractTokenData(w, r)
	if err == nil {
		w.Header().Set("Content-type", "application/json;charset=UTF-8")
		if user.User_admin == true {
			w.WriteHeader(http.StatusOK)
			listOfProduct := database.BuildListOfUser(database.GetAllItem("user"))
			database.Jsonconverter(w, r, listOfProduct)
		} else {
			w.WriteHeader(http.StatusUnauthorized)
		}
	} else {
		w.WriteHeader(http.StatusUnauthorized)
		errorMessage := err.Error()
		w.Write([]byte(errorMessage))
	}
	return
}

func GetUser(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-type", "application/json;charset=UTF-8")
	user, err := middleware.ExtractTokenData(w, r)
	if err == nil {
		vars := mux.Vars(r)
		id, err := strconv.Atoi(vars["id"])
		if err != nil {
			log.Fatal(err)
		}
		if user.User_admin == true || int(user.Id) == id {
			w.WriteHeader(http.StatusOK)
			product := database.ParseUser(database.GetInfo(id, "User"))
			database.Jsonconverter(w, r, product)
		} else {
			w.WriteHeader(http.StatusUnauthorized)
			w.Write([]byte("restricted access"))
		}
	} else {
		w.WriteHeader(http.StatusUnauthorized)
		errorMessage := err.Error()
		w.Write([]byte(errorMessage))
	}
	return
}

func CreateUser(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-type", "application/json;charset=UTF-8")
	w.WriteHeader(http.StatusOK)
	user, err := middleware.ExtractTokenData(w, r)
	if err == nil {
		body, err := io.ReadAll(r.Body)
		var newuser models.User
		err = json.Unmarshal(body, &newuser)
		if err != nil {
			log.Fatal(err)
		}
		if user.User_admin != true {
			newuser.User_admin = false
		}
		database.AddUser(newuser)
		json.NewEncoder(w).Encode(newuser)
	} else {
		w.WriteHeader(http.StatusUnauthorized)
		errorMessage := err.Error()
		w.Write([]byte(errorMessage))
	}
	return
}

func Alteruser(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-type", "application/json;charset=UTF-8")
	user, err := middleware.ExtractTokenData(w, r)
	if err == nil {
		vars := mux.Vars(r)
		id, err := strconv.Atoi(vars["id"])
		if err != nil {
			log.Fatal(err)
		}
		if user.User_admin == true || user.Id == float64(id) {
			w.WriteHeader(http.StatusOK)
			alteruser := database.ParseUser(database.GetInfo(id, "user"))
			body, err := io.ReadAll(r.Body)
			err = json.Unmarshal(body, &alteruser)
			if err != nil {
				log.Fatal(err)
			}
			database.ChangeUser(alteruser)
			json.NewEncoder(w).Encode(alteruser)
		} else {
			w.WriteHeader(http.StatusUnauthorized)
			w.Write([]byte("restricted access"))
		}
	} else {
		w.WriteHeader(http.StatusUnauthorized)
		errorMessage := err.Error()
		w.Write([]byte(errorMessage))
	}
	return
}

func DeleteUser(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-type", "application/json;charset=UTF-8")
	user, err := middleware.ExtractTokenData(w, r)
	if err == nil {
		vars := mux.Vars(r)
		id, err := strconv.Atoi(vars["id"])

		if err != nil {
			log.Fatal(err)
		}
		if user.User_admin == true || user.Id == float64(id) {
			w.WriteHeader(http.StatusOK)
			database.DeleteItem(id, "user")
		} else {
			w.WriteHeader(http.StatusUnauthorized)
			w.Write([]byte("restricted access"))
		}
	} else {
		w.WriteHeader(http.StatusUnauthorized)
		errorMessage := err.Error()
		w.Write([]byte(errorMessage))
	}
	return
}
