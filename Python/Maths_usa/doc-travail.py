MessageCrypte="JC QAPGNR NMSP BCAMBCP LC BCTPYGR NYQ CRPC JMLE Y DYGPC HC JC BMLLCPYG QSP AC KCKC DMPSK"
lg=len(MessageCrypte)
MessageClair=""
cle=24 

for i in range(lg):
    if MessageCrypte[i]==' ':
        MessageClair+=' '
    else:
        asc=ord(MessageCrypte[i])-cle
        MessageClair+=chr(asc+26*((asc<65)-(asc>90)))

print MessageClair