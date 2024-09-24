from django.test import TestCase
from listings.models import Listing
from listings.form import ListForm
class Listingtest (TestCase):
    def test_string_representation(self):
        listing = Listing()
        listing.title = "My entry title"
        listing.description = "My entry description"
        listing.type = "REC"
        list = ListForm(listing)
        list.save()
        list = Listing.objects.get(id = 1)
        self.assertEqual(listing.title, list.title)
