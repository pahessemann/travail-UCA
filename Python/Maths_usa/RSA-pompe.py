#!/usr/bin/env python3
#-*- coding:utf-8 -*-



import random, sys, os


def gcd(a, b):
    # Retour le PGCD de a et b en utilisant l'algorithme d'Euclide 
    while a != 0:
        a, b = b % a, a
    return b


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

def generateKey(keySize):
    # Crée une paire de clés publique / privée avec des touches qui sont des bits dans KEYSIZE
	# taille. Cette fonction peut prendre un certain temps à courir.

    # Etape 1: Création de deux nombres premiers, p et q. Calculer n = p * q.
    print('Generating p prime...')
    p = generateLargePrime(keySize)
    print('Generating q prime...')
    q = generateLargePrime(keySize)
    n = p * q

    # Étape 2: Créer un nombre e qui est premier avec (p-1) * (q-1).
    print('Generating e that is relatively prime to (p-1)*(q-1)...')
    while True:
        # Continuez à essayer des nombres aléatoires pour e jusqu'à ce que l'on est valide.
        e = random.randrange(2 ** (keySize - 1), 2 ** (keySize))
        if gcd(e, (p - 1) * (q - 1)) == 1:
            break

    # Etape 3: Calculer d, l'inverse de mod e.
    print('Calculating d that is mod inverse of e...')
    d = findModInverse(e, (p - 1) * (q - 1))

    publicKey = (n, e)
    privateKey = (n, d)

    print('Public key:', publicKey)
    print('Private key:', privateKey)

    return (publicKey, privateKey)


def makeKeyFiles(name, keySize):
    # Crée de la x_pubkey.txt «deux fichiers et 'x_privkey.txt' 
    #(où x est la valeur de nom) avec le n, e et d, e entiers écrits en eux, délimité par une virgule.

    # Notre vérification de sécurité ne nous empêchera d'écraser nos anciens fichiers clés:
    if os.path.exists('%s_pubkey.txt' % (name)) or os.path.exists('%s_privkey.txt' % (name)):
        sys.exit('WARNING: The file %s_pubkey.txt or %s_privkey.txt already exists! Use a different name or delete these files and re-run this program.' % (name, name))

    publicKey, privateKey = generateKey(keySize)

    print()
    print('The public key is a %s and a %s digit number.' % (len(str(publicKey[0])), len(str(publicKey[1]))))
    print('Writing public key to file %s_pubkey.txt...' % (name))
    fo = open('%s_pubkey.txt' % (name), 'w')
    fo.write('%s,%s,%s' % (keySize, publicKey[0], publicKey[1]))
    fo.close()

    print()
    print('The private key is a %s and a %s digit number.' % (len(str(publicKey[0])), len(str(publicKey[1]))))
    print('Writing private key to file %s_privkey.txt...' % (name))
    fo = open('%s_privkey.txt' % (name), 'w')
    fo.write('%s,%s,%s' % (keySize, privateKey[0], privateKey[1]))
    fo.close()



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


def isPrime(num):
    # Retour Vrai si nombre est un nombre premier. Cette fonction fait une rapide
	# Premier chèque de numéro avant rabinMiller ().

    if (num < 2):
        return False # 0, 1, and negative numbers are not prime

    # À propos de 1/3 du temps, nous pouvons rapidement déterminer si num n'est pas premier en divisant par
	# Les quelques premiers douzaine de nombres premiers. Ceci est plus rapide
	# De rabinMiller (), mais contrairement rabinMiller () n'est pas garanti
	# Prouver qu'un nombre est premier.
    lowPrimes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997]

    if num in lowPrimes:
        return True

    # Voir si l'un des nombres premiers faible peut diviser num
    for prime in lowPrimes:
        if (num % prime == 0):
            return False

    # Si tout le reste échoue, appeler rabinMiller () pour déterminer si nombre est un nombre premier.
    return rabinMiller(num)


