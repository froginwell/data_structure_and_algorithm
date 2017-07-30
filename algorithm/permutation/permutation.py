# -*- coding: utf-8 -*-

from __future__ import unicode_literals

"""
全排列
"""


def permutation_by_recursion_1(a):
    """
    没有去重的全排列
    """

    if a:
        if len(a) == 1:
            yield a[0]
        else:
            for i in permutation_by_recursion_1(a[1:]):
                for j in range(len(i) + 1):
                    k = ''.join([i[0:j], a[0], i[j:]])
                    yield k


def permutation_by_recursion_3(a):
    """
    没有去重的全排列
    """

    if a:
        if len(a) == 1:
            yield a[0]
        else:
            for i in range(len(a)):
                b = a[0:i] + a[i+1:]
                for e in permutation_by_recursion_3(b):
                    k = a[i] + e
                    yield k


def permutation_by_recursion_4(a):
    """
    去过重的全排列
    """

    if a:
        if len(a) == 1:
            yield a[0]
        else:
            for i in range(len(a)):
                if a[i] not in a[:i]:
                    b = a[0:i] + a[i+1:]
                    for e in permutation_by_recursion_4(b):
                        k = a[i] + e
                        yield k


if __name__ == '__main__':
    a = 'AABB'
    print(list(permutation_by_recursion_1(a)))
    print(list(permutation_by_recursion_3(a)))
    print(list(permutation_by_recursion_4(a)))
