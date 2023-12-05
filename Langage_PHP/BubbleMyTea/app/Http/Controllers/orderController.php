<?php

namespace App\Http\Controllers;

use App\Models\Item;
use Illuminate\Http\Request;

class orderController extends Controller {
    public function show() {        
        $id = session('id');
        $listofItems = Item::all();
        return view('order',['items' => $listofItems, 'id' => $id]);
    }
}
