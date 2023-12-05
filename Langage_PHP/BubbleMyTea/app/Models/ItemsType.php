<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class ItemsType extends Model
{
    use HasFactory;
    protected $fillable = ['name'];
    public function items() {
        return $this->hasMany(Item::class, 'type_id');
    }
    // déclaration en php d'un lien sql. Ici,qu'il existe de multiples référence à l'id de $this 
    // dans la colonne type_id de la classe Item.
    public static function createItemsType($name) {
        $itemsType = new ItemsType([
            'name' => $name,
        ]);
        $itemsType->save();
        return ($itemsType);
    }
    public static function updateItemsType($itemsType) {
        $itemsType->save();
        return ($itemsType);
    }

    public static function getItemsTypeById($id) {
        return ItemsType::where('id', $id)->first();
    }

    public static function getItemsTypeByName($name) {
        $itemsType = ItemsType::where('name', $name)->get();
        return ($itemsType);
    }


    public static function deleteItemsType($itemsType) {
        $itemsType->delete();
    }
}

