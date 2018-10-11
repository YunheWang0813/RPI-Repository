x=raw_input('Please enter your first name:')
y=raw_input('Please enter your last name:')
f=len("Hello,")
g=len(x)
h=len(y)+1
i=max(f,g,h)
j='*'*i+'*'*6+'\n'
k='*'*i+'*'*6
l=i-f
m=i-g
s=i-h
a='** Hello,' + " "*l + ' **\n'
b='** ' + x + " "*m + ' **\n'
c='** ' + y + '!' + " "*s + ' **\n'
print j,a,b,c,k