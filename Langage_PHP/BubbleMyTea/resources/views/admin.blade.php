<!DOCTYPE html>
  <html lang="{{ str_replace('_', '-', app()->getLocale()) }}">
    <head>
      <meta charset="utf-8">
      <meta name="viewport" content="width=device-width, initial-scale=1">
      <title>Admin</title>
      <script type="text/javascript" src="/js/admin.js"></script>
      <link href="/css/admin.css" rel="stylesheet" />
    </head>
    <main>
      <body>
      @include('includes.header')
        @csrf
        <div class='secondheader'>
            <span class='article'>liste des arcticles</span> <a href='/modif_item'> <button>Ajout</button></a></span>
        </div>
        <div id='displayitem' class='items'>
            <?php foreach($items as $item): ?>
            <div class='item'>
                <form method="POST" action="/delete-item/{{$item->id}}">
                    @csrf
                    {{ method_field('DELETE') }}
                    <button class='delete'>
                        <img src="/images/icone_html/deleteincon.png" width="10" height="10">
                    </button>
                </form>
                <img src="/images/articles/{{$item->picture_name}}" width="120" height="120"
                    id="picutrename/{{$item->picture_name}}">

                <form method="POST" action="/admin/{{$item->id}}">
                    @csrf
                    <input type="text" id="name/{{$item->id}}" name="name" value="{{$item->name}}">
                    <input type="text" id="description/{{$item->id}}" name="description" value="{{$item->description}}">
                    <input type="text" id="price/{{$item->id}}" name="price" value="{{$item->price}}€">
                    <button class='save' type="submit">
                        SAUVEGARDER</button>
                </form>


            </div>
            <?php endforeach; ?>
        </div>
    </body>
</main>

</html>