"""
最大子数组和
"""


def max_sum_of_subarray(arr):
    if not arr:
        return None

    max_sum = arr[0]
    temp = arr[0]
    for elem in arr[1:]:
        if temp < 0:
            temp = elem
        else:
            temp += elem
        if max_sum < temp:
            max_sum = temp
    return max_sum


if __name__ == '__main__':
    arr = [1, 2, 3, -4, -7, 20]
    print(max_sum_of_subarray(arr))
