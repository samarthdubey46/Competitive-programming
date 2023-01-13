def fibonacci(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fibonacci(n-1) + fibonacci(n-2)

class linkedList:
    def __init__(self, value):
        self.value = value
        self.next = None
    def reverse(self):
        if self.next == None:
            return self
        else:
            head = self.next.reverse()
            self.next.next = self
            self.next = None
            return head

def addhello(s):
    print(s + "hello")