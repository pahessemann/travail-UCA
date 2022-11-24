message=input('Entrer votre message')
def crypt(mess):
    traduction=''
    i=len(mess)-1
    
    while i>-1 :
        traduction = traduction+mess[i]
        i = i-1
    return (traduction)
m = crypt(message)
print(m)
print(crypt(m))
    
        

