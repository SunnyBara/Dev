from django import forms
from django.contrib.auth.forms import UserCreationForm
from django.contrib.auth import get_user_model
from authentication.models import User
from . import validators

class LoginForms(forms.Form):
    username = forms.CharField(max_length=63, label='Nom d\'utilisateur')
    password = forms.CharField(max_length=63, widget=forms.PasswordInput, label="Mot de passe")

class SingupForm(UserCreationForm):
    class Meta(UserCreationForm.Meta):
        model = get_user_model()
        fields = ('username','email','first_name','last_name','role')

# class PostCodeForm(forms.Form):
#     post_code = forms.CharField(max_length=10, validators=[validators.PostCodeValidator])