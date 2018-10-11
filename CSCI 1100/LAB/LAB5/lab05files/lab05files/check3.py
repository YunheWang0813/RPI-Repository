import lab05_util
import webbrowser

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
        
    print''
    print 'What would you like to do next?'
    print '1. Visit the homepage'
    print '2. Show on Google Maps'
    print '3. Show directions to this restaurant'
            
    B=int(raw_input('Your choice (1-3)? ==> '))
    if B==1:
        webbrowser.open(restaurant[4])
    elif B==2:
        webbrowser.open('http://www.google.com/maps/place/'+X[0]+','+X[1])
    elif B==3:
        webbrowser.open('http://www.google.com/maps/dir/'+'110 8th Street,Troy NY/'+X[0]+','+X[1])
                        

restaurants = lab05_util.read_yelp('yelp.txt')

A=int(raw_input('Enter a number ==> '))
if 1<=A<=155:
    print_info(restaurants[A-1])
else:
    print 'Warning!'
