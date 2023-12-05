<!DOCTYPE html>
<html lang="fr">

<head>
    <meta charset="UTF-8">
    <link rel="stylesheet" href="/css/dashboard.css">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Dashboard</title>
</head>

<body>
    @include('includes.header')

    <div class="container">
        <div class="sidebar">
            <ul class = "mylist">
                <li><a href="{{ route('dashboardProfil', ['id' => $user->id]) }}" class="{{ Request::is('dashboardProfil') ? 'active' : '' }}">Profile</a>
                <li><a href="{{ route('Dashboard', ['id' => $user->id]) }}" class="{{ Request::is('dashboard') ? 'active' : '' }}">My Orders</a></li>
                <li><a href="{{ route('order', ['id' => $user->id]) }}" class="{{ Request::is('order') ? 'active' : '' }}">Order</a></li>
            </ul>

            <button class="logout-button">Logout</button>

        </div>
        <div class="main-content">
            <!-- <form action="/traitement" method="post"> -->
            <form action="/dashboardProfil/{{$user->id}}" method="post" >
                @csrf
                <div class="input-group">
                    <label for="nom">Nom :</label>
                    <input type="text" id="nom" name="nom" value={{$user->lastname}}>
                    <button type="button" class="pen-button">&#9999;</button>
                </div>

                <div class="input-group">

                    <label for="prenom">Prénom :</label>
                    <input type="text" id="prenom" name="prenom" value={{$user->firstname}} required>
                    <button type="button" class="pen-button">&#9999;</button>
                </div>

                <div class="input-group">

                    <label for="email">Email :</label>
                    <input type="email" id="email" name="email" value={{$user->email}} required>
                    <button type="button" class="pen-button">&#9999;</button>
                </div>
                <br><br>
                <button type = "sumbit"> Sauvegarder</button>
            </form>

        </div>
    </div>

</body>

</html>