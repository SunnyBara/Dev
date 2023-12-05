<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;
use Illuminate\Database\Eloquent\Relations\BelongsTo;
use Illuminate\Database\Eloquent\Relations\BelongsToMany;

class Item extends Model
{
    use HasFactory;
    protected $fillable = [
        'name',
        'description',
        'picture_name',
        'price',
        'type_id',
    ];
    // protected $guarded = ['type_id'];

    public function itemsType(): BelongsTo {
        return $this->belongsTo(ItemsType::class, 'type_id');
    }
    // La fonction itemsType renvoie un lien entre laclasse ItemType et la colonne type_id dans $this.
    // par defaut ca va vers la colonne id de la Classe en argument si aucune autre n'est précisée.
    public function orders(): BelongsToMany {
        return $this->belongsToMany(Order::class, 'items_orders');
    }
    // renvoie ce que belongsToMany renvoie avec cette classe et cette table d'association spécifiques en arguments.
    // permet de lier this (donc l instance d Item créée avec cette fonction) à la classe Order 
    // (qui a pour fonction d être un modèle),via la table items_orders
    // et donc à tous les orders dont cet item fait partie.
    public static function attachOrder($item, $order) {
        $item->orders()->attach($order);
    }
    // La fonction attachOrder appelle la fonction orders, (qui renvoie un lien), dans une instance d'Item.
    // Ensuite on appelle la fonction attach qui est ds le lien renvoyé par orders,(le lien est une classe de type 
    // BelongsToMany), et qui prend en argument une instance d'Order.
    // Cela crée un lien entre un item et un order dans la table items_orders ( grace à orders).
    public static function createItem($name, $description, $picture_name, $price, $itemsType) {
        $item = new Item([
            'name' => $name,
            'description' => $description,
            'picture_name' => $picture_name,
            'price' => $price,
        ]);
        $item->itemsType()->associate($itemsType);
        $item->save();
        return ($item);
    }
    //  associate est un attach solo.
    public static function updateItem($item) {
        $item->save();
        return ($item);
    }

    public static function getItemById($id) {
        return Item::where('id', $id)->first();
    }
        // comme Item extends la classe Model du coup c'est lui-même un modèle 
        // et peut utiliser les fonctions de la classe Model. 
        // Je peux donc appeler la fonction statique where qui me permet de faire une requete sql
        // via Eloquent. select le premier FROM items WHERE id = le contenu de $id.
    public static function getItemByOrder($order) {
        $items = $order->items()->get();
        // sur mon instance du modèle Order j'appelle ma fonction items qui crée le lien
        // coté php (qui représente le lien sql via les foreign keys) entre les tables items et orders,
        // ensuite j'appelle la fonction get qui récupère tous les items attachés à cet order via ce lien.
        return ($items);
    }

    public static function getItemsByType($itemsType) {
        $items = $itemsType->items()->get();
        return ($items);
    }
        // sur mon instance du modèle itemsType j'appelle ma fonction items qui est dans Itemstype 
        // et qui crée le lien coté php (qui représente le lien sql via les foreign keys) entre les tables items 
        // et items_types, ensuite j'appelle la fonction get qui récupère tous les items attachés 
        // à cet instance d'itemsType via ce lien.
    public static function getItemByName($name) {
        $items = Item::where('name', $name)->get();
        // comme Item extends la classe Model du coup c'est lui-même un modèle 
        // et peut utiliser les fonctions de la classe Model. 
        // Je peux donc appeler la fonction statique where qui me permet de faire une requete sql
        // via Eloquent. select * FROM items WHERE name = le contenu de $name.
        return ($items);
    }

    public static function getItemByPrice($price) {
        $items = Item::where('price', $price)->get();
        return ($items);
    }
    public static function deleteItem($item) {
        $item->delete();
    }
}




