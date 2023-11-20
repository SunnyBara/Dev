 function request() {
    const xhttp = new XMLHttpRequest();

    xhttp.onload = function() {
      const separators = ['時','分']
      let full_hours = this.responseText + '秒';

      for (const separator of separators) {
         full_hours = full_hours.replace(':', `${separator}`);
      }
      document.getElementById('heure').innerHTML = `Heure actuelle : ${full_hours}`;
      console.log(this);
      }
    xhttp.open("GET", "/gethours",true);
    xhttp.send();
    setTimeout(request, 500);
 }
   


request();
