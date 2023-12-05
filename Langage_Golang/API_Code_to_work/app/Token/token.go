package Token

import (
	"fmt"
	"time"

	"example.com/data-access/models"
	"github.com/golang-jwt/jwt"
)

var secretKey = []byte("your-secret-key") // placeholder à changer pour la sécurité

func CreateToken(user models.User) (string, error) {
	fmt.Printf("user id  %f , state %v name %s passeword %s\n\n", user.Id, user.User_admin, user.User_name, user.User_password)
	token := jwt.New(jwt.SigningMethodHS256)
	claims := token.Claims.(jwt.MapClaims)
	claims["user_id"] = user.Id
	claims["user_admin"] = user.User_admin
	claims["exp"] = time.Now().Add(time.Minute * 1).Unix()

	tokenString, err := token.SignedString(secretKey)
	if err != nil {
		return "", err
	}
	return tokenString, nil
}

func ParseToken(tokenString string) (*jwt.Token, error) {
	token, err := jwt.Parse(tokenString, func(token *jwt.Token) (interface{}, error) {
		return secretKey, nil
	})

	if err != nil {
		return nil, err
	}

	return token, nil
}
