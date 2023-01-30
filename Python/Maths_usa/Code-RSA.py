from random import randrange

alphabet = 'abcdefghijklmnopqrstuvwxyz'
message = input("Ecrivez votre message")


p = int(input("Nombre p, premier s'il vous plait!"))
q =int(input("Nombre q, premier s'il vous plait!"))


def rabinMiller(num):
    # Renvoie True si nombre est un nombre premier.

    s = num - 1
    t = 0
    while s % 2 == 0:
        # maintenir la réduction de moitié de jusqu'à ce qu'il soit même (et utiliser t
		# à compter combien de fois nous réduire de moitié s)
        s = s // 2
        t += 1

    for trials in range(5): # essayer de falsifier primalité 5 l'époque de numéros
        a = random.randrange(2, num - 1)
        v = pow(a, s, num)
        if v != 1: # Ce test ne s'applique pas si v est 1.
            i = 0
            while v != (num - 1):
                if i == t - 1:
                    return False
                else:
                    i = i + 1
                    v = (v ** 2) % num
    return True

rabinMiller(p)
rabinMiller(q)

N = p*q
print("N est égale à :")
print(N)

phi = (p-1)*(q-1)


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

def genE (phi):
     indice = phi -1
     while indice>0:
         if PGCD (phi , indice) == 1:
             return indice
         else :
            indice = indice-1
            
            
            
def findModInverse(a, m):
    # Renvoie l'inverse modulaire d'un% m, ce qui est
	# le nombre x de telle sorte que a * x% m = 1

    if gcd(a, m) != 1:
        return None # pas d'inverse mod si un m & ne sont pas premiers entre eux

    # Calculer en utilisant l'algorithme d'Euclide étendu:
    u1, u2, u3 = 1, 0, a
    v1, v2, v3 = 0, 1, m
    while v3 != 0:
        q = u3 // v3 # // est l'opérateur de division entière
        v1, v2, v3, u1, u2, u3 = (u1 - q * v1), (u2 - q * v2), (u3 - q * v3), v1, v2, v3
    return u1 % m
        
             
E = genE (phi)
D = findModInverse(E, phi)

print("La clé publique :")

print("et :")

print("La clé privé :")


