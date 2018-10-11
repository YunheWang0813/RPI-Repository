import lab05_util

def print_info(restaurant):
    print restaurant[0]+' ('+restaurant[5]+')'
    X=restaurant[3]
    X=X.split('+')
    print ' '*8+X[0]
    print ' '*8+X[1]
    Y=restaurant[6]
    print "Average Score: %.2f " %(sum(Y) / float(len(Y)))

restaurants = lab05_util.read_yelp('yelp.txt')
print_info(restaurants[0])
print
print_info(restaurants[1])