//import { Server } from "socket.io";
import express from 'express';
import http from 'http';

const app = express();
const server = http.createServer(app);

app.get('/',(req,res) => {
    res.send('Hello World');
});

server.listen(3000, ()=> {
    console.log('serveur running at http:localhost:3000');
});
