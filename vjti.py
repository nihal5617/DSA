# class Node:
#     def __init__(self, data):
#         self.data = data
#         self.next = None


# class LinkedList:
#     def __init__(self):
#         self.head = None

#     def append(self, new_data):
#         new_node = Node(new_data)
#         new_node.next = self.head
#         self.head = new_node

#     def deleteNode(self, key):
#         temp = self.head
#         if temp is not None:
#             if temp.data == key:
#                 self.head = temp.next
#                 temp = None
#                 return
#         while temp is not None:
#             if temp.data == key:
#                 break
#             prev = temp
#             temp = temp.next
#         if temp == None:
#             return
#         prev.next = temp.next

#     def printList(self):
#         temp = self.head
#         while temp:
#             print(" %d" % (temp.data)),
#             temp = temp.next


# if __name__ == "__main__":
#     llist = LinkedList()
#     llist.append(21)
#     llist.append(35)
#     llist.append(47)
#     llist.append(52)
#     llist.append(89)
#     print("Created Linked List: ")
#     llist.printList()
#     llist.deleteNode(35)
#     print("\nLinked List after Deletion")
#     llist.printList()


class Remover:
    def __init__(self, data):
        self.data = data


class ListRemover(Remover):
    def __sub__(self, key):
        self.data.remove(key)


class DictRemover(Remover):
    def __sub__(self, key):
        self.data.pop(key)


if __name__ == "__main__":
    L = ListRemover([1, 2, 3, 4, 5, 6, 7])
    key_l = 4
    try:
        L - key_l
        print(L.data)
    except:
        print(f"{key_l} doesnt exist in the given list")

    D = DictRemover({1: "a", 2: "b", 3: "c"})
    key_d = 2
    try:
        D - key_d
        print(D.data)
    except:
        print(f"{key_d} doesnt exist in the given dict")


# class Employee:
#     def __init__(self, id, dept, perfindex):
#         self.id = id
#         self.department = dept
#         self.performanceindex = perfindex

#     class DateofJoining:
#         def __init__(self, dd, mm, yy):
#             self.date = f"{dd}--{mm}--{yy}"

#         def display(self):
#             print(self.date)


# class Promotion:
#     def __init__(self, Employee):
#         self.Employee = Employee

#     def increaseperf(self):
#         self.Employee.performanceindex += 20
#         print("Performance index = " + str(self.Employee.performanceindex))


# if __name__ == "__main__":
#     Jatin = Employee(1, "IT", 40)
#     Promotion(Jatin).increaseperf()
#     date = Jatin.DateofJoining(11, 4, 21)
#     date.display()


# class Fruit:
#     def __init__(self, name, color, price):
#         self.name = name
#         self.color = color
#         self.price = price

#     def __str__(self):
#         return f"Name = {self.name}, color = {self.color}, price = {self.price} "


# class FruitBasket:
#     def __init__(self):
#         self.fruitlist = []

#     def putFruit(self, fruit):
#         self.fruitlist.append(fruit)


# if __name__ == "__main__":
#     fb = FruitBasket()
#     fb.putFruit(Fruit("Apple", "Red", 10))
#     fb.putFruit(Fruit("Orange", "Orange", 20))
#     fb.putFruit(Fruit("Banana", "Yellow", 30))
#     for i in fb.fruitlist:
#         print(i.name)

# x = 5


# def before_after(func):
#     def inner():
#         print(x)
#         func()
#         print(x)

#     return inner


# @before_after
# def modify():
#     global x
#     x = 10


# modify()


# def unique(*args):
#     for i in args:
#         print(set(i))


# unique("Lannce", "ronnit")
