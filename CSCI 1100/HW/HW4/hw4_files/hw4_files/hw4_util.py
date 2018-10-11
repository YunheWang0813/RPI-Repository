""" This is a utility module for Homework#4 in CSCI 1100 Fall 2015

    For part 2, use the read_legos function to read the lego information
    as follows:

    import hw4_util
    legos = read_legos()


    For part 3, use the read_flu function to read the flu related data 
    for a country as follows:

    import hw4_util
    cdata = hw4_util.read_flu('US') ##for country='US'


"""


def read_flu(country):
    dates, countries = read_flu_all()
    for country_data in countries:
        if country_data[0].lower() == country.lower():
            return country_data[1:]
    return []

def read_flu_all():
    i = 0
    header = []
    countries = []
    dates = []
    for line in open('google_flu.csv').read().split("\r"):
        m = line.strip().split(",")
        i += 1
        if i == 1:
            for val in m[1:]:
                countries.append( [val] )
        else:
            date = m[0].split("/")
            dates.insert(0, date[0])
            for i in range(1,len(m)):
                val = int(m[i])
                countries[i-1].insert(1, val)
    return dates, countries

def read_legos():
    legos = []
    for line in open('legos.txt'):
        m = line.strip().split()
        cnt = int(m[0])
        lego = m[1]
        legos += [lego]*cnt
    return legos

if __name__ == "__main__":
    ## Example use
    data = read_flu('Brazil')
    print data

    legos = read_legos()
    print legos
