def get_stack_pop_order(a):
    _get_stack_pop_order([], a, [])


def _get_stack_pop_order(stk, q, res):
    if not stk and not q and res:
        print(res)

    if q:
        stk.append(q.pop(0))
        _get_stack_pop_order(stk, q, res)
        q.insert(0, stk.pop())

    if stk:
        res.append(stk.pop())
        _get_stack_pop_order(stk, q, res)
        stk.append(res.pop())


if __name__ == '__main__':
    get_stack_pop_order([1, 2, 3])
