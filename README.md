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

Clone this repository and access to PythonScripts Folder, type and run in a terminal `python combination.py` to create all enigma machine combinations. On this occasion we only use 5904428 combinations.

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

