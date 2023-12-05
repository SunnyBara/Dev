<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="/css/order.css">
    <title>Your Orders </title>
</head>

<body>
    @include('includes.header')

    <ul>
                <li><a href="{{ route('dashboardProfil', ['id' => $id]) }}" class="{{ Request::is('dashboardProfil') ? 'active' : '' }}">Profile</a></li>
                <li><a href="{{ route('Dashboard', ['id' => $id]) }}" class="{{ Request::is('dashboard') ? 'active' : '' }}">My Orders</a></li>
                <li><a href="{{ route('order', ['id' => $id]) }}" class="{{ Request::is('order') ? 'active' : '' }}">Order</a></li>
            </ul>
    <div class="order-container">
        <div class="order-header">
            <h2>Your Orders</h2>
        </div>
        <div class="order-list">
            <div class="order-list">
                @foreach($items as $item)
                <div class='item item{{ $item->type_id }}' id='item{{ $item->type_id }}' data-id="{{ $item->type_id }}"
                    data-price="{{ $item->price }}">
                    <img src="{{ asset ('images/articles/' . $item->picture_name) }}" alt="{{ $item->name }}">
                    <h3>{{ $item->name }}</h3>
                    <p>{{ $item->description }}</p>
                </div>
                @endforeach
            </div>

            <div id="error-banner">You have reached the maximum limit for this item type.</div>

        </div>
    </div>


    <<div class="vertical-navbar">
        <div class="selected-items">
            <h3>Selected Items</h3>
            <ul id="selected-items-list"></ul>
        </div>

        <div class="total-amount">
            <h3>Total Amount</h3>
            <p id="total-amount">0.00</p>
        </div>


        <div class="pay-button-container">
            <button class="pay-button">Pay</button>
        </div>
        </div>

        <script>
        document.addEventListener('DOMContentLoaded', function() {
            var selectedItemsCount = {
                '1': 0,
                '2': 0,
                '3': 0
            };

            var maxLimits = {
                '1': 1,
                '2': 3,
                '3': 1
            };

            var items = document.querySelectorAll('.item');

            items.forEach(function(item) {
                item.addEventListener('click', function() {
                    var type = this.getAttribute('data-id');
                    var name = this.querySelector('h3').textContent;
                    var price = parseFloat(this.getAttribute('data-price'));

                    if (selectedItemsCount[type] < maxLimits[type]) {
                        addToSelectedItemsList(name, price, type);
                        updateTotalAmount(price);
                        selectedItemsCount[type]++;
                        hideSelectedItem(this);
                    } else {
                        displayErrorBanner('You reached the maximum limit for this item type.');
                    }
                });
            });

            var selectedItemsList = document.getElementById('selected-items-list');
            selectedItemsList.addEventListener('click', function(event) {
                var listItem = event.target.closest('li');
                if (listItem) {
                    var price = parseFloat(listItem.textContent.split('$')[1]);
                    var type = listItem.getAttribute('data-type-id');
                    removeFromSelectedItemsList(listItem, price, type);
                }
            });

            function addToSelectedItemsList(name, price, type) {
                var listItem = document.createElement('li');
                listItem.textContent = name + ' - $' + price.toFixed(2);
                listItem.setAttribute('data-type-id', type);
                selectedItemsList.appendChild(listItem);
            }

            function updateTotalAmount(price) {
                var totalAmountElement = document.getElementById('total-amount');
                var currentTotal = parseFloat(totalAmountElement.textContent);
                var newTotal = currentTotal + price;
                totalAmountElement.textContent = newTotal.toFixed(2);
            }

            function displayErrorBanner(message) {
                var errorBanner = document.getElementById('error-banner');
                errorBanner.textContent = message;
                errorBanner.style.display = 'block';

                setTimeout(function() {
                    errorBanner.style.display = 'none';
                }, 3000);
            }

            function removeFromSelectedItemsList(listItem, price, type) {
                var currentTotal = parseFloat(document.getElementById('total-amount').textContent);
                var newTotal = currentTotal - price;
                document.getElementById('total-amount').textContent = newTotal.toFixed(2);

                var correspondingItem = document.querySelector('.item[data-id="' + type +
                    '"]:not([style*="display: block"])');
                if (correspondingItem) {
                    correspondingItem.style.display = 'block';
                }

                listItem.remove();
                selectedItemsCount[type]--;
            }
        });
        </script>

</body>

</html>