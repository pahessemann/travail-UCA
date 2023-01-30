alphabet = 'abcdefghijklmnopqrstuvwxyz'



message = input("Ecrivez votre message")
decalagex = int(input("Valeur du decalage x?"))
decalagey= int(input("Valeur du decalage y?"))


def crypt(mess, decalagex, decalagey):
    traduction=''
    i=0
    x = 0
    
    while i<len(mess) :
        x = (decalagex*((alphabet.find(mess[i]))) + (decalagey))%len(alphabet)
        
        traduction = traduction+alphabet[x]
        i = i+1
    return (traduction)


def decrypt(mess, x , y):
    
    int(u=0)
    u= (1/x)%len(alphabet)
    i=0
    c = 0
    
    while i<len(mess) :
        c = ((u*mess)-(y*u))%len(alphabet)
        
        traduction = traduction+alphabet[x]
        i = i+1
    return (traduction)
        


m = crypt(message,decalagex,decalagey)
print(m)
print(decrypt(m , decalagex, decalagey))
print(m)