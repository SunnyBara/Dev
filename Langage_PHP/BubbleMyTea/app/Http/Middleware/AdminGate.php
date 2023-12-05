<?php

namespace App\Http\Middleware;

use Closure;
use Illuminate\Http\Request;
use Illuminate\Routing\Controllers\Middleware;
use Symfony\Component\HttpFoundation\Response;


// $next est une variable qui contient une fonction qui permet
// de passer de ce middleware au suivant s'il y en a un,
// de reprendre le processing de la requête.

// {
//     /**
//      * Handle an incoming request.
//      *
//      * @param  \Closure(\Illuminate\Http\Request): (\Symfony\Component\HttpFoundation\Response)  $next
//      */
//     public function handle(Request $request, Closure $next): Response
//     {
//         return $next($request);
//     }
// }
class AdminGate
   {
    public function handle(Request $request, Closure $next): Response 
    {
        $admin = session('admin');
        if ($admin) {
            return ($next($request));
        } else {
           return redirect('/');
        }
    }
}