def generateLargePrime(keysize=1024):
    # Retourne un nombre premier aléatoire de bits KEYSIZE taille.
    while True:
        num = random.randrange(2**(keysize-1), 2**(keysize))
        if isPrime(num):
            return num




# IMPORTANT: La taille de bloc doit être inférieure ou égale à la taille de la clé!
# (Remarque: La taille de bloc est en octets, la taille de la clé est en bits Il.
# 8 bits dans 1 octet).
DEFAULT_BLOCK_SIZE = 128 # 128 bytes
BYTE_SIZE = 256 # Un octet dispose de 256 valeurs différentes.

def getBlocksFromText(message, blockSize=DEFAULT_BLOCK_SIZE):
    # Convertit un message de chaîne à une liste d'entiers de blocs. chaque entier
	# Représente 128 (ou quel que soit blockSize est réglé sur) les chaînes de caractères.

    messageBytes = message.encode('ascii') # convert the string to bytes

    blockInts = []
    for blockStart in range(0, len(messageBytes), blockSize):
        # Calculer le nombre entier de bloc pour ce bloc de texte
        blockInt = 0
        for i in range(blockStart, min(blockStart + blockSize, len(messageBytes))):
            blockInt += messageBytes[i] * (BYTE_SIZE ** (i % blockSize))
        blockInts.append(blockInt)
    return blockInts


def getTextFromBlocks(blockInts, messageLength, blockSize=DEFAULT_BLOCK_SIZE):
    # Convertit une liste des blocs entiers à la chaîne de message d'origine.
	# La longueur du message d'origine est nécessaire pour convertir correctement le dernier entier de bloc.
    message = []
    for blockInt in blockInts:
        blockMessage = []
        for i in range(blockSize - 1, -1, -1):
            if len(message) + i < messageLength:
                # Décoder la chaîne de message pour le 128 (ou quel que soit 
				# BlockSize est réglé sur) des personnages de ce bloc entier.
                asciiNumber = blockInt // (BYTE_SIZE ** i)
                blockInt = blockInt % (BYTE_SIZE ** i)
                blockMessage.insert(0, chr(asciiNumber))
        message.extend(blockMessage)
    return ''.join(message)


def encryptMessage(message, key, blockSize=DEFAULT_BLOCK_SIZE):
    # Convertit la chaîne de message dans une liste de nombres entiers de blocs, puis 
	# Crypte chaque nombre entier de bloc. Passez la clé publique pour chiffrer.
    encryptedBlocks = []
    n, e = key

    for block in getBlocksFromText(message, blockSize):
        # ciphertext = plaintext ^ e mod n
        encryptedBlocks.append(pow(block, e, n))
    return encryptedBlocks


def decryptMessage(encryptedBlocks, messageLength, key, blockSize=DEFAULT_BLOCK_SIZE):
    # Déchiffre une liste d'entiers de blocs cryptés dans le message d'origine 
	# Chaîne. La longueur du message d'origine est nécessaire pour déchiffrer correctement 
	# Le dernier bloc. Assurez-vous de passer la clé privée pour décrypter.
    decryptedBlocks = []
    n, d = key
    for block in encryptedBlocks:
        # texte Clair = texte chiffré ^ d mod n
        decryptedBlocks.append(pow(block, d, n))
    return getTextFromBlocks(decryptedBlocks, messageLength, blockSize)


def readKeyFile(keyFilename):
    # Étant donné le nom d'un fichier qui contient une clé publique ou privée, 
    # Retourner la clé comme un (n, e) ou (n, d) tuple.
    fo = open(keyFilename)
    content = fo.read()
    fo.close()
    keySize, n, EorD = content.split(',')
    return (int(keySize), int(n), int(EorD))


