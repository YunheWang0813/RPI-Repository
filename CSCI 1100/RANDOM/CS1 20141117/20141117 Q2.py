clubs = {'WRPI': set(['May', 'Coulson']), 'Red Army': set(['Simmons', 'Fitz']), \
'Poly': set(['May']), 'UPAC': set(['Skye', 'Hunter']) }

if __name__=='__main__':
    name=raw_input('Name ==> ')
    x=set()
    y=set()
    for key in clubs.keys():
        if name in clubs[key]:
            x.add(key)
        else:
            y.add(key)
    print 'Member of: %s'%x
    print 'Not member of: %s'%y