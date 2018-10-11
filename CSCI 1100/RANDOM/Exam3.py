'''No.1 *
   set('dog') is different from .add('dog')
'''
def notused(words):
    all_letters = set("abcdefghijklmnopqrstuvwxyz")
    used=set()
    for word in words:
        used=set(word.lower())|used
    return all_letters-used

'''No.2
>>>a=set(['dog','cat'])
>>>b=set(['dog','cat','monkey'])
>>>a-b
>>>set([])

only_one = (s1-(s2|s3)) | (s2-(s1|s3)) | (s3-(s1|s2))
'''

'''No.3
w1 = "the quick brown fox jumps over the lazy dog"
w2 = "hey diddle diddle the cat and the fiddle the cow jumps over the moon"
w3 = "jack and jill went over the hill to fetch a pail of water"
print len(set(w1.split())&set(w2.split())&set(w3.split()))
'''

'''No.4 *
*:'1234' in '12345' => True
'''
rest_reviews = {"DeFazio's":["Great pizza", "Best in upstate"], \
"I Love NY Pizza":["Great delivery service"], \
"Greasy Cheese": [ "Awful stuff", "Everything was terrible" ] }
'''
for name in rest_reviews.keys():
    count = 0
    for review in rest_reviews[name]:
        review = review.lower()
        if 'awful' in review or 'terrible' in review \
           or 'dump' in review:
            count += 1
    if count > 0:
        print name, count
'''
def add_review(rest_reviews, new_review, rest_name):
    if rest_name in rest_reviews.keys():
        rest_reviews[rest_name].append(new_review)
    else:
        rest_reviews[rest_name] = [new_review]
''' Q6 partd        
L1 = [0,1,2,4,1,0]
s1 = set(L1)
L1.pop()
L1.pop()
L1.pop()
L1[0] = 5
s1.add(6)
s1.discard(1)
print L1
for v in sorted(s1):
    print v
'''
'''Q8'''
class Person(object):
    def __init__( self, n, bd, m, f):
        self.name = n
        self.birthday = bd
        self.mother = m
        self.father = f
        
    def judge(self,other):
        if self.mother==other.mother and self.father==other.father:
            if self.birthday==other.birthday:
                if self.name==other.name:
                    return -1
                return 2
            return 1
        return 0

'''Q9 *'''
D1 = {'Joe':set(['555-1111','555-2222']), 'Jane':set(['555-3333'])}
D2 = {'Joe':set(['555-2222','555-4444']), 'Kate':set(['555-6666'])}

def merge_dict(D1,D2):
    D = D1.copy()
    for key in D2:
        if key in D:
            D[key] = D[key] | D2[key]
        else:
            D[key] = D2[key]
    return D

'''Q10'''
class Rectangle(object):
    def __init__( self, u0, v0, u1, v1 ):
        self.x0 = u0
        self.y0 = v0
        self.x1 = u1
        self.y1 = v1
    
    def inside(self,xt,yt):
        if self.x0<xt<self.x1 and self.y0<yt<self.y1:
            return True
        return False