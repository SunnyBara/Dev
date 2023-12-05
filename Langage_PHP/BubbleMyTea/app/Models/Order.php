<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;
use Illuminate\Database\Eloquent\Relations\BelongsTo;

class Order extends Model
{
    use HasFactory;

    protected $fillable = [
        'status',
        'user_id',
    ];
    public function user(): BelongsTo {
        return $this->belongsTo(User::class, 'user_id');
        // protected $guarded = ['user_id']; 
    }
    public function items() {
        return $this->belongsToMany(Item::class, 'items_orders');
    }
    function attachItem($order, $item) {
        $order->items()->attach($item);
    }
    public static function createOrder($status, $user) {
        $order = new Order([
            'status' => $status,
        ]);
        $order->user()->associate($user);
        $order->save();
        return ($order);
    }
    public static function updateOrder($order) {
        $order->save();
        return ($order);
    }

    public static function getOrderById($id) {
        return Order::where('id', $id)->first();
    }

    public static function getOrdersByUser($user) {
        $orders = $user->orders()->get();
        return ($orders);
    }

    public static function getOrderByStatus($status) {
        $orders = Order::where('status', $status)->get();
        return ($orders);
    }
    public static function deleteOrder($order) {
        $order->delete();
    }
}
class OrderDetails
{
    public $order;
    public $items;
    public $price;

    public function __construct(Order $order, float $price)
    {
        $this->order = $order;
        $this->price = $price;
    }
}