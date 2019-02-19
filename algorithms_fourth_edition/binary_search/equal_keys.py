"""
Equal keys. Add to BinarySearch a static method rank() that takes a key and a
sorted array of int values(some of which may be equal) as arguments and returns
the number of elements that are smaller than the key and a similar method
count() that returns the number of elements equal to the key. Note: If i and j
are the values returned by rank(key, a) and count(key, a) respectively, then
a[i...i+j-1] are the values in the array that are equal to key.
"""


class BinarySearch(object):

    @staticmethod
    def search(a, key):
        if not a:
            return -1

        low = 0
        high = len(a) - 1
        while low <= high:
            mid = low + (high - low) // 2
            if key == a[mid]:
                return mid
            elif key < a[mid]:
                high = mid - 1
            else:
                low = mid + 1
        return -1

    @staticmethod
    def rank(a, key):
        if not a:
            return 0

        low = 0
        high = len(a) - 1
        while low <= high:
            mid = low + (high - low) // 2
            if key <= a[mid]:
                high = mid - 1
            else:
                low = mid + 1
        return high + 1

    @staticmethod
    def count(a, key):
        if not a:
            return 0

        a_length = len(a)

        # 下界
        low = 0
        high = a_length - 1
        while low <= high:
            mid = low + (high - low) // 2
            if key <= a[mid]:
                high = mid - 1
            else:
                low = mid + 1
        if low == a_length or a[low] != key:  # 不能找到 key
            return 0
        left_border = low

        # 上界
        low = 0
        high = a_length - 1
        while low <= high:
            mid = low + (high - low) // 2
            if key < a[mid]:
                high = mid - 1
            else:
                low = mid + 1

        return high - left_border + 1


if __name__ == '__main__':
    print(BinarySearch.search([1, 2, 2, 3], 2))
    print(BinarySearch.rank([1, 2, 2, 3], 2))
    print(BinarySearch.count([1, 2, 2, 3], 2))

    print(BinarySearch.search([1, 2, 2, 3], 4))
    print(BinarySearch.rank([1, 2, 2, 3], 4))
    print(BinarySearch.count([1, 2, 2, 3], 4))

    print(BinarySearch.search([2, 2, 2, 2], 2))
    print(BinarySearch.rank([2, 2, 2, 2], 2))
    print(BinarySearch.count([2, 2, 2, 2], 2))
