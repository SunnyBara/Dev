<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\Item;



class admin extends Controller
{

    public function show() {        
        $listofItems = Item::all();
        return view('admin',['items' => $listofItems]);
    }


    public function addarticle(Request $request) {
        $item = new Item([
            'name' => $request->input('name'),
            'picture_name' => $request->input('picture'),
            'description' => $request->input('description'),
            'price' => $request->input('price'),
            'type_id' => ($request->input('articleType')),
        ]);
        $item->save();
        return redirect('/admin');
    }
    public function deleteItem($id)
    {
       $item = Item::find($id);
       $item->delete();
        return redirect('/admin');
    }
    public function modifarticle(Request $request,$id) {
        $item = Item::getItemById($id);
        $item->name = $request->input('name');
        $item->description = $request->input('description');
        $price = $request->input('price');
        $item->price = str_replace("€", "",$price);
        $item->save();
        return redirect('/admin');
    }
}