class Item:
    def __init__(self,data) -> None:

        self.next = None
        self.data =  data

class file :
    def __init__(self,item:Item) -> None:
        self.first_item = item
        self.last_item = item
    def add_file(self,item : Item)->None:
        self.last_item.next = item
        self.last_item = self.last_item.next
    def remove_item(self):
        self.first_item =  self.first_item.next
    def show_items(self):
        tmp = self.first_item
        while tmp is not None:
            print(tmp.data)
            tmp = tmp.next


my_file =  file(Item("test"))
my_file.add_file(Item("test2"))
my_file.add_file(Item("test3"))
my_file.add_file(Item("test4"))
my_file.remove_item()
my_file.remove_item()
my_file.show_items()