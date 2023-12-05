FROM golang:1.21.4
EXPOSE 8080
WORKDIR /app

COPY go.mod go.sum ./
RUN go mod download

COPY . .
RUN go build
CMD ./data-access