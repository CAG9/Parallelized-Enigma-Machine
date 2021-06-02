# Reflectores: Tres posibles
reflectors = [ 'EJMZALYXVBWFCRQUONTSPIKHGD', #A    
              'YRUHQSLDPXNGOKMIEBFZCWVJAT',        
              'FVPJIAOYEDRZXWGCTKUQSBNMHL'] #C

# Rotores: Ocho posibles
con_rotors = [ 'EKMFLGDQVZNTOWYHXUSPAIBRCJ', #1       
            'AJDKSIRUXBLHWTMCQGZNPYFVOE',        
            'BDFHJLCPRTXVZNYEIWGAKMUSQO',        
            'ESOVPZJAYQUIRHXLNFTGKDCMWB',        
            'VZBRGITYUPSDNHLXAWMJQOFECK',      
            'JPGVOUMFYQBENHZRDKASXLICTW',       
            'NZJHGRCXMYSWBOUFAIVLPEKQDT',        
            'FKQHTLXOCBJSPDZRAMEWNIUYGV'] #8      

# Rotores de retorno: Ocho posibles
rotors_return = ['UWYGADFPVZBECKMTHXSLRINQOJ',
                  'AJPCZWRLFBDKOTYUQGENHXMIVS',
                  'TAGBPCSDQEUFVNZHYIXJWLRKOM',
                  'HZWVARTNLGUPXQCEJMBSKDYOIF',
                  'QCYLXWENFTZOSMVJUDKGIARPHB',
                  'SKXQLHCNWARVGMEBJPTYFDZUIO',
                  'QMGYVPEDRCWTIANUXFKZOSLHJB',
                  'QJINSAYDVKBFRUHMCPLEWZTGXO']

alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

def normalize_text(text):
    result = ""
    text = text.replace(" ", "").upper()
    for c in text:
        if c in alphabet:
             result += c
    return result

def char_to_pos(char):       
    return int(ord(char)-65) 

def change(char,charset=alphabet,n=0):
    pos = char_to_pos(char)+n
    char = charset[pos % 26]        
    return char

class enigmaM3:                       
    reflector = ""       
    rotors = ""      
    plugboard = ""                   
    pos_ini= "" #Posicion inicio se actualiza con cada caracter       
    intern_position = ('A','A','A')  # Posición Inicial             
    notch = (('Q',),('E',),('V',),('J',),('Z',),('Z','M'),('Z','M'),('Z','M'))
    opts = []

    def __init__(self,rot,ref,pos_ini,pos_int,plugboard=None):       
        self.set_rotors(rot)       
        self.set_reflector(ref)       
        self.set_pos_ini(pos_ini)       
        self.set_intern_position(pos_int)       
        self.set_plugboard(plugboard)
        self.opts.append([rot,ref,pos_ini,pos_int,plugboard])
    
    def set_reflector(self,char):       
        self.reflector = reflectors[char_to_pos(char)]
    
    def set_rotors(self,rot):       
        rots = []
        for q in range(len(rot)):
            rots.append(rot[q]-1)
        self.rotors = tuple(rots)       
    
    def set_pos_ini(self,pos_ini):       
        self.pos_ini = list(pos_ini)       
    
    def set_intern_position(self,pos_int):                      
        self.intern_position = (pos_int)                       
    
    def set_plugboard(self,plugboard):       
        self.plugboard = plugboard
    
    def reset(self):
        opts = self.opts[0]
        self.__init__(opts[0],opts[1],opts[2],opts[3],opts[4])
    
    def apply_rotor(self,char,n,rotor):
        char = change(char,rotor,n)
        return change(char,n=-n)
    
    def reflecting(self,char):                       
        return change(char,self.reflector)
    
    def rotor_forward(self):       
        if self.pos_ini[1] in self.notch[self.rotors[1]]:            
            self.pos_ini[0] = change(self.pos_ini[0],n=1)       
            self.pos_ini[1] = change(self.pos_ini[1],n=1)       
        if self.pos_ini[2] in self.notch[self.rotors[2]]:       
            self.pos_ini[1] = change(self.pos_ini[1],n=1)      
        self.pos_ini[2] = change(self.pos_ini[2],n=1)
    
    def apply_plugboard(self,char):       
        for i in self.plugboard:       
            if char == i[0]: 
                return i[1]            
            if char == i[1]: 
                return i[0]
        return char
    
    def cipher_letter(self,char):
        char = self.apply_plugboard(char)
        self.rotor_forward()
        for i in range(2,-1,-1):
            n = ord(self.pos_ini[i]) - ord(self.intern_position[i])
            char = self.apply_rotor(char,n,con_rotors[self.rotors[i]])          
        char = self.reflecting(char)             
        for i in range(3):       
            n = ord(self.pos_ini[i]) - ord(self.intern_position[i])       
            char = self.apply_rotor(char,n,rotors_return[self.rotors[i]])             
        char = self.apply_plugboard(char)       
        return char
    
    def cipher(self,text):
        output = ""
        for c in text:
            output += self.cipher_letter(c)
        return output
    
    def decipher(self,text):
        return self.cipher(text)

#Enigma default config
print("Write the message")
plain = input()
plain = plain.upper()


#Rotors initial pos
initial = ('A','B','C')
#Rotors order
rotors = (4,1,3)
#Reflectors
reflector = 'B'
#Intern Position
intern_pos = ('A','A','A')
#plugboard
plugboard = [('A','M'),('F','I'),('N','V'),('P','S'),('T','U'),('W','Z')]

enigma = enigmaM3(rotors,reflector,initial,intern_pos,plugboard)
cipher_text = enigma.cipher(plain)

print("---------------")
print("|   Encode    |")
print("--------------")
print(f"Message: {plain}")
print(f"Encode message: {cipher_text}\n")

print("---------------")
print("|   Decipher    |")
print("--------------")
print(f"Encode message: {cipher_text}")
enigma.reset()
decipher_text = enigma.decipher(cipher_text)
print(f"Decode message: {decipher_text}")
