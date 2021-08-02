# Parallelized-Enigma-Machine

## **Index**
<ul>
  <li><a href="#Authors">Authors</a></li>
  <li><a href="#Licence">Licence</a></li>
  <li><a href="#General Objectives">General Objectives</a></li>
  <li><a href="#Requirements">Requirements</a></li>
  <li><a href="#Installation">Installation</a></li>
  <li><a href="#Run">Run</a></li>
  <li><a href="#Results">Results</a></li>
  
</ul>

<center><h1><strong><a name = "Authors">Authors information</a></strong></h1></center>

* César-Arcos-González -- cesar99ag@comunidad.unam.mx -- [![Github](https://img.shields.io/badge/-racec9999-black?style=flat-square&logo=Github&logoColor=white&link=https://www.github.com/in/Cesar-p-singh/)](https://github.com/racec9999) -- [![Linkedin: César Arcos](https://img.shields.io/badge/-César_Arcos-blue?style=flat-square&logo=Linkedin&logoColor=white&link=https://www.linkedin.com/in/Cesar-p-singh/)](https://www.linkedin.com/in/cesar-arcos/)

 
* Brian-Kalid-García-Olivo -- briankalid@comunidad.unam.mx -- [![Github](https://img.shields.io/badge/-briankalid-black?style=flat-square&logo=Github&logoColor=white&link=https://www.github.com/in/Brian-p-singh/)](https://github.com/briankalid/) -- [![Linkedin: Brian Kalid García Olivo](https://img.shields.io/badge/-Brian_Kalid_García_Olivo-blue?style=flat-square&logo=Linkedin&logoColor=white&link=https://www.linkedin.com/in/Kalid-p-singh/)](https://www.linkedin.com/in/briankalid/)

* José-Vidal-Cardona-Rosas -- ladivcr@comunidad.unam.mx -- [![Github](https://img.shields.io/badge/-Ladivcr-black?style=flat-square&logo=Github&logoColor=white&link=https://www.github.com/in/Vidal-p-singh/)](https://github.com/Ladivcr/) -- [![Linkedin: José Vidal Cardona Rosas](https://img.shields.io/badge/-José_Vidal_Cardona_Rosas-blue?style=flat-square&logo=Linkedin&logoColor=white&link=https://www.linkedin.com/in/Vidal-p-singh/)](https://www.linkedin.com/in/jos%C3%A9-vidal-cardona-rosas-006010179/)


<center><h1><strong><a name = "Licence">Licence</a></strong></h1></center>

**GNU General Public License v3.0**

<center><h1><strong><a name = "General Objectives">General Objectives</a></strong></h1></center> 

* Understand the Enigma Machine
* Simulate the Enigma Machine
* Implement a Decipher
* Minimize the time by parallelizing the enigma machine decipher


<center><h1><strong><a name = "Requirements">Requirements</a></strong></h1></center> 

This project was develop in Linux

- Python 3  `sudo apt-get install python3.8`
- Numpy `pip install numpy` or `conda install numpy`
- Pandas `pip install pandas` or `conda install pandas`
- Mpi4py `pip install mpi4py` or `conda install -c anaconda mpi4py`
- 4 cores CPU

<center><h1><strong><a name = "Installation">Installation</a></strong></h1></center> 

1. Clone this repository 
2. Access to PythonScripts Folder
3. Type and run in a terminal `python combination.py` to create all enigma machine combinations.

> On this occasion we only use <a name="combination">5904428 combinations</a>.

<center><h1><strong><a name = "Run">Run</a></strong></h1></center> 

Open a terminal and move to the folder "PythonScripts" and run sequentially the following commands:

* python DecipherV2.py
* mpiexec -np 2 python ParallelizedDecipher.py 
* mpiexec -np 3 python ParallelizedDecipher.py
* mpiexec -np 4 python ParallelizedDecipher.py

Ensure your pc have at least 2 cores to run the previous commands.

<center><h1><strong><a name = "Results">Results</a></strong></h1></center> 


| Results Cores  | 1 Core         | 2 Cores                     | 3 Cores                  | 4 Cores |
| --- | --- | ---           | ---            | --- |
|  Script       |  DecipherV2.py | ParallelizedDecipher.py |ParallelizedDecipher.py   | ParallelizedDecipher.py |
| Time          | 220.4618 seconds| 233.5454 seconds | 345.6484 seconds            | 417.2356 seconds |

Recall that we are working with <a href="#combination">5904428</a> combinations. The reason for this
is because we have had to limit the number of combinations because we have very little processing power available to us. 
processing power we have at our disposal is very little. 


"Depending on the model (M3 or M4), the system had 3 or 4 rotors. The second and third rotors moved toward a nut when the previous rotor had made a full turn. There was also a socket panel that mixed the letters of the alphabet and a projector that sent the current to the rotors before displaying the results.

In total, for the Enigma machines equipped with 26 letters, there were 17,576 combinations (26 x 26 x 26) related to the orientation of each of the three rotors, 6 possible combinations related to the order of the rotors, and thus 100,391. 791,500 possible connections when connecting the six pairs of letters on the socket panel: 12 letters chosen out of 26 (26! /(12!14!)), then 6 letters out of 12 (12!/6!), and since some pairs were the same (A/D and D/A), it was necessary to divide by 26. 


Therefore, the Enigma machines could encrypt a text using 1016 (17,576 * 6 * 100,391,791,791,500) different combinations!". _[La máquina Enigma: Historia y funcionamiento, Carlos López Jurado](https://es.ccm.net/contents/131-criptografia-enigma)_

As can be seen from the results obtained. The calculation time is very long for the number of combinations we have.
If we work with all the combinations, even if we parallelize the code and it could try one combination per second, it would take years. 
It would take years. 

That's why we had to limit the combinations.

# References

- [itertools](https://docs.python.org/3/library/itertools.html#itertools.combinations)

- [Cracking Enigma](https://www.youtube.com/watch?v=RzWB5jL5RX0)

- [Breaking the Enigma: What if Turing had Python](https://www.youtube.com/watch?v=Ibwp5Ny46fk)

- [Exploring of an enigma](https://plus.maths.org/content/exploring-enigma)

- [Breaking the Enigma Code in Python with MCMC](https://towardsdatascience.com/breaking-the-enigma-code-in-python-with-mcmc-marvel-themed-9ceb358dd8ae)

- [Breaking Enigma](https://courses.csail.mit.edu/6.857/2018/project/lyndat-nayoung-ssrusso-Enigma.pdf)