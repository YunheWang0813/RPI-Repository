def binary(num1, num2):
    if num2==0:
        return 0     
    z=binary(num1, num2/2)   
    if num2&1==0:
        return 2*z
    else:
        return num1+2*z


if __name__ == '__main__':
    num1=int(raw_input('Enter number1 ==> '))
    num2=int(raw_input('Enter number2 ==> '))
    ans=binary(num1, num2)
    print ans