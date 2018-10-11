class Account(object):
    def __init__(self, number, balance):
        self.number = number
        self.balance = balance
        self.overdrawn = self.is_overdrawn()
        
    def is_overdrawn(self):
        if self.balance > 0:
            return False
        else:
            return True
        
    def __str__(self):
        if self.overdrawn:
            return '%d: $%.2f(*)'%(self.number,self.balance)
        else:
            return '%d: $%.2f'%(self.number,self.balance)
        
    def withdraw(self,amount):
        self.balance-=amount
        self.overdrawn = self.is_overdrawn()
        
    def deposit(self,amount):
        self.balance+=amount
        self.overdrawn = self.is_overdrawn()
        
    def transfer(self,other,amount):
        self.balance+=amount
        other.balance-=amount
        other.overdrawn = other.is_overdrawn()
        self.overdrawn = self.is_overdrawn()
        
x = Account(1234, 34)
x.withdraw(10)
print x
y = Account(5678, 50)
y.deposit(20)
print y
x.transfer(y, 80)
print x
print y