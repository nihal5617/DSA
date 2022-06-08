# class Node:
#     def __init__(self, coeff=None, pow=None):
#         self.coeff = coeff
#         self.pow = pow
#         self.next = None


# class LinkedList:
#     def __init__(self):
#         self.head = None

#     def append(self, coeff, pow):
#         if self.head is None:
#             self.head = Node(coeff, pow)
#         else:
#             ptr = self.head
#             while ptr.next:
#                 ptr = ptr.next
#             ptr.next = Node(coeff, pow)

#     def traverse(self):
#         temp = self.head
#         while temp:
#             print(f"{temp.coeff}x^{temp.pow}", end="")
#             if temp.next:
#                 if temp.next.coeff >= 0:
#                     print("+", end="")
#             temp = temp.next
#         print()

#     def add(self, coeff, pow):
#         if self.head is None:
#             self.append(coeff, pow)
#         else:
#             ptr = self.head
#             while ptr:
#                 if ptr.pow == pow:
#                     ptr.coeff += coeff
#                     return
#                 ptr = ptr.next
#             self.append(coeff, pow)


# def create_poly():
#     print("Enter number of terms of in polynomial.")
#     n = int(input())
#     poly = LinkedList()
#     for i in range(n):
#         coeff, pow = list(map(int, input().split()))
#         poly.append(coeff, pow)
#     return poly


# def add_poly(poly1, poly2):
#     poly = LinkedList()
#     temp1 = poly1.head
#     temp2 = poly2.head

#     while temp1 and temp2:
#         if temp1.pow > temp2.pow:
#             poly.append(temp1.coeff, temp1.pow)
#             temp1 = temp1.next
#         elif temp1.pow < temp2.pow:
#             poly.append(temp2.coeff, temp2.pow)
#             temp2 = temp2.next
#         else:
#             poly.append(temp1.coeff + temp2.coeff, temp1.pow)
#             temp1, temp2 = temp1.next, temp2.next

#     return poly


# def sub_poly(poly1, poly2):
#     poly = LinkedList()
#     temp1 = poly1.head
#     temp2 = poly2.head

#     while temp1 and temp2:
#         if temp1.pow > temp2.pow:
#             poly.append(temp1.coeff, temp1.pow)
#             temp1 = temp1.next
#         elif temp1.pow < temp2.pow:
#             poly.append(-temp2.coeff, temp2.pow)
#             temp2 = temp2.next
#         else:
#             poly.append(temp1.coeff - temp2.coeff, temp1.pow)
#             temp1, temp2 = temp1.next, temp2.next
#     return poly


# def mul_poly(poly1, poly2):
#     poly = LinkedList()
#     temp1 = poly1.head
#     while temp1:
#         temp2 = poly2.head
#         while temp2:
#             poly.add(temp1.coeff * temp2.coeff, temp1.pow + temp2.pow)
#             temp2 = temp2.next
#         temp1 = temp1.next

#     return poly


# if __name__ == "__main__":
#     print("First polynomial")
#     poly1 = create_poly()
#     print("Second polynomial")
#     poly2 = create_poly()

#     poly1.traverse()
#     poly2.traverse()

#     poly = add_poly(poly1, poly2)
#     print("Addition")
#     poly.traverse()

#     poly = sub_poly(poly1, poly2)
#     print("Subtraction")
#     poly.traverse()

#     poly = mul_poly(poly1, poly2)
#     print("Multiplication")
#     poly.traverse()

# [100, 2, 3, 50]
# arr = [1, 2, 20, 8, 8, 1, 2, 5, 8, 0]
# X = 8
# queries = [100, 4, 2, 1, 3]
# d = [4, 5, 9]


# def solve(X, arr, queries):
#     d = []
#     z = []
#     for i in range(len(arr)):
#         if arr[i] == X:
#             d.append(i + 1)
#     # print(d)
#     for i in queries:
#         try:
#             z.append(d[i - 1])
#         except:
#             z.append(-1)
#     return z


# print(*solve(8, [1, 2, 20, 8, 8, 1, 2, 5, 8, 0], [100, 1, 2, 3, 4]))


def getMaxUnits(boxes, unitsPerBox, truckSize):
    arr = []
    for i in range(len(boxes)):
        arr.append((unitsPerBox[i], boxes[i]))
    arr.sort(reverse=True)
    ans = 0
    cnt = 0
    print(arr)
    for i in range(len(boxes)):
        while arr[i][1] != 0:
            if cnt == truckSize:
                print(ans)
            ans += arr[i][0]
            arr[i][1] -= 1
            cnt += 1
    print(ans)


getMaxUnits([1, 1], [9, 6], 1)
