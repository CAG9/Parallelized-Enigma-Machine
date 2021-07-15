import multiprocessing as mp
from multiprocessing import Pool
from pythonenigma import enigmaM3
import time
#from itertools import permutations

#def rotors_initial_pos(rotors_letter): 
#    """Function for finding all three-letter permutations in the alphabet
#    ---------------------
#    Args:
#        rotors_letter (tuple): a tuple with the english alphabet
#    -------------------
#    returns: list of list with all possible permutations of three-letter
#    """
#    return list(permutations(rotors_letter,3))

#def rotors_order(rotors_number):
#    """Function to generate all three-number permutation
#    ------------------------
#    Args:
#        rotors_number (numbers tuple): a tuple with integers from 0 to 9
#    ----------------------
#    return: list of list with all possible permutations of three-numbers
#    """
#    return list(permutations(rotors_number, 3))



def createM3(rotors, initial):
    """A function to create a enigmaM3 machine
    ------------------------
    Args:
        rotors (tuple): A tuple of three-number
        initial (tuple): A tuple of three-letter
    ----------------------
    return: enigmaM3 machine
    
    """
    #Reflectors
    reflector = 'B'
    #Intern Position
    intern_pos = ('A','A','A')
    #plugboard
    plugboard = [('A','M'),('F','I'),('N','V'),('P','S'),('T','U'),('W','Z')]

    # Create our engima with initial settings
    enigma_decipher = enigmaM3(rotors, reflector, initial, intern_pos, plugboard)
    
    return enigma_decipher

#def decrip(myM3): 
#    """A function to try decipher a message
#    Args:
#        myM3 (enigmaM3): An object created by us
#
#    Returns:
#        [bool]: [message decipher or not]
#    """
    # Try to decipher the message
#    myM3.reset()
#    decipher_text = myM3.decipher(message)
#    if "FUHRER" in decipher_text:
#        print("Message decoded!")
#        print(decipher_text)
#        return True
#    else: 
#        return False
    
def comprobar(t_letter,t_number,msg):
    myM3 = createM3(t_number, t_letter)

    
    #myM3.reset()
    decipher_text = myM3.decipher(msg)

    #print(t_letter,t_number)
    #print(decipher_text)

    if "FUHRER" in decipher_text:
        print("Message decoded!")
        print(decipher_text)
        print("TNumber ",t_number)
        print("TLEtter ",t_letter)

        return True

    return False
    #print(decipher_text)
    



     

def rotors_number_pos(iterable,r,letters,message):
    pool = tuple(iterable)
    n = len(pool)
    r = n if r is None else r
    if r > n:
        return
    indices = list(range(n))
    cycles = list(range(n, n-r, -1))
    

    initial = tuple(pool[i] for i in indices[:r])
    
    res=comprobar(letters,initial,message)

    if res:
        return True

    while n:
        for i in reversed(range(r)):
            cycles[i] -= 1
            if cycles[i] == 0:
                indices[i:] = indices[i+1:] + indices[i:i+1]
                cycles[i] = n - i
            else:
                j = cycles[i]
                indices[i], indices[-j] = indices[-j], indices[i]

                next_stp = tuple(pool[i] for i in indices[:r])
                
                res=comprobar(letters,next_stp,message)

                if res:
                    return True

                break
        else:
            return



def rotors_letter_pos(iterable,iterable_numbers,r,message):
    pool = tuple(iterable)
    n = len(pool)
    r = n if r is None else r
    if r > n:
        return
    indices = list(range(n))
    cycles = list(range(n, n-r, -1))
    

    initial = tuple(pool[i] for i in indices[:r])


    res=rotors_number_pos(iterable_numbers,r,initial,message)
    if res:
        return


    while n:
        for i in reversed(range(r)):
            cycles[i] -= 1
            if cycles[i] == 0:
                indices[i:] = indices[i+1:] + indices[i:i+1]
                cycles[i] = n - i
            else:
                j = cycles[i]
                indices[i], indices[-j] = indices[-j], indices[i]

                next_stp = tuple(pool[i] for i in indices[:r])
                res=rotors_number_pos(iterable_numbers,r,next_stp,message)
                if res:
                    return

                break
        else:
            return



if __name__ == "__main__":
    #* the message to decipher
    msm = open ('message.txt','r')
    message = msm.read()
    message = message.upper()
    msm.close()
    start_time = time.time()

    #* Enigma default config 
    # (This is what we need to find in our program)

    #* Rotors initial pos
    # initial = ('A','B','C') # Objective
    # Omitimos la ñ, dado que trabajamos con el alfabeto inglés
    rotors_letter = ("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
    #initial = rotors_initial_pos(rotors_letter) # Get all permutations with three-letters

    #* Rotors order
    # rotors = (4,1,3) # Objective
    rotors_number = (0,1, 2, 3, 4, 5, 6, 7, 8)
    #rotors = rotors_order(rotors_number)


    # ! FALTA DESARROLLAR EL BUCLE ANIDADO PARA PROBAR LAS CONFIGURACIONES
    # ! Es aquí dónde usare: multiprocessing.process
    # * https://rico-schmidt.name/pymotw-3/multiprocessing/basics.html
    advance = 1



    #rotors_letter_pos(rotors_letter,rotors_number,3,message)
   
    with Pool(processes=4) as pool:
        result = pool.map(rotors_letter_pos,(rotors_letter,rotors_number,3,message))
        
    
    print("--- %s seconds --- " %(time.time() - start_time))	



 
   
