class Item :
    def __init__(self,data):
        self.value = data
        self.next =  None
        self.prev =  None
    
class Pile :
    first_item : Item
    last_item :Item
    def __init__(self) -> None:
        self.first_item = None
        self.last_item = None
        self.size = 0

    def set_first_item(self,item):
        self.first_item = item
    def set_last_item(self,item):
        self.last_item = item

    def add_pile(self, truc: Item):
        if self.first_item == None:
            self.set_first_item(truc)
        if self.last_item == None:
            self.set_last_item(truc)
        else :
            truc.prev =  self.last_item
            self.last_item.next = truc
            self.last_item =  self.last_item.next
        self.size += 1

    def show_items(self):
        if self.get_size_of_pile():
            tmp : Item =  self.first_item
            while tmp is not None:
                print(tmp.value)
                tmp = tmp.next
        else :
            print("nothing to show")

    def remove_pile(self):
        if self.last_item != None:
            self.last_item = self.last_item.prev
            self.last_item.next = None
            self.size -=1
        else :
            print("nothin to remove")
    def get_size_of_pile(self):
        return self.size
    
    def destroy_pile(self):
        self.set_first_item(None)
        self.set_last_item(None)
        self.size = 0



pile = Pile()
pile.add_pile(Item("test"))
pile.add_pile(Item("test2"))
pile.add_pile(Item("test3"))
pile.remove_pile()
pile.show_items()
pile.destroy_pile()
pile.show_items()

