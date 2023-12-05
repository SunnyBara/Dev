<!DOCTYPE html>
<html lang="fr">

<head>
    <meta charset="UTF-8">
    <link rel="stylesheet" href="/css/login.css">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login</title>

</head>

<body>

@include('includes.header')

    <form id="form" action="/" method="post">
        @csrf
        <label for="email">Email :</label>
        <input type="email" id="email" name="email" required />

        <label for="password">Password :</label>
        <input type="password" id="password" name="password" required />
        <button>Send</button>
        <p>You don't have an account ?<br><a href="/registre">click here</a> to register.</p>

    </form>

</body>

</html>