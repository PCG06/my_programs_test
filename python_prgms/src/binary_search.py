# Python script to perform binary search

def binary_search(arr, target):
    left = 0
    right = len(arr) - 1

    while left <= right:
        mid = (left + right) // 2

        if arr[mid] == target:
            return mid + 1 # 1-based index
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1

def main():
    arr = sorted([int(i) for i in input("Enter numbers: ").split()]) # Sorts the input array
    target = int(input("Enter number to search: "))

    # Print array elements
    print("The sorted array elements are:")
    print(*arr) # No need to loop while printing array elements. Use * to avoid [sqaure brackets around numbers]

    result = binary_search(arr, target)

    if result != -1:
        print(f"Found at position {result}")
    else:
        print("Not found")

if __name__ == "__main__":
    main()
