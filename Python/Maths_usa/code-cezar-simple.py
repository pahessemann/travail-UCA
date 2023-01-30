alphabet = 'abcdefghijklmnopqrstuvwxyz'



message = input("Ecrivez votre message")
decalage = int(input("Valeur du decalage?"))

def crypt(mess , decalage , z ):
    traduction=''
    i=0
    x = 0
    
    while i<len(mess) :
        x = (alphabet.find(mess[i]) + (z * decalage))%len(alphabet)
        
        traduction = traduction+alphabet[x]
        i = i+1
    return (traduction)


m = crypt(message ,decalage, 1)
print(m)
print(crypt(m ,decalage, -1))