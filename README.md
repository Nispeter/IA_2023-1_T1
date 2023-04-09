# Tarea 1: Busquedas
IA_2023-1\
Nicolas Parra Garcia

## Uso
g++ main.cpp DFS.cpp BCU.cpp Greedy.cpp AStar.cpp -o sarch\
./search        ->windows\
.\search.exe    ->linux


## Condiciones de funcionamiento 
Los nodos del grafo de busqueda deben ser secuenciales.\
    A B C D  (bueno)\
    A B D C  (bueno)\
    A D C E  (malo)\
Los nombres de los nodos del grafo deben ser nombrados con maximo un caracterde largo.\
Las heuristicas deben ser entregadas en orden alfabetico.

### Warning
Este es de los peores codigos que he hecho, principalmente por las malas practicas , los arreglos baratos en el codigo y la legibilidad.