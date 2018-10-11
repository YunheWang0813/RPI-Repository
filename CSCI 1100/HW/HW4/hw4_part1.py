Word=raw_input('Enter a word => ')
print Word
def is_alternating(word):
    word=word.lower()
    vomel=['a','o','i','e','u']
    if len(word)<8:
        return False
    else:
        i=0
        j=0
        k=0
        l=0
        while i<(len(word)+1)/2:
            if word[2*i] in vomel:
                j+=1
            else:
                j+=0
            i+=1
        while k<len(word)/2-1:
            if word[2*k+1]<word[2*k+3]:
                l+=1
            else:
                l+=0
            k+=1
        if j==(len(word)+1)/2 and l==len(word)/2-1:
            return True
        else:
            return False

if is_alternating(Word)==True:
    print 'The word '+"'"+Word.lower()+"'"+' is alternating'
if is_alternating(Word)==False:
    print 'The word '+"'"+Word.lower()+"'"+' is not alternating'