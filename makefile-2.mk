grafica.png : grafica.py datos.dat
    python grafica.py 
datos.dat : a.out
    ./a.out > datos.dat
a.out : BlandonValentina_Ejercicio29.cpp
    c++ BlandonValentina_Ejercicio29.cpp