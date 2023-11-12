//import { Server } from "socket.io";
import express from 'express';
import http from 'http';
import bodyParser from "body-parser"
import { User } from './src/data/User';
import { isUserExist } from './Database/user_table';

const app = express();
const server = http.createServer(app);

const jsonParser = bodyParser.json();
const urlencodePdParser = bodyParser.urlencoded({extended: true})

app.use(jsonParser);
app.use(urlencodePdParser);

app.get('/',(req,res) => {
    res.send('ok')});


app.get('/login',(req,res) => {
    res.sendFile(__dirname + "/login.html")
});
 
    app.post("/login",async (req,res) => {
        const username = req.body.username;
        const password = req.body.password;
        const userlog = new User(username,password)
        if(await isUserExist(userlog)){
    
        }
    })

app.get('/chat',(req,res) => {{
    res.send('Chat')
}})
server.listen(3000, ()=> {
    console.log('serveur running at http:localhost:3000');
});
