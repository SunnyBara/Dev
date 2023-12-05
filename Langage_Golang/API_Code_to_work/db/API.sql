drop database  if exists API;
create database if not exists API;
use API;

create table if not exists users (
	id INTEGER(6) NOT NULL AUTO_INCREMENT,
	user_name varchar(20) not null,
	user_password varchar(255) not null,
	user_admin boolean default 0,
  user_age INTEGER(2),
  user_sexe VARCHAR(1),
  user_weight INTEGER(3),
  user_height INTEGER(3),
	PRIMARY KEY (id)
);

create table if not exists foods (
	id INTEGER(6) NOT NULL AUTO_INCREMENT,
	food_name varchar(50) not null,
  food_calories FLOAT(3) NOT NULL,
  food_protein FLOAT (3) NOT NULL,
  food_carbohydrate FLOAT(3) NOT NULL,
  food_lipid FLOAT(3) NOT NULL,
	food_description varchar(255),
	PRIMARY KEY (id)
);


create table if not exists weight (
  id integer(6) NOT NULL AUTO_INCREMENT,
  user_id integer(6),
  weight integer(3),
  created_at timestamp default now(),
  FOREIGN KEY(user_id) REFERENCES users(id),
  PRIMARY KEY(id)
);

create table if not exists meals (
  id integer(6) NOT NULL AUTO_INCREMENT,
  user_id integer(6),
  created_at timestamp default now(),
  FOREIGN KEY(user_id) REFERENCES users(id),
  PRIMARY KEY(id)
);

create table if not exists meals_foods (
  id integer(6) NOT NULL AUTO_INCREMENT,
  meal_id integer(6),
  food_id integer(6),
  PRIMARY KEY (id),
  FOREIGN KEY (meal_id) REFERENCES meals(id),
  FOREIGN KEY (food_id) REFERENCES foods(id)
);

create table if not exists notes (
  id integer(6) NOT NULL AUTO_INCREMENT,
  user_id integer(6),
  body text,
  created_at timestamp default now(),
  PRIMARY KEY (id),
  FOREIGN KEY (user_id) REFERENCES users(id)
);