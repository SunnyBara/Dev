<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\User;
use App\Models\Item;

class Useregistration extends Controller
{
    public function register(Request $request)
    {
        $user = new User([
            'lastname' => $request->input('nom'),
            'firstname' => $request->input('prenom'),
            'email' => $request->input('email'),
            'password' => ($request->input('password1')),
        ]);
        $user->save();
        return redirect('/');
    }


}