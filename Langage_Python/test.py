class test:
    def printmy(self,a,b,c):
        print(a,b,c)
        return


class testB(test):
    def printmy(self, b, c):
        print(b,c)
        return
mytest =  test()
montest =  testB()
mytest.printmy(1,2,3)
montest.printmy(2,3)
