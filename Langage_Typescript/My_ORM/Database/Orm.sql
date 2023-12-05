drop database if exists ORM;
create database if not exists ORM;
use ORM;

create table if not exists users (
    id INTEGER(6) NOT NULL AUTO_INCREMENT,
    user_login VARCHAR(20) NOT NULL,
    user_email VARCHAR(50) NOT NULL,
    PRIMARY KEY (id)
);

create table if not exists products (
    id INTEGER(6) NOT NULL AUTO_INCREMENT,
    product_name VARCHAR(20) NOT NULL,
    PRIMARY KEY (id)
);

create table if not exists user_product (
    id INTEGER(6) NOT NULL AUTO_INCREMENT,
    user_id INTEGER(6) NOT NULL,
    product_id INTEGER(6) NOT NULL,
    FOREIGN KEY (user_id) REFERENCES users(id),
    FOREIGN KEY (product_id) REFERENCES products(id),
    PRIMARY KEY (id)    
);

create table if not exists messages (
    id INTEGER(6) NOT NULL AUTO_INCREMENT,
    user_id INTEGER(6) NOT NULL,
    message_content VARCHAR(255) NOT NULL,
    FOREIGN KEY (user_id) REFERENCES users(id),
    PRIMARY KEY (id)
    );