def fibonacci_search(a, target):
    if not a:
        return -1

    len_a = len(a)
    f = [1, 1]
    k = 0
    while True:
        if k == len(f):
            f.append(f[-1] + f[-2])
        if len_a > f[k] - 1:
            k += 1
        else:
            break
    print(f, k)

    length = len_a
    while length < f[k] - 1:
        a.append(a[-1])
        length += 1

    low = 0
    high = length - 1
    while low <= high:
        mid = low + f[k-1] - 1
        print('**', low, mid, high, k)
        if target == a[mid]:
            if mid < len_a:
                return mid
            else:
                return len_a - 1
        elif target > a[mid]:
            low = mid + 1
            k -= 2
        else:
            high = mid - 1
            k -= 1
    print('k', k)
    return -1


if __name__ == '__main__':
    print(fibonacci_search([1], 1))
    print(fibonacci_search([1, 4, 8, 9, 11, 20, 38, 100], 1))
    print(fibonacci_search([1, 4, 8, 9, 11, 20, 38, 100], 12))
    print(fibonacci_search(list(range(10000)), 10000))
