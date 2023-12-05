package models

type Product struct {
	Id                float64 `json:"id"`
	Food_name         string  `json:"food_name"`
	Food_description  string  `json:"food_description"`
	Food_calories     float64 `json:"food_calories"`
	Food_protein      float64 `json:"food_protein"`
	Food_carbohydrate float64 `json:"food_carbohydrate"`
	Food_lipid        float64 `json:"food_lipid"`
}

type User struct {
	Id            float64 `json:"id"`
	User_name     string  `json:"user_name"`
	User_password string  `json:"user_password"`
	User_admin    bool    `json:"user_admin"`
	User_age      int64   `json:"user_age"`
	User_gender   int64   `json:"user_gender"`
	User_weight   int64   `json:"user_weight"`
	User_height   int64   `json:"user_height"`
}

type Notes struct {
	Id           float64 `json:"id"`
	Note_message string  `json:"note_message"`
	User_id      float64 `json:"user_id"`
}

type Scanner interface {
	Scan(dest ...interface{}) error
}
