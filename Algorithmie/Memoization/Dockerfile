FROM ubuntu:latest

RUN apt-get update && apt-get install -y valgrind
COPY . . 
CMD ["valgrind --leak-check=full", "./factoriel.out"]
