<?php

use Illuminate\Support\Facades\Route;
use SebastianBergmann\CodeCoverage\Report\Html\Dashboard;
use App\Http\Controllers\useregistration;
use App\Http\Controllers\admin;
use App\Models\Item;
use App\Models\ItemsType;
use App\Models\User;
use App\Models\Order;
use App\Http\Controllers\DashboardController;
use App\Http\Controllers\OrderController; 
/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider and all of them will
| be assigned to the "web" middleware group. Make something great!
|
*/

Route::get('/', function () {
    return view('welcome');
});
Route::post('/',[DashboardController::class, 'login']);


Route::get('/registre', function () {
    return view('registre');
});
Route::post('/registre', [useregistration::class, 'register'])->name('registre');

Route::get('/dashboardProfil/{id}', [DashboardController::class, 'Dashboardprofil'])->name('dashboardProfil');

Route::post('/dashboardProfil/{id}', [DashboardController::class, 'alteruser'])->name('dashboardProfil'); 

Route::get('/dashboard/{id}', [DashboardController::class, 'index'])->name('Dashboard'); 

Route::post('/dashboard/{id}', [DashboardController::class, 'index'])->name('Dashboard');

// route::get('/createUserTest',function() {
//     echo("CREATE USER");
//     $user = User::create(['type' => 'client', 'firstname' => 'Roger', 'lastname' => 'Letavernier', 'email' => 'letavernier@gmail.com', 'password' => 'password' ]);
//     echo($user);
// });

// route::get('/createUserTest',function() {
//     echo("CREATE USER");
//     $user = User::create(['type' => 'client', 'firstname' => 'Roger', 'lastname' => 'Letavernier', 'email' => 'letavernier@gmail.com', 'password' => 'password' ]);
//     echo($user);
// });

route::get('/createUserTest', function () {
    echo ("CREATE USER");

    // $user = new User([
    //     'type' => 'customer',
    //     'firstname' => 'Sandrine',
    //     'lastname' => 'Feedy',
    //     'email' => 'sandrine.feedy@hmail.com',
    //     'password', 'passwoo'
    // ]);
    // $user->save();

    User::createUser('customer', 'Sandrine', 'Feedy', 'sandrine.feedy@hmail.com', 'passwoo');
});

route::get('/getUserTest', function () {
    echo ("GET USER");
    $users = User::all();
    echo ($users);
});

route::get('/createItemsTypeTest', function () {
    echo ("CREATE ITEMS_TYPE");

    $itemsType = new ItemsType([
        'name' => 'Sandrine',
    ]);
    $itemsType->save();
});
// route::get('/createItemsTypeTest',function() {
//     echo("CREATE ITEMSTYPE");
//     $itemsType = ItemsType::create(['name' => 'Black Tea']);
//     echo($itemsType);
// });

route::get('/getItemsTypeTest', function () {
    echo ("GET ITEMSTYPE");
    $itemsTypes = ItemsType::all();
    echo ($itemsTypes);
});
route::get('/createOrderTest', function () {
    echo ("CREATE ORDER");
    $user = User::where('id', 1)->first();
    echo ($user);

    $order = new Order([
        'status' => 'en cours',
    ]);
    $order->user()->associate($user);
    $order->save();
});
// route::get('/createOrderTest',function() {
//     echo("CREATE ORDER");
//     $order = Order::create(['status' => 'En cours', 'user_id' => 1]);
//     echo($order);
// });

// route::get('/getOrderTest', function () {
//     echo ("GET ORDER FROM USER");
//     $orders = Order::all();
//     echo ($orders);
// });

// route::get('/getOrdersFromUser', function () {
//     echo ("GET ORDER");
//     $user = User::getUserById(1);
//     $orders = $user->orders()->get();
//     echo ($orders);
// });


// route::get('/createItemTest', function () {
//     echo ("CREATE ITEM YUY");
//     $type = ItemsType::where('id', 1)->first();
//     echo ($type);

//     $item = new Item([
//         'name' => 'teatits fraise',
        // 'description' => 'meilleur tea du monde',
//         'picture_name' => 'vive la photo',
//         'price' => 4.50
//     ]);
//     $item->itemsType()->associate($type);
//     $item->save();
    // $item->name = 'toto';
    // $item->save();
    //$item = Item::create(['name' => 'teatits fraise', 'picture_name' => 'vive la photo', 'price' => 4.50, 'type_id' => 1]);
    // echo($item);
// });

// route::get('/getOneItemTest', function () {
//     echo ("GET One ITEM");
//     $item = Item::where('id', 3)->update(['name' => 'raspberry black tea']);
//     echo ($item);
// });

// route::get('/getItemTest', function () {
//     echo ("GET ITEM");
//     $items = Item::all();
//     echo ($items);
// });

// route::get('/LinkItemToOrder', function () {
//     echo ("GET LinkItemToOrder");
//     $item = Item::getItemById(3);
//     $order = Order::getOrderById(1);
//     $item->orders()->attach($order);
// });

Route::get('/admin', [admin::class, 'show'])
->middleware('App\\Http\\Middleware\\AdminGate');

Route::get('/modif_item',function() {
    return view('modif_item');
})->middleware('App\\Http\\Middleware\\AdminGate');

Route::post('/modif_item', [admin::class, 'addarticle'])->name('modif_item')
->middleware('App\\Http\\Middleware\\AdminGate');
Route::post('/admin/{id}', [admin::class, 'modifarticle'])->name('admin')
->middleware('App\\Http\\Middleware\\AdminGate');

Route::get('/order/{id}',[orderController::class,'show'])->name('order');

Route::delete('/delete-item/{id}', [admin::class, 'deleteItem'])->name('delete.item')
->middleware('App\\Http\\Middleware\\AdminGate');;