def find_times_number_occurred(a, number):
    lower_bound = find_lower_bound(a, number)
    if lower_bound == -1:
        return 0

    upper_bound = find_upper_bound(a, number)

    return upper_bound - lower_bound + 1


def find_lower_bound(a, number):
    if not a:
        return -1

    low = 0
    high = len(a) - 1
    while low <= high:
        mid = (low + high) // 2
        if number <= a[mid]:
            high = mid - 1
        else:
            low = mid + 1

    if a[low] == number:
        return low

    return -1


def find_upper_bound(a, number):
    if not a:
        return -1

    low = 0
    high = len(a) - 1
    while low <= high:
        mid = (low + high) // 2
        if number >= a[mid]:
            low = mid + 1
        else:
            high = mid - 1

    if a[high] == number:
        return high

    return -1


if __name__ == '__main__':
    a = [1, 2, 2, 2, 3, 3, 3, 3, 4]
    print(find_lower_bound(a, 4))
    print(find_upper_bound(a, 4))
    print(find_times_number_occurred(a, 3))
