base10=128
A=base10*10**9
base2=A/2**30
difference=base10-base2
print base2, difference
print base10 , "In base10 is actually", base2 , "in base2", difference, "less than advertised."