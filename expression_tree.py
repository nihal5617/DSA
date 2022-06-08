class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def insert(root: Node, ele):
    if not root:
        return ele
    if root.data == ele:
        return root
    elif root.data > ele:
        root.left = insert(root.left, ele)
    else:
        root.right = insert(root.right, ele)
    return root


def inorder(root: Node):
    if root:
        inorder(root.left)
        print(root.data, end="")
        inorder(root.right)


def preorder(root: Node):
    if root:
        print(root.data, end="")
        preorder(root.left)
        preorder(root.right)


def postorder(root: Node):
    if root:
        postorder(root.left)
        postorder(root.right)
        print(root.data, end="")


if __name__ == "__main__":
    root = Node("+")
    root.left = Node("*")
    root.right = Node(7)
    root.left.left = Node("+")
    root.left.right = Node("c")
    root.left.left.left = Node("a")
    root.left.left.right = Node("b")

    inorder(root)
    print()
    preorder(root)
    print()
    postorder(root)
    print()
