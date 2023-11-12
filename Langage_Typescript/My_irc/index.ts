import { Server, Socket } from "socket.io";
import express from 'express';
import http, { IncomingMessage } from 'http';
import bodyParser from "body-parser"
import { User } from './src/data/User';
import { getUserInfo, isUserExist } from './Database/user_table';
import expressSession, {SessionData} from 'express-session';
import Room from './src/data/Room';

declare module 'express-session' {
    interface SessionData {
        user?: { 
          login: string,
          password: string,
          rooms?: Room[],
          friendList?: User[],
          user_Id?: number
        };
    }
};

interface SessionIncomingMessage extends IncomingMessage{
    session : SessionData
};

interface SessionSocket extends Socket {
    request: SessionIncomingMessage
};

const app = express();
const server = http.createServer(app);
const io = new Server(server);

const session = expressSession({
    secret : 'verysecret',
    resave: false,
    saveUninitialized: true,
    cookie: {}
})


const wrapper = (middleware : any) => (socket : Socket, next : any ) => middleware(socket.request, {},next);
io.use(wrapper(session));



const jsonParser = bodyParser.json();
const urlencodePdParser = bodyParser.urlencoded({extended: true})

app.use(jsonParser);
app.use(urlencodePdParser);
app.use(session);

app.get('/',(req,res) => {
    res.redirect('/login');
});


app.get('/login',(req,res) => {
    res.sendFile(__dirname + "/login.html")
});
 
app.post("/login",async (req,res) => {
  const username = req.body.username;
  const password = req.body.password;
  let userlog = new User(username,password)
  if(await isUserExist(userlog)){
    const userindb = await getUserInfo(userlog);
    if(userlog._password === userindb._password ) { 
      req.session.user = {
        user_Id: userindb._user_Id,
        password: userindb._password,
        login: userindb._login,
        rooms : userindb.rooms,
        friendList : userindb.friendList
      }
      res.redirect('/chat');
    } else {
        res.send('Invalid password')
    }
  } else {
      console.log(`${userlog._login} is not in the database`);
  }
    })


app.get('/chat',(req,res) => {{
    if(req.session.user) {
        res.sendFile(__dirname + '/chat.html');
    } else {
        res.redirect('/login');
    }
  
}})

io.on('connection',(defaultSocket : Socket) => {
    const socket = <SessionSocket> defaultSocket;
    const userSession = socket.request.session.user
    if(userSession) {
        socket.on('chat message', (message)=> {
            io.emit('chat message', `${userSession.login}:  ${message}`);
        });
        socket.on('disconnect', () => {
            console.log('user disconnected');
        });
    }
});

server.listen(3000, ()=> {
    console.log('serveur running at http:localhost:3000');
});
