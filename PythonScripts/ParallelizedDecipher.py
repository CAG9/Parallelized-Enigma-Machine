#!/usr/bin/env python3
"""
License GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
Contact:
    César Arcos González:     cesar99ag@comunidad.unam.mx 
    Brian Kalid García Olivo: briankalid@comunidad.unam.mx
    José Vidal Cardona Rosas: ladivcr@comunidad.unam.mx
    Victor De la Luz:         vdelaluz@enesmorelia.unam.mx
"""
import multiprocessing as mp
from pythonenigma import enigmaM3
import time
import itertools
import string
import numpy
from mpi4py import MPI
import pandas as pd
import sys

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
    #* the message to decipher
    #MPI.Init()
    comm = MPI.COMM_WORLD
    rank = comm.Get_rank() # the rank of each core
    size = comm.Get_size()# Cores size
    
    start_time_read = time.time()

    print("%s:Reading txt..."%(rank))
    sys.stdout.flush()
    msm = open ('message.txt','r')
    message = msm.read()
    message = message.upper()
    msm.close()
    print("%s:end txt..."%(rank))
    print("%s:Reading csv..."%(rank))
    sys.stdout.flush()



    df = pd.read_csv("EnigmaCombinations.csv")
    data = df['Combinations'].tolist()


    
    print("%s:end csv..."%(rank))
    sys.stdout.flush()
    # Parallelizing
    data_per_rank = len(data)
    num_per_rank = data_per_rank // size #1476384 per core if there are 4
    #start_bound = 0
    # split for  cores 
    lower_bound = rank * num_per_rank   #start_bound + rank * num_per_rank
    upper_bound = (rank + 1) * num_per_rank #start_bound + (rank + 1) * num_per_rank
    Combinations = []
    print("%s:Starting split"%(rank))
    sys.stdout.flush()
    for i in range(lower_bound, upper_bound):
        Combinations.append(data[i]) 
    print("%s:Finishing split [%s]"%(rank,len(Combinations)))
    sys.stdout.flush()
    del(data)
    Complete_time_combination = time.time() - start_time_read
    
    comm.Barrier()

    print("%s:Searching..."%(rank))
    sys.stdout.flush()
    
    start_time = time.time()
    printing = num_per_rank // 100
    t1=t0=time.time()
    for i in range(0, num_per_rank):
        if (i % printing == 0):
            t1 = time.time()
            print("%s:[%0.0i %s]"%(rank,(i/num_per_rank)*100, t1-t0))
            sys.stdout.flush()
            t0 = time.time()

        combination = Combinations[i]
        comb1 = (combination[3],combination[8],combination[13])
        comb2 = (int(combination[19]),int(combination[22]),int(combination[25]))
        check = FindOut(comb1,comb2,message)
        if check:
            print("|--- rank %s in %s seconds ---| " %(rank,time.time() - start_time))
            sys.stdout.flush()
            i = num_per_rank+1
            break
    MPI.Finalize()
