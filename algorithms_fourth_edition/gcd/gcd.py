def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a


if __name__ == '__main__':
    print(gcd(0, 10))
    print(gcd(10, 0))
    print(gcd(100, 36))
    print(gcd(36, 100))
