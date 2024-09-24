from django.shortcuts import render, redirect
from . import form
from django.contrib.auth import authenticate, login as auth_login , logout
from django.views.generic import View
from django.conf import settings
# Create your views here.

# def login(request):
#     forms = form.LoginForms()
#     messages = ''
#     if request.method == "POST":
#         forms = form.LoginForms(request.POST)
#         if forms.is_valid():
#             user = authenticate(
#                 username=forms.cleaned_data["username"],
#                 password=forms.cleaned_data["password"])
#             if user is not None :
#                 auth_login(request,user)
#                 return redirect('home')
#     messages='Probleme d\'authentification'
#     return render(request,'authentication/login.html', context={'form' : forms , 'message':messages})

# class LoginpageView(View):
#     template_name = 'authentication/login.html'
#     form_class = form.LoginForms
#     def get(self,request):
#         forms = self.form_class()
#         message = ''
#         return render(request,self.template_name,context={'form' : forms , 'message' : message})
    
#     def post(self, request):
#         forms = self.form_class(request.POST)
#         if forms.is_valid():
#             user = authenticate(
#                 username=forms.cleaned_data['username'],
#                 password=forms.cleaned_data['password']
#             )
#             if user is not None:
#                 auth_login(request,user)
#                 return redirect('home')
#         message = "Identifiants Invalide"
#         return render(request,self.template_name,context={'form' : forms, 'message' : message})
def logout_user(request):
    logout(request)
    return redirect('login')

def signup_page(request):
    forms = form.SingupForm()
    if request.method == 'POST':
        forms = form.SingupForm(request.POST)
        if forms.is_valid():
            user = forms.save()
            auth_login(request,user)
            return(redirect(settings.LOGIN_REDIRECT_URL))
    return (render(request,'authentication/signup.html', context={'form' : forms}))

