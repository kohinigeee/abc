x = int(input())

y = format(x, 'x')
y = y.upper()

if ( len(y) == 1 ):
    y = '0'+y
print(y)