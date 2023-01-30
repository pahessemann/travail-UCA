# -*- coding: utf-8 -*-
"""
Created on Mon Dec 5 13:43:09 2022

@author: paul.hessemann
"""

def est_premier(n):
        if n == 2 or n == 3 :
                return True
        if n%2 == 0 or n<2:
                return False

        for i in range(3, int(n**0.5)+1,2):
                if n%i==0:
                        return False
        return True


def PGCD(a,b) :
   while a%b != 0 :
      a, b = b, a%b
   return b


def inverse_modulaire(a,n):
    x = 0
    while (a * x % n != 1):
                x = x +1;
    return x


def LCP(n):
    LCP = []
    for i in range(2,n):
        if(est_premier(i) == True):
            LCP.append(i);
    return LCP


def Generateur_de_cle(LP):
        p = random.choice(LP);
        q = random.choice(LP);
        if q == p :
                q = random.choice(LP);
        return(p*q)

def Cle_N(p,q):
        return p*q

def Fn(p,q):
        Fn = (p-1) * (q-1)
        return Fn

def Fn_V2(N):
        if N == 1:
                return 1
        else:
                L = [k for k in range(1,N) if PGCD(N,k)==1]
        return len(L)


def Rec_Facteurs(N):
    Phi = Fn_V2(N)
    Somme = N - Phi + 1
    Produit = N

    Dsc = ((-1 * Somme) ** 2) - (4 * 1 * Produit)
    if est_premier(N) == True:
        return(N,1)
    elif (Dsc == 0):
        p = -1 * Somme // 2
        q = 1
        return(int(p),int(q))
    elif (Dsc > 0):
        p = (Somme - (Dsc**0.5)) // 2
        q = (Somme + (Dsc**0.5)) // 2
        return(int(p),int(q))
    else:
        print("Erreur")


def RSA_Cryptage(Alphabet, Message,E,N):
    temp = ""
    for e in Message:
        if Alphabet.index(e) < 10:
            temp += "0" + str(Alphabet.index(e))
        else:
            temp += str(Alphabet.index(e))

    print(temp)



#def RAS_Decryptage(Alphabet, Message, D):


if __name__== "__main__":
        #print("Exercice 1:\n")
        #print("Nous disposons des informations suivantes :\n")
        N = 391 #partie de la clé publique
        E = 151 #partie de la clé publique
        D = 7  #clé privée
        #1)
        print("Le message transmis par Bob est C = 17")
        C = 17
        print("Pour déchiffrer ce message, on a recours à la procédure suivante : M = C puissance D")
        M = C ** D % N
        print("Le message déchiffré vaut donc :",M)
        #2)
        print("Pour retrouver p et q tel que N = p*q, on a recours à la fonction def_Facteurs:")
        print("p et q valent donc respectivement :")
        print(Rec_Facteurs(N))
        print("Par la fonction Fn_V2, on trouve directement Phi(n)\n:")
        print("Sa valeur est donc:", Fn_V2(391))
        print("Une déduction connaissant les valeurs de p et q se fait par :")
        print("On obtient ainsi la meme valeur : ", Fn(17,23))
        #3)
        print("D est l'inverse modulaire de E en Phi(n)")
        print("A l'aide des fonctions adéquates, on effectue la procédure suivante et on trouve:")
        print("D = E puissance -1 modulo phi(N)\n")
        print("On retrouve bien D =", inverse_modulaire(E, Fn(17,23)))

        #print("Exercice 2:\n")
        print("On considère les éléments suivants:")
        N2 = 221
        E2 = 11
        D2 = 35
        #a) Chiffrer  le messsage M :
        M2 = 112
        if M2 < N2:
            C2 = M2 ** E2 % N2
            print("Le message crypté vaut :",C2)

        #b) Déchiffrer le cryptogramme Cn:
        Cn = 78
        Mn = Cn ** D2 % N2
        print("Le message déchiffré vaut :", Mn)

        #2)
        p2 = 53
        q2 = 71
        #a) Calcul de N et Phi(n)
        Nn = p2*q2
        print("N vaut :", p2*q2)
        print("Phi(n) vaut: ", Fn(p2,q2), Fn_V2(Nn))
        print("On remarque que les deux méthodes donnent le meme résultat")
        #b)
        Eq = 307
        if((Eq < Fn_V2(Nn)) and (PGCD(Fn_V2(Nn),Eq) == 1)):
            Dq = inverse_modulaire(Eq,Fn_V2(Nn))
        print("D vaut :", Dq)
        #c)
        print("Elements constituant la clé publique :",Eq ,Nn)
        print("Element constituant le clé privée:",Dq )
        #d)
        print("Une fois la procédure terminée, il est recommandé de détruire les éléments constituant la clé privée car ils ne seront plus d'aucune utilité.\n")

        #print("Exercice 3:\n")
        ALPHABET = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"]
        Er = 257
        Nr = 1073
        Dr = 353

        Mr = "RSA"
        temp=""
        for e in Mr:
            if ALPHABET.index(e) < 10:
                temp+= "0"+str(ALPHABET.index(e))
            else:
                temp += str(ALPHABET.index(e))

        print(temp)

        part_1 =""
        for i in range(0,3):
            part_1+= temp[i]
        part_1 = int(part_1)
        print(part_1)
        part_2=""
        for i in range(3,len(temp),1):
            part_2+= temp[i]
        part_2 = int(part_2)
        print(part_2)
        Cr1 =(part_1**Er)%Nr
        Cr2 = (part_2**Er)%Nr
        print(Cr1, Cr2)
        crypted = str(Cr1)+";"+str(Cr2)
        print(crypted)

        Cr = "105;578"
        Cra=""
        Crb=""

        for e in Cr:
            if e == ";":
                break
            else:
                Cra+=e
        Cra = int(Cra)
        print(Cra)

        for i in range(4,len(Cr)):
            Crb+=Cr[i]
        Crb = int(Crb)
        print(Crb)

        K =(Cra**Dr)% Nr
        if K < 10 :
            K = "00"+ str(K)
        elif K < 100:
            K = "0" + str(K)
        G = (Crb**Dr)% Nr
        if G < 10:
            G = "00" + str(G)
        elif G <100:
            G = "0"+str(G)
        Message_inter1 = str(K)+";"+str(G)
        Message_inter2 = str(K)+str(G)
        print(Message_inter2)
        bloc1=""
        bloc2=""
        bloc3=""
        for i in range(0,2):
            bloc1+=Message_inter2[i]
        for i in range(2, 4):
            bloc2 += Message_inter2[i]
        for i in range(4, 6):
            bloc3 += Message_inter2[i]
        print(bloc1,bloc2,bloc3)

        Message_dechiffre=""
        indice1=int(bloc1)
        indice2=int(bloc2)
        indice3=int(bloc3)
        Message_dechiffre+= ALPHABET[indice1]+ALPHABET[indice2]+ALPHABET[indice3]
        print(Message_dechiffre)

