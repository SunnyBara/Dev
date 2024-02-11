import { goright } from "./vaisseaux";

const express = require("express");

export const app = express();

app.use(express.static("public"));

app.listen(3000, () => {
  console.log("connected");
});

app.get("/", (request, response) => {
  response.sendFile(__dirname + "/homepage.html");
});
app.get("/moveright", (request: Request, response) => {
  console.log(request);
  response.send(goright(10));
});
