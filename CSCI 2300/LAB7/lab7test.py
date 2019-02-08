import heapdict

def huffman(chars, code, deep):
    while len(chars)>1:
        l=chars.popitem()
        r=chars.popitem()
        for i in l[0]:
            code[i]+='0'
            deep[i]+=1
        for i in r[0]:
            code[i]+='1'
            deep[i]+=1
        z=l[0]+r[0]
        zfreq=chars[z]=l[1]+r[1]
        chars[z]=zfreq


if __name__ == '__main__':
    chars=heapdict.heapdict()
    code={}
    deep={}
    
    for c in 'mississippi':
        if c in chars:
            chars[c]+=1
        else:
            chars[c]=1
            code[c]=''
            deep[c]=0
    
    freq={}
    for i in chars:
        freq[i]=chars[i]
                
    huffman(chars, code, deep)

    for i in code:
        code[i]=code[i][::-1]
        
    length=0
    for i in freq:
        length+=freq[i]*deep[i]