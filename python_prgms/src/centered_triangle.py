# Python script to create a centered triangle
# Credits to Kira-Learning on YouTube :)

def tree(height):
    length = height * 2 - 1
    stars = 1
    for i in range(1, height + 1):
        print(("*" * stars).center(length))
        stars += 2

def main():
    height = int(input("Enter number of lines: "))
    tree(height)

if __name__ ==  "__main__":
    main()
