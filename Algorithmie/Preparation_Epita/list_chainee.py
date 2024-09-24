class Node:
    def __init__(self, data):
        self.item = data
        self.ref = None

class LinkedList: 
    def __init__(self):
        self.start_node = None  
    def traverse_list(self):
        if self.start_node is None:
            print("Pas d'élément dans la liste")
            return
        else:
            n = self.start_node
            while n is not None:
                print(n.item , " ")
                n = n.ref
    def add_node(self, node :Node):
        tmp :Node = self.start_node
        while tmp.ref is not None:
            tmp = tmp.ref
        tmp.ref =  node


list1 = LinkedList()
list1.traverse_list()
node1 = Node("1")
node2 = Node("2")
node3 = Node("3")
list1.start_node = node1
list1.add_node(node2)
list1.add_node(node3)
list1.traverse_list()