#3)_____________________________________________________________________________________________________________________
#a)___________________CHIFFREMENT_DU_MOT_METHODE________________________________________________________________________
        ALPHABET1 = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"]
        Er1 = 257
        Nr1 = 1073
        Dr1 = 353
        Mr1 = "METHODE"
        temp1=""
        for e in Mr1:
            if ALPHABET1.index(e) < 10:
                temp1+= "0"+str(ALPHABET1.index(e))
            else:
                temp1 += str(ALPHABET1.index(e))

        print(temp1)

        L = []

        for i in range(0,len(temp1)-2,3):
            if i <= len(temp1)-1:
                if i <(len(temp1) -2) :
                    a = temp1[i] + temp1[i + 1] + temp1[i + 2]
                    L.append(a)
                elif temp1[i+2] == -1:
                    a = temp1[i]+temp1[i+1]
                    L.append(a)
                elif temp1[i + 1] == -1:
                    a = temp1[i]
                    L.append(a)



        for e in L:
            print(e)
        LCD = []
        for i in range(len(L)):
            L[i] = int(L[i])
            LCD.append(L[i])
        for e in LCD:
            print(e)

        LMD =[]
        for i in range(len(LCD)):
            LMD.append(LCD[i] ** Er % Nr)

        for e in LMD:     # contient les indices cryptés
            print(e)

        Cryptogramme = ""

        for i in range(len(LMD)):
            if i!= len(LMD) - 1:
                Cryptogramme+= str(LMD[i])+";"
            else:
                Cryptogramme+= str(LMD[i])


        for e in Cryptogramme:
            print(e,end='')

#b)__________________________________________Dechiffrer_________________________________________________________________
        ALPHABET2 = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T","U", "V", "W", "X", "Y", "Z"]
        Er2 = 257
        Nr2 = 1073
        Dr2 = 353
        Mr2 = "263;115;613;10"
        temp2 = ""
        LB =[]
        LB = Mr2.split(";")
        print("\n")
        for e in LB:
            print(e,end=' ')
        print("\n")

        for i in range(len(LB)):
            LB[i]= int(LB[i]) #tous les elements de LB deviennent des entiers

        LS = []

        for i in range(len(LB)):
            LS.append((LB[i]**Dr)% Nr)

        for e in LS:
            print(e, end= ' ') #LS contient les valeurs déchiffrées modulo Nr

        print("\n")

        Concat=""
        for i in range(len(LS)):
            LS[i] = str(LS[i])
            Concat+= LS[i]
        print(Concat)

        LI = []

        for i in range(0,len(Concat),2):
            if i != len(Concat)-1:
                LI.append(Concat[i] + Concat[i+1])
            elif i == len(Concat)-1:
                LI.append(Concat[i])

        for e in LI:
            print(e, end=' ')

        MSDC = ""

        for i in range(len(LI)):
            k = int(LI[i]) % len(ALPHABET2)
            MSDC+= ALPHABET2[k]
        print(MSDC)