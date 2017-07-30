from __future__ import print_function
import math
from pprint import pprint


def coins_change(total_money, coins):
    numbers = [0]
    for i in range(1, total_money + 1):
        min_number = 0
        for coin in coins:
            if coin <= i:
                temp = numbers[i - coin]
                if coin == i:
                    temp += 1
                elif temp != 0:
                    temp += 1
                if temp < min_number or min_number == 0:
                    min_number = temp
        numbers.append(min_number)
    print(numbers)
    return numbers[-1]


def coins_change_1(total_money, coins):
    solutions = [[0 for _ in coins + [0]]]
    for i in range(1, total_money + 1):
        min_number = 0
        coin_index = -1
        old_index = -1
        for j, coin in enumerate(coins):
            if coin <= i:
                temp = solutions[i - coin][-1]
                if coin == i:
                    temp += 1
                elif temp != 0:
                    temp += 1
                if temp < min_number or min_number == 0:
                    min_number = temp
                    old_index = i - coin
                    coin_index = j
        solution = [0 for _ in coins + [0]]
        if min_number:
            solution = solutions[old_index][:]
            solution[coin_index] += 1
            solution[-1] += 1
        solutions.append(solution)
    pprint(solutions)
    return solutions[-1]


def all_solutions(total_money, coins):
    solution = [int(math.ceil(float(total_money) / coin)) for coin in coins]
    max_number = solution[:]
    i = len(solution) - 1
    while True:
        sum_ = sum_of_coins(solution, coins)
        if sum_  == total_money:
            yield solution
            solution[i] = -1
        elif sum_ > total_money:
            solution[i] -= 1
        else:
            solution[i] = -1

        for j in reversed(range(1, i + 1)):
            if solution[j] == -1:
                solution[j] = max_number[j]
                solution[j - 1] -= 1

        if solution[0] == -1:
            break


def sum_of_coins(solution, coins):
    sum_ = 0
    for i in range(len(solution)):
        sum_ += solution[i] * coins[i]
    return sum_


def main():
    total_money = 100
    coins = [5, 20, 50]
    # print(coins_change(total_money, coins))
    # print(coins_change_1(total_money, coins))

    for solution in all_solutions(total_money, coins):
        print(solution)


if __name__ == '__main__':
    main()
