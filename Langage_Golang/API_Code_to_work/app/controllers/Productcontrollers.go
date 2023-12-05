package controllers

import (
	"encoding/json"
	"fmt"
	"io"
	"log"
	"net/http"
	"strconv"

	database "example.com/data-access/Database"
	"example.com/data-access/middleware"
	"example.com/data-access/models"
	"github.com/gorilla/mux"
)

func GetProducts(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-type", "application/json;charset=UTF-8")
	w.WriteHeader(http.StatusOK)

	listOfProduct := database.BuildListOfProduct(database.GetAllItem("food"))
	database.Jsonconverter(w, r, listOfProduct)
	return
}

func GetProduct(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-type", "application/json;charset=UTF-8")
	w.WriteHeader(http.StatusOK)
	vars := mux.Vars(r)
	fmt.Printf("vars = %v\n", vars)
	id, err := strconv.Atoi(vars["id"])
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("id = %v\n", id)
	product := database.ParseProduct(database.GetInfo(id, "food"))
	database.Jsonconverter(w, r, product)
}

func CreateProducts(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-type", "application/json;charset=UTF-8")
	user, err := middleware.ExtractTokenData(w, r)
	if err == nil {
		if user.User_admin == true {
			w.WriteHeader(http.StatusOK)
			body, err := io.ReadAll(r.Body)
			var product models.Product
			err = json.Unmarshal(body, &product)
			if err != nil {
				log.Fatal(err)
			}
			database.AddProduct(product)
			json.NewEncoder(w).Encode(product)
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

func AlterProducts(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-type", "application/json;charset=UTF-8")
	user, err := middleware.ExtractTokenData(w, r)
	if err == nil {
		if user.User_admin == true {
			w.WriteHeader(http.StatusOK)
			vars := mux.Vars(r)
			id, err := strconv.Atoi(vars["id"])
			product := database.ParseProduct(database.GetInfo(id, "food"))
			body, err := io.ReadAll(r.Body)
			err = json.Unmarshal(body, &product)
			if err != nil {
				log.Fatal(err)
			}
			database.ChangeProduct(product)
			json.NewEncoder(w).Encode(product)
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

func DeleteProduct(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-type", "application/json;charset=UTF-8")
	user, err := middleware.ExtractTokenData(w, r)
	if err == nil {
		if user.User_admin == true {
			w.WriteHeader(http.StatusOK)
			vars := mux.Vars(r)
			id, err := strconv.Atoi(vars["id"])
			database.DeleteItem(id, "food")
			if err != nil {
				log.Fatal(err)
			}
		} else {
			w.WriteHeader(http.StatusUnauthorized)
		}
	} else {
		w.WriteHeader(http.StatusUnauthorized)
		errorMessage := err.Error()
		w.Write([]byte(errorMessage))
	}

}
