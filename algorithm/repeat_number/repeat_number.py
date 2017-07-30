# -*- coding: utf-8 -*-
"""
“不重复数”的含义是相邻两位不相同，例如1101是重复数，而1201是不重复数

1. 给定任意一个正整数，求比这个数大且最小的“不重复数”

2. 给定任意一个正整数，求比这个数小且最大的“不重复数”
"""

from __future__ import unicode_literals
from __future__ import print_function


def get_minimum_number(number):
    number += 1
    temp = number
    number_list = []

    # 将 number 放入 list 中
    # eg: 12344 -> [1, 2, 3, 4, 4]
    while temp:
        remainder = temp % 10
        number_list.insert(0, remainder)
        temp //= 10

    # 记录从哪个位置开始调整，从这个位置开始将数组调整为 [0, 1, 0, 1, ...]
    adjust_index = -1
    for i in range(1, len(number_list)):
        if number_list[i] == number_list[i - 1]:
            flag = False
            # [1, 9, 9, 0] -> [2, 0, 1, 0]
            # [9, 9, 0] -> [1, 0, 1, 0]
            if number_list[i] == 9:
                number_list[i] = 1
                number_list[i - 1] = 0
                if i - 2 >= 0:
                    number_list[i - 2] += 1
                else:
                    number_list.insert(0, 1)
                    flag = True
            else:
                number_list[i] += 1
            if flag:
                adjust_index = i + 2
            else:
                adjust_index = i + 1
            break
    else:
        return number

    # 调整数组
    flag = True
    for i in range(adjust_index, len(number_list)):
        if flag:
            number_list[i] = 0
            flag = False
        else:
            number_list[i] = 1
            flag = True

    number = 0
    for num in number_list:
        number = number * 10 + num

    return number


def get_maximum_number(number):
    number -= 1
    temp = number
    number_list = []

    # 将 number 放入 list 中
    # eg: 12344 -> [1, 2, 3, 4, 4]
    while temp:
        remainder = temp % 10
        number_list.insert(0, remainder)
        temp //= 10

    # 记录从哪个位置开始调整，从这个位置开始将数组调整为 [9, 8, 9, 8, ...]
    adjust_index = -1
    for i in range(1, len(number_list)):
        if number_list[i] == number_list[i - 1]:
            flag = False
            # [2, 0, 0, 0] -> [1, 9, 8, 0]
            # [1, 0, 0, 0] -> [9, 8, 0]
            if number_list[i] == 0:
                number_list[i] = 8
                number_list[i - 1] = 9
                if i - 2 >= 0:
                    number_list[i - 2] -= 1

                if number_list[0] == 0:
                    number_list.pop(0)
                    flag = True
            else:
                number_list[i] -= 1

            if flag:
                adjust_index = i
            else:
                adjust_index = i + 1
            break
    else:
        return number

    # 调整数组
    flag = True
    for i in range(adjust_index, len(number_list)):
        if flag:
            number_list[i] = 9
            flag = False
        else:
            number_list[i] = 8
            flag = True

    number = 0
    for num in number_list:
        number = number * 10 + num

    return number


def main():
    number_list = [8, 9, 990, 19900, 13400]
    for number in number_list:
        print(get_minimum_number(number))
    print('*' * 30)

    number_list = [1, 10000, 20000, 17600, 17700]
    for number in number_list:
        print(get_maximum_number(number))


if __name__ == '__main__':
    main()
