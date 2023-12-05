package middleware

import (
	"fmt"
	"net/http"
	"strings"

	"example.com/data-access/Token"
	"example.com/data-access/models"
	"github.com/golang-jwt/jwt"
)

func ExtractTokenData(w http.ResponseWriter, r *http.Request) (models.User, error) {
	authHeader := r.Header.Get("Authorization")
	if authHeader == "" {
		fmt.Printf("Authorization header missing")
	}
	authValues := strings.Fields(authHeader)

	token, err := Token.ParseToken(authValues[1])
	if err != nil {
		fmt.Println("Error parsing token:", err)
	} else {
		if claims, ok := token.Claims.(jwt.MapClaims); ok && token.Valid {
			var user models.User
			user.Id = claims["user_id"].(float64)
			user.User_admin = claims["user_admin"].(bool)
			return user, err
		} else {
			fmt.Println("Invalid token")
		}
	}
	return models.User{}, err
}
