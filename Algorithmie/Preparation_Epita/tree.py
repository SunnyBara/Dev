class btree:
    def __init__(self,elt:int) -> None:
        self.elt = elt
        self.right = None
        self.left = None
        self.heigth = 0

    def add_node(self,elt:int):
        tmp =  self
        height = 1
        while self.check_right(tmp,elt) or self.check_left(tmp,elt):
            if elt > tmp.elt:
                tmp = tmp.right
            else :
                tmp =  tmp.left
            height += 1
        if tmp.elt < elt:
            tmp.right = btree(elt)
        else :
            tmp.left = btree(elt)
        if(height > self.heigth):
            self.heigth = height
            
    def check_right(self,tmp, elt:int):
         if elt > tmp.elt and tmp.right is not None :
             return True
         return False
    
    def check_left(self,tmp,elt:int):
        if tmp.elt >= elt and tmp.left is not None :
            return True
        return False
    
    def print_node_prefixe(self):
        self.parcour_profondeur_prefixe(self)

    def print_node_infixe(self):
        self.parcour_profondeur_infixe(self)

    def print_node_posfixe(self):
        self.parcour_profondeur_postfixe(self)

    def parcour_profondeur_prefixe(self,node):
        if node is None:
            return
        self.parcour_profondeur_prefixe(node.left)
        self.parcour_profondeur_prefixe(node.right)

    def parcour_profondeur_infixe(self,node):
        if node is None:
            return
        self.parcour_profondeur_infixe(node.left)
        print(node.elt)
        self.parcour_profondeur_infixe(node.right)

    def parcour_profondeur_postfixe(self,node):
        if node is None:
            return
        self.parcour_profondeur_postfixe(node.left)
        self.parcour_profondeur_postfixe(node.right)
        print(node.elt)

    def get_size(self):
        return self.heigth
    
    def is_node(self,elt:int):
        if(self.search_node(elt) is not None):
                return True
        return False
    
    # def search_node(self, elt:int) -> ['btree'] | None:
    #     tmp = self
    #     while self.check_right(tmp,elt) or self.check_left(tmp,elt) or tmp.elt == elt:
    #         print(tmp.elt)
    #         if elt > tmp.elt:
    #             tmp = tmp.right
    #         elif elt == tmp.elt:
    #             return tmp
    #         else :
    #             tmp =  tmp.left
    #     return None
    def ABRrgd(self, Btree):
        if (Btree is None):
            print("_",end='')
            return
        print('<',Btree.elt,',',end='')
        self.ABRrgd(Btree.left)
        print(',',Btree.elt,'>',end='')
        self.ABRrgd(Btree.right)
        





root =  btree(7)
root.add_node(10)
root.add_node(3)
root.add_node(1)
root.add_node(6)
root.add_node(4)
root.add_node(7)
root.add_node(14)
root.add_node(13)
root.add_node(12)
root.add_node(15)
root.add_node(2)

root.ABRrgd(root)