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
            <ul>
                <li><a href="{{ route('dashboardProfil', ['id' => $user->id]) }}" class="{{ Request::is('dashboardProfil') ? 'active' : '' }}">Profile</a></li>
                <li><a href="{{ route('Dashboard', ['id' => $user->id]) }}" class="{{ Request::is('dashboard') ? 'active' : '' }}">My Orders</a></li>
                <li><a href="{{ route('order', ['id' => $user->id]) }}" class="{{ Request::is('order') ? 'active' : '' }}">Order</a></li>
            </ul>
            <button class="logout-button">Logout</button>
        </div>
        <div class="orders-container">
    <?php foreach ($Detailsorders as $Detailsorder): ?>
        <div class="detailorder">
            <div class="order-info">
                <div class="date">Date: {{ $Detailsorder->order->created_at }}</div>
                <div class="price">Price: {{ $Detailsorder->price }}</div>
            </div>
            <div class="items">
                <?php foreach ($Detailsorder->items as $item): ?>
                    <?php if ($item->type_id === 1): ?>
                        <div class="tea-item">
                            <img src="/images/articles/{{$item->picture_name}}" alt="{{ $item->name }}" width=  "50" height="50">
                        </div>
                    <?php else: ?>
                        <div>{{ $item->name }}</div>
                    <?php endif; ?>
                <?php endforeach; ?>
            </div>
            <div class="status">Status: {{ $Detailsorder->order->status }}</div>
        </div>
    <?php endforeach; ?>
</div>
 </div>

</body>

</html>

