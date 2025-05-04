# Python script to perform bubble sort

def bubbleSort(arr):
    for i in range(0, len(arr) - 1):
        for j in range(0, len(arr) - 1 - i):
            if arr[j] > arr[j + 1]:
                temp = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = temp

def main():
    arr = list(map(int, input("Enter numbers: ").split()))
    
    print("The array elements are:")
    print(*arr)

    bubbleSort(arr)
    
    print("The sorted array elements are:")
    print(*arr)

if __name__ == "__main__":
    main()