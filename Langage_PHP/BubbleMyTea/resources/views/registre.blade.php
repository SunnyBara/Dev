<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <link rel="stylesheet" href="/css/registre.css">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Registre</title>
    <script src="js/script.js" defer></script>
</head>

<body>
    @include('includes.header') 
    <form method="POST" onsubmit="return validatePassword();">
    @csrf
        <label for="nom">Name :</label>
        <input type="text" id="nom" name="nom" required />

        <label for="prenom">First name :</label>
        <input type="text" id="prenom" name="prenom" required />

        <label for="email">Email :</label>
        <input type="email" id="email" name="email" required />

        <label for="password1">Password :</label>
        <input type="password" id="password1" name="password1" required />

        <label for="password2">Confirm Password :</label>
        <input type="password" id="password2" name="password2" required />

        <button type="submit">Submit</button>
    </form>
</body>

</html>