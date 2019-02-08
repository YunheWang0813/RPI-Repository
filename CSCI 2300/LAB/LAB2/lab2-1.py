def binary(num1, num2):
    total=0
    while num1!=0:
        test=num1&1
        if test!=0:
            total+=num2
        num1=num1/2
        num2=num2<<1
    return total
        
        


if __name__ == '__main__':
    num1=int(raw_input('Enter number1 ==> '))
    num2=int(raw_input('Enter number2 ==> '))
    ans=binary(num1, num2)
    print ans