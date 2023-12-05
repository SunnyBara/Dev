package database

import (
	"database/sql"
	"fmt"

	"example.com/data-access/models"
)

func AddProduct(new_product models.Product) (int64, error) {
	result, err := Db().Exec("INSERT INTO foods (food_name,food_description,food_calories,food_protein,food_carbohydrate,food_lipid) VALUES (?, ?,?,?,?,?)", new_product.Food_name, new_product.Food_description, new_product.Food_calories, new_product.Food_protein, new_product.Food_carbohydrate, new_product.Food_lipid)
	if err != nil {
		return 0, fmt.Errorf("AddProduct: %v", err)
	}
	id, err := result.LastInsertId()
	if err != nil {
		return 0, fmt.Errorf("AddProduct: %v", err)
	}
	return id, nil
}

func ParseProduct(row models.Scanner) models.Product {
	var new_product models.Product
	row.Scan(&new_product.Id, &new_product.Food_name, &new_product.Food_description, &new_product.Food_calories, &new_product.Food_protein, &new_product.Food_carbohydrate, &new_product.Food_lipid)
	return new_product
}

func BuildListOfProduct(rows *sql.Rows) []models.Product {
	var listOfProduct []models.Product
	defer rows.Close()
	for rows.Next() {
		var product models.Product = ParseProduct(rows)
		listOfProduct = append(listOfProduct, product)
	}
	return listOfProduct
}

func ChangeProduct(product models.Product) (int64, error) {
	result, err := Db().Exec("UPDATE foods SET food_name = ? food_description = ? food_calories = ? food_protein = ? food_carbohydrate = ? food_lipid = ? WHERE id = ?", product.Food_name, product.Food_description, product.Food_calories, product.Food_protein, product.Food_carbohydrate, product.Food_lipid, product.Id)
	if err != nil {
		return 0, fmt.Errorf("ChangeProduct: %v", err)
	}
	id, err := result.LastInsertId()
	if err != nil {
		return 0, fmt.Errorf("ChangeProduct: %v", err)
	}
	return id, nil
}
