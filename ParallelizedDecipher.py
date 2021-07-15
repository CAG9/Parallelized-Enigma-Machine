import multiprocessing as mp
from pythonenigma import enigmaM3
import time
import itertools
import string
import numpy
from mpi4py import MPI

def GetCombinations():
    Initial = list(string.ascii_uppercase)
    Initial_combination = list(itertools.product(Initial,repeat=3))

    Rotors = [1,2,3,4,5,6,7,8]
    Rotors_combination = list(itertools.permutations(Rotors,r=3))
    c = list(itertools.product(Initial_combination, Rotors_combination))
    return c


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


def comprobar(t_letter,t_number,msg):
    myM3 = createM3(t_number, t_letter)

    
    #myM3.reset()
    decipher_text = myM3.decipher(msg)

    #print(t_letter,t_number)
    #print(decipher_text)

    if "FUHRER" in decipher_text:
        print("Message decoded!")
        print(decipher_text)
        print("Numbers ",t_number)
        print("Letters ",t_letter)

        return True

    return False


if __name__ == "__main__":
    #* the message to decipher
    msm = open ('message.txt','r')
    message = msm.read()
    message = message.upper()
    msm.close()
    start_time = time.time()

    Initial = list(string.ascii_uppercase)
    Initial_combination = list(itertools.product(Initial,repeat=3))

    Rotors = [1,2,3,4,5,6,7,8]
    Rotors_combination = list(itertools.permutations(Rotors,r=3))
    all_combinations = list(itertools.product(Initial_combination, Rotors_combination))

    #* Enigma default config 
    # (This is what we need to find in our program)

    #* Rotors initial pos
    # initial = ('A','B','C') # Objective
    # Omitimos la ñ, dado que trabajamos con el alfabeto inglés
    #rotors_letter = ("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
    #initial = rotors_initial_pos(rotors_letter) # Get all permutations with three-letters

    #* Rotors order
    # rotors = (4,1,3) # Objective
    #rotors_number = (0,1, 2, 3, 4, 5, 6, 7, 8)
    #rotors = rotors_order(rotors_number)


    # ! FALTA DESARROLLAR EL BUCLE ANIDADO PARA PROBAR LAS CONFIGURACIONES
    # ! Es aquí dónde usare: multiprocessing.process
    # * https://rico-schmidt.name/pymotw-3/multiprocessing/basics.html
    #advance = 1
    #('A', 'C', 'D') (3, 7, 5)

    # Parallelizing
    comm = MPI.COMM_WORLD
    rank = comm.Get_rank() # the rank of each core
    size = comm.Get_size()# size of cores

    data_per_rank = len(all_combinations)
    num_per_rank = data_per_rank // size #1476384 per core if there are 4
    start_bound = 0
    # split for the cores 
    lower_bound = start_bound + rank * num_per_rank
    upper_bound = start_bound + (rank + 1) * num_per_rank

    comm.Barrier()


    for i in range(lower_bound, upper_bound):
        check = comprobar(all_combinations[i][0],all_combinations[i][1],message)
        if check:
            break



#    for combination in all_combinations:
#            check = comprobar(combination[0],combination[1],message)
#            if check:
#                break


    #rotors_letter_pos(rotors_letter,rotors_number,3,message)

    print("--- %s seconds --- " %(time.time() - start_time))














