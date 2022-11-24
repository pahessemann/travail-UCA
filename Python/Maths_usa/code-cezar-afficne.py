alphabet = 'abcdefghijklmnopqrstuvwxyz'



message = input("Ecrivez votre message")
decalagex = int(input("Valeur du decalage x?"))
decalagey= int(input("Valeur du decalage y?"))

def PGCD (a , b):
    while a!=b: 
        d=abs(b-a) 
        b=a 
        a=d 
        print("pgcd=",d)
        return d
    if d==1: 
        print("Les deux entiers sont premiers entre eux.")
        return 0



def crypt(mess , z ):
    traduction=''
    i=0
    x = 0
    
    while i<len(mess) :
        x = (decalagex*((alphabet.find(mess[i]))) + (z * decalagey))%len(alphabet)
        
        traduction = traduction+alphabet[x]
        i = i+1
    return (traduction)

def euclideetendu ( a, b):
    x=1 ; xx=0
    y=0 ; yy=1
    while b!=0:
        q=a//b
        a, b == b , a%b
        xx , x=x-q*xx , xx
        yy , y=y-q*yy , yy
    return(a,x,y)


def decrypt(mess , z ):
    traduction=''
    i=0
    x = 0
    
    while i<len(mess) :
        x = (u*((alphabet.find(mess[i]))) + (z * v))%len(alphabet)
        
        traduction = traduction+alphabet[x]
        i = i+1
    return (traduction)


pgcd = PGCD( decalagex, decalagey)
a,u,v=euclideetendu ( decalagex, len(alphabet))
m = crypt(message , 1)
print(m)
print(decrypt(m , pgcd))