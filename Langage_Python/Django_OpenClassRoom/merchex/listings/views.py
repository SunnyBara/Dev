from django.shortcuts import render, redirect
from django.http import HttpResponse,HttpResponseNotFound
from listings.models import Band
from listings.models import Listing
from listings.form import ContactUsForm , BandForm , ListForm
from django.core.mail import send_mail

def band_list(request):
    list  = Band.objects.all()
    return render(request,'listings/band_list.html',{"list" : list})

def band_detail(request,id):
    try :
     band  = Band.objects.get(id = id)
     list = Listing.objects.all().filter(band = id)
    except :
     return HttpResponseNotFound("<h1>Band not found </h1>")
    return render(request,'listings/band_detail.html',{"band": band, "list":list})

def band_create(request):
   match(request.method):
      case "POST" :
         band = BandForm(request.POST)
         if band.is_valid():
            newband = band.save()
            return redirect('band-detail',newband.id)
      case "GET" :
         band = BandForm()
   
   return render(request, 'listings/band_create.html', {"form" : band})

def band_update(request,id):
   band = Band.objects.get(id = id)
   match(request.method):
      case "POST" :
         form = BandForm(request.POST, instance=band)
         if form.is_valid():
            form.save()
            return redirect('band-detail',band.id)
      case "GET" :
         form = BandForm(instance=band)
   
   return render(request, 'listings/band_update.html', {"form" : form})


def band_delete(request,id):
   band = Band.objects.get(id = id)
   match(request.method):
      case "POST" :
            band.delete()
            return redirect('band-list')
   return render(request, 'listings/band_delete.html', {"band" :  band})




def about (request):
    return render(request,'listings/about.html' )

def contact_us(request):
    print('la Methode de requete est ' , request.method)
    match (request.method):
       case "POST" :
        print('la Methode post contient : ', request.POST)
        form = ContactUsForm(request.POST)
        if form.is_valid():
           send_mail(subject = f'Message from {form.cleaned_data["name"] or "anonyme"} via Merchex Contact Us Form',
                     message = form.cleaned_data["message"],
                     from_email = form.cleaned_data["email"],
                     recipient_list =  ["admin@merchex.xyz"])
           return redirect('email-sent')
       case "GET" :
        form = ContactUsForm()
    return render(request,'listings/contact_us.html', {"form":form})
       
def email_sent(request):
   return render(request, 'forms/emailsent.html')




def listing (request):
    liste  = Listing.objects.all()
    return render(request, 'listings/listing.html' , {"list" : liste})
def list_detail(request,id):
    try :
        liste  = Listing.objects.get(id = id)
    except :
        return HttpResponseNotFound('<h1> List not found </h1>')
    return render(request, 'listings/list_detail.html' , {"list" : liste})

def list_create(request):
   match(request.method):
      case "POST" :
         list = ListForm(request.POST)
         if list.is_valid():
            list.save()
            return redirect('listing')
      case "GET" :
         list = ListForm()
   return render(request, 'listings/list_create.html', {"form" : list})


def list_update(request,id):
   list = Listing.objects.get(id=id)
   match(request.method):
      case "POST" :
         form = ListForm(request.POST, instance= list)
         if form.is_valid():
            form.save()
            return redirect('list-detail' , list.id)
      case "GET" :
         form = ListForm(instance=list)
   return render(request, 'listings/list_update.html', {"form" : form})

def list_delete(request,id):
   list = Listing.objects.get(id = id)
   match(request.method):
      case "POST" :
            list.delete()
            return redirect('listing')
   return render(request, 'listings/list_delete.html', {"list" :  list})


