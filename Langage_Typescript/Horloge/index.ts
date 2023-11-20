import * as path from 'path';


const express = require('express');

const app = express();
app.use(express.static('public'));


app.listen(3000,() => {
    console.log("serveur connecté");
})

app.get('/', (request: Request, response) => {
    response.sendFile(__dirname + '/horloge.html');
  });

  app.get('/gethours',(request: Request, response) => {
    response.send(new Date().toLocaleTimeString());
  })