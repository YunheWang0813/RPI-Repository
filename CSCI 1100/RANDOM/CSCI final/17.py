def notused(L):
    all_letters = set("abcdefghijklmnopqrstuvwxyz")
    used=set()
    for item in L:
        x=set(item.lower())
        used=used|x
    return all_letters-used

