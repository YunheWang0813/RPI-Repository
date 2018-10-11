def find_dup(L):
    s=set()
    for num in L:
        s.add(num)
    print len(s)

find_dup([2, 1, 2, 1, 1, 2, 2])