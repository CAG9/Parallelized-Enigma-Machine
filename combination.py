#!/usr/bin/env python3
"""
License GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
Contact:
    César Arcos González: cesar99ag@comunidad.unam.mx 
    Brian Kalid García Olivo: briankalid@comunidad.unam.mx
    José Vidal Cardona Rosas: ladivcr@comunidad.unam.mx
"""
import itertools
import string
import numpy as np 
import pandas as pd

Initial = list(string.ascii_uppercase)
Initial_combination = list(itertools.product(Initial,repeat=3))
Rotors = [1,2,3,4,5,6,7,8]
Rotors_combination = list(itertools.permutations(Rotors,r=3))
all_combinations = list(itertools.product(Initial_combination, Rotors_combination)) 
d = {'Combinations': all_combinations}
df = pd.DataFrame(data=d)
df.to_csv("EnigmaCombinations.csv",index = False)
