drop database  if exists IRC;
create database if not exists IRC;
use IRC;

create table if not exists User (
	Id INTEGER(6) NOT NULL AUTO_INCREMENT,
	User_Name varchar(15) not null,
	User_Password varchar(15) not null,
	PRIMARY KEY (id)
);
create table if not exists Room (
	Id INTEGER(6) NOT NULL AUTO_INCREMENT,
	Room_Name varchar(15) not null,
	Date_Creation DATETIME NOT NULL default Now(),
	Nb_User_Max INTEGER(4),
	Nb_User_Current INTEGER(4),
	Id_User_Admin INTEGER(6) Not Null,
	PRIMARY KEY (Id) ,
	FOREIGN key (Id_User_Admin) REFERENCES User (Id)
);

create table if not exists User_To_Room (
	Id_User INTEGER(6) not null ,
	Id_Room INTEGER(6) not null ,
	FOREIGN key (Id_User) REFERENCES User(Id),
	FOREIGN key (Id_Room) REFERENCES Room(Id) 
) ;

create table if not exists Room_Message (
	Id INTEGER(6) NOT NULL AUTO_INCREMENT,
	Id_Room INTEGER(6) NOT NULL,
	Id_User INTEGER(6) NOT NULL,
	Content TEXT NOT NULL,
	Date_Send DATETIME NOT NULL default Now() ,
	PRIMARY key (Id), 
	FOREIGN KEY (Id_User) REFERENCES User(Id),
	FOREIGN KEY (Id_Room) REFERENCES Room(Id)
);
create table if not exists Private_Message (
	Id INTEGER(6) NOT NULL AUTO_INCREMENT,
	Id_Sender INTEGER(6) NOT NULL,
	Id_Receiver INTEGER(6) NOT NULL,
	Content TEXT NOT NULL,
	Date_Send DATETIME NOT NULL default Now() ,
	PRIMARY key (Id), 
	FOREIGN KEY (Id_Sender) REFERENCES User(Id),
	FOREIGN KEY (Id_Receiver) REFERENCES User(Id)
);

insert into user (User_name,User_password) VALUES ('michel','letest');
insert into user (User_name,User_password) Values ('jean','letest');
insert into Room (Room_Name,Nb_User_max,Nb_User_current,Id_User_Admin) values ('totoroom',4,1,1);