def encryptAndWriteToFile(messageFilename, keyFilename, message, blockSize=DEFAULT_BLOCK_SIZE):
    # Aide d'une clé à partir d'un fichier de clé, chiffrer le message et l'enregistrer dans un 
    # Fichier. Retourne la chaîne de message chiffré.
    keySize, n, e = readKeyFile(keyFilename)

    # Assurez-vous que la taille de clé est supérieure à la taille de bloc.
    if keySize < blockSize * 8: # * 8 pour convertir octets à des bits
        sys.exit('ERROR: Block size is %s bits and key size is %s bits. The RSA cipher requires the block size to be equal to or greater than the key size. Either decrease the block size or use different keys.' % (blockSize * 8, keySize))


    # Chiffrer le message
    encryptedBlocks = encryptMessage(message, (n, e), blockSize)

    # Convertir les grandes valeurs int pour une valeur de chaîne.
    for i in range(len(encryptedBlocks)):
        encryptedBlocks[i] = str(encryptedBlocks[i])
    encryptedContent = ','.join(encryptedBlocks)

    # Écrivez la chaîne cryptée dans le fichier de sortie.
    encryptedContent = '%s_%s_%s' % (len(message), blockSize, encryptedContent)
    fo = open(messageFilename, 'w')
    fo.write(encryptedContent)
    fo.close()
    # Retourne également la chaîne cryptée.
    return encryptedContent


def readFromFileAndDecrypt(messageFilename, keyFilename):
    # Aide d'une clé à partir d'un fichier de clé, de lire un message crypté à partir d'un fichier 
    # Puis le déchiffrer. Retourne la chaîne de message déchiffré.
    keySize, n, d = readKeyFile(keyFilename)


    # Lire dans la longueur du message et le message crypté à partir du fichier.
    fo = open(messageFilename)
    content = fo.read()
    messageLength, blockSize, encryptedMessage = content.split('_')
    messageLength = int(messageLength)
    blockSize = int(blockSize)

    # Assurez-vous que la taille de clé est supérieure à la taille de bloc.
    if keySize < blockSize * 8: # * 8 to convert bytes to bits
        sys.exit('ERROR: Block size is %s bits and key size is %s bits. The RSA cipher requires the block size to be equal to or greater than the key size. Did you specify the correct key file and encrypted file?' % (blockSize * 8, keySize))

    # Convertir le message crypté dans les grandes valeurs int.(grands entiers)
    encryptedBlocks = []
    for block in encryptedMessage.split(','):
        encryptedBlocks.append(int(block))

    # Décrypter les grandes valeurs int.(grands entiers)
    return decryptMessage(encryptedBlocks, messageLength, (n, d), blockSize)




# fonction de lancement
def main():
	# Créer une paire de clés publique / privée avec 1024 touches de bits
    print('Création des fichiers clés...')
    makeKeyFiles('CervoKeys', 1024)
    print('Effectué ! ')
    # Exécute un test qui permet de crypter un message dans un fichier ou déchiffre un message 
    # À partir d'un fichier.
    filename = 'encrypted_file.txt' # the file to write to/read from
    mode = 'encrypt' # choix du mode

    if mode == 'encrypt':
        message = '''Salut à tous, je partage avec vous mes quelques notions de cryptage ! j'espère continuer a partager ainsi car moi aussi je profite tjrs des notions des autres'''
        pubKeyFilename = 'CervoKeys_pubkey.txt'
        print('Chiffrement et écriture dans %s...' % (filename))
        encryptedText = encryptAndWriteToFile(filename, pubKeyFilename, message)

        print('Texte chiffré:')
        print(encryptedText)

    elif mode == 'decrypt':
        privKeyFilename = 'CervoKeys_privkey.txt'
        print('Lecture depuis %s et déchiffrement...' % (filename))
        decryptedText = readFromFileAndDecrypt(filename, privKeyFilename)

        print('Texte déchiffré :')
        print(decryptedText)








# Lancement s'il n'est pas importé comme module.
if __name__ == '__main__':
    main()