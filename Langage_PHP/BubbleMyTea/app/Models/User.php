<?php

namespace App\Models;

// use Illuminate\Contracts\Auth\MustVerifyEmail;
use Illuminate\Database\Eloquent\Factories\HasFactory;
// use Illuminate\Foundation\Auth\User as Authenticatable;
use Illuminate\Notifications\Notifiable;
// use Laravel\Sanctum\HasApiTokens;
use Illuminate\Database\Eloquent\Model;

class User extends Model
{
    use HasFactory, Notifiable;

    /**
     * The attributes that are mass assignable.
     *
     * @var array<int, string>
     */
    protected $fillable = [
        'admin',
        'firstname',
        'lastname',
        'email',
        'password',

    ];

    public function orders() {
        return $this->hasMany(Order::class, 'user_id');
    }
    public static function createUser($admin, $firstname, $lastname, $email, $password) {
        $user = new User([
            'admin' => $admin,
            'firstname' => $firstname,
            'lastname' => $lastname,
            'email' => $email,
            'password' => $password,
        ]);
        $user->save();
        return ($user);
    }
    public static function updateUser($user) {
        $user->save();
        return ($user);
    }

    public static function getUserById($id) {
        return User::where('id', $id)->first();
    }
    public static function getUserByEmail($mail) {
        return User::where('email', $mail)->first();
    }
    public static function getUsersByLastname($lastname) {
        return User::where('lastname', $lastname)->get();
    }
    public static function deleteUser($user) {
        $user->delete();
    }
}


/**
 * The attributes that should be hidden for serialization.
 *
 * @var array<int, string>
 */
// protected $hidden = [
//     'password',
//     'remember_token',
// ];

// /**
//  * The attributes that should be cast.
//  *
//  * @var array<string, string>
//  */
// protected $casts = [
//     'email_verified_at' => 'datetime',
//     'password' => 'hashed',
// ];
