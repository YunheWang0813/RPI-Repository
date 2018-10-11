import lab05_util

def print_info(restaurant):
    print restaurant[0]+' ('+restaurant[5]+')'
    X=restaurant[3]
    X=X.split('+')
    print ' '*8+X[0]
    print ' '*8+X[1]
    Y=restaurant[6]
    if len(Y)>2:
        Z=(sum(Y)-max(Y)-min(Y))/float(len(Y)-2)
    else:
        Z=(sum(Y))/float(len(Y))
    if 0<Z<=2:
        print 'This restaurant is rated bad, based on',len(Y),'reviews.'
    elif 2<Z<=3:
        print 'This restaurant is rated average, based on',len(Y),'reviews.'
    elif 3<Z<=4:
        print 'This restaurant is rated above average, based on',len(Y),'reviews.'
    elif 4<Z<=5:
        print 'This restaurant is rated very good, based on',len(Y),'reviews.'

restaurants = lab05_util.read_yelp('yelp.txt')

A=int(raw_input('Enter a number ==> '))
if 1<=A<=155:
    print_info(restaurants[A-1])
else:
    print 'Warning!'