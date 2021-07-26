#!/usr/bin/env python3
"""
License GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
Contact:
    César Arcos González: cesar99ag@comunidad.unam.mx 
    Brian Kalid García Olivo: briankalid@comunidad.unam.mx
    José Vidal Cardona Rosas: ladivcr@comunidad.unam.mx
"""
import multiprocessing as mp
from pythonenigma import enigmaM3
import time
import itertools
import string
import pandas as pd

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


def FindOut(t_letter,t_number,msg):
    myM3 = createM3(t_number, t_letter)
    decipher_text = myM3.decipher(msg)
    if "FUHRER" in decipher_text:
        print("Message decoded!")
        print(decipher_text)
        print("Numbers ",t_number)
        print("Letters ",t_letter)

        return True

    return False

if __name__ == "__main__":
    # the message to decipher
    msm = open ('message.txt','r')
    message = msm.read()
    message = message.upper()
    msm.close()
    # Load all combinations
    df = pd.read_csv("EnigmaCombinations.csv")
    Combinations = df['Combinations'].tolist()
    start_time = time.time()
    for combination in Combinations:
        comb1 = (combination[3],combination[8],combination[13])
        comb2 = (int(combination[19]),int(combination[22]),int(combination[25]))
        check = FindOut(comb1,comb2,message)
        if check:
            break
    print("--- %s seconds --- " %(time.time() - start_time))	















