TO use this Orm you need to set up a model of your table that extend Tab

example:
"export class User extends Tab {}"

since this moment you are free to use some function like get();
(the query is in asynchronous context so you have to use await or set up a promise with callback)

here an exemple for each cases:

1/ await

async function test() {
const user = new User();
const users = await user.get();
console.log(users);
}
test();

2/ Promise
const user = new User();
const Promiseusers = user.get();
Promiseusers.then((users) => {
console.log(users);
});

To add/del/update specifics items you need to declare the columns that you are using in the database

List of Functions :
Table.all() => get all items from table 'Table'
item.get() => get the item from his instance table (The table might contain a primary key to ensure a consistent result)
item.save() => save current item in the database if the current id already exist this function will update the information.
