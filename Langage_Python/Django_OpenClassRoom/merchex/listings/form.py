from django import forms
from listings.models import Band, Listing

class ContactUsForm(forms.Form) :
    name = forms.CharField(required=False)
    email = forms.EmailField()
    message = forms.CharField(max_length=500)

class BandForm(forms.ModelForm):
    class Meta:
        model = Band
        #fields = '__all__'
        exclude = ('active','official_homepage')

class ListForm(forms.ModelForm):
    class Meta:
        model = Listing
        exclude = ('band','sold')