<!DOCTYPE html>
  <html lang="{{ str_replace('_', '-', app()->getLocale()) }}">
    <head>
      <meta charset="utf-8">
      <meta name="viewport" content="width=device-width, initial-scale=1">
      <title>Admin</title>
      <script type="text/javascript" src="/js/admin.js"></script>
      <link href="/css/form.css" rel="stylesheet" />
    </head>
    <main>
    @include('includes.header')
      <body>
        <form method="post">
        @csrf
          <div>
            <span class ='image'>
            <label for="picture">Choose a Picture:</label>
          <input type="file" id="picture" name="picture" accept="image/*" required>
          </div>
            <div>
            <label>Description</label> <br>
            <input type="text" id="description" name="description"/>
          </div>
          <div>
            <label for ='name'>Nom de l'article</input>
              <input type="text" id="name" name="name" required/>  
          <div><br>
          <label for="price">Price</label>
          <input type="text" pattern="\d*\.\d{2}" id="price" name="price" onblur="validatePriceInput()" />
          </div>
          <div>
          <div>
          <label for="articleType"> select articleType </label>
          <select id="articleType" name="articleType" required>
            <option value="" disabled selected>Select an option</option>
            <option value="1">Tea</option>
            <option value="2">Juice Flavor</option>
            <option value="3">Topping</option>
        </select>
          </div>
          <button type = "submit">Sauvegarder</button>
            </div>
</form>
</body>
</html>
