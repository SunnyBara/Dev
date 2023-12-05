package main

import (
	"example.com/data-access/controllers"
	"github.com/gorilla/mux"
)

func InitializeRouter() *mux.Router {
	router := mux.NewRouter().StrictSlash(true)

	router.Methods("GET").Path("/products").HandlerFunc(controllers.GetProducts)
	router.Methods("POST").Path("/products").HandlerFunc(controllers.CreateProducts)
	router.Methods("GET").Path("/products/{id}").HandlerFunc(controllers.GetProduct)
	router.Methods("PUT").Path("/products/{id}").HandlerFunc(controllers.AlterProducts)
	router.Methods("DELETE").Path("/products/{id}").HandlerFunc(controllers.DeleteProduct)

	router.Methods("GET").Path("/users").HandlerFunc(controllers.GetUsers)
	router.Methods("POST").Path("/users").HandlerFunc(controllers.CreateUser)
	router.Methods("GET").Path("/users/{id}").HandlerFunc(controllers.GetUser)
	router.Methods("PUT").Path("/users/{id}").HandlerFunc(controllers.Alteruser)
	router.Methods("DELETE").Path("/users/{id}").HandlerFunc(controllers.DeleteUser)

	router.Methods("POST").Path("/login").HandlerFunc(controllers.Login)
	return router
}
