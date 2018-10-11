amt=float(raw_input('Please enter an amount between 0 and 1 ==> '))
amt=100*amt
c25=amt/25
c10=amt%25/10
c5=amt%25%10/5
c1=amt%25%10%5
print "You need ==> 25 cent: %d\t 10 cent: %d\t 5 cent: %d\t1 cent: %d" %(c25,c10,c5,c1)
