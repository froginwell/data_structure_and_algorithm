# -*- coding: utf-8 -*-

from __future__ import unicode_literals

"""
数轴上有 n 个点，从左到右依次为 a[0], a[1] ..., a[n-1]，给定一根长度为 L 的
绳子，求绳子最多能覆盖其中几个点
"""


def max_cover(a, rope_length):
    if not a:
        return 0

    length = len(a)
    max_num = 1
    i = 0
    j = 1
    while j < length:
        while j < length and a[j] - a[i] < rope_length:
            max_num += 1
            j += 1
        i += 1
        j += 1

    return max_num


if __name__ == '__main__':
    a= [-1, 0, 3, 7, 8, 20, 21, 22, 23, 24, 25, 26]
    rope_length = 5
    print(max_cover(a, rope_length))
