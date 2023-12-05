<?php

namespace App\Http\Controllers;

use App\Models\User;
use Illuminate\Http\Request;
use App\Models\Order;
use App\Models\OrderDetails;
use App\Models\Item;

class DashboardController extends Controller
{

    public function my_reverse($array): array {
        $revarray = [];
        $sizeofarray = sizeof($array);
        $i = 0;
        while ($i < $sizeofarray) {
            $revarray[$sizeofarray - $i - 1] = $array[$i];
            $i += 1;
        }
        return ($revarray);
    }

    public function index($id) {
        $user = User::getUserById($id);
        $orders = Order::getOrdersByUser($user);
        $Detailsorders = [];
        $i = 0;
        $orders = $this->my_reverse($orders);
        while ($i < sizeof($orders)) {
            $items = Item::getItemByOrder($orders[$i]);
            $j = 0;
            $price = 0;
            while ($j < sizeof($items)) {
                $price += $items[$j]->price;
                $j += 1;
            }
            $detailorder = new OrderDetails($orders[$i], $price);
            $detailorder->items = $items;
            $Detailsorders[$i] = $detailorder;
            $i += 1;
        }
        return view('/dashboard', ['user' => $user, 'Detailsorders' => $Detailsorders]);
    }

    public function login(Request $request) {
        $email = $request->email;
        $password = $request->password;
        $user = User::getUserByEmail($email);
        if ($user != null && $user->password === $password) {
            session(['id' => $user->id, 'admin' => $user->admin]);
            return view('/dashboardProfil', ['user' => $user]);
        } else {
            return view('welcome');
        }
    }

    public function Dashboardprofil($id) {
        $user = User::getUserById($id);
        return view('/dashboardProfil', ['user' => $user]);
    }

    public function alteruser(Request $request, $id) {
        $user = User::getUserById($id);
        $user->lastname = $request->input('nom');
        $user->firstname = $request->input('prenom');
        $user->email = $request->input('email');
        $user->save();
        return view('/dashboardProfil', ['user' => $user]);
    }

}