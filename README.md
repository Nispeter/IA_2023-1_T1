# Tarea 1: Busquedas
IA_2023-1\
Nicolas Parra Garcia

## Uso
g++ main.cpp DFS.cpp BCU.cpp Greedy.cpp AStar.cpp -o search\
./search        ->linux\
.\search.exe    ->windows


## Condiciones de funcionamiento 
El parser lee el input desde el archivo "input.txt"
Los nodos del grafo de busqueda deben ser secuenciales.\
    A B C D  (bueno)\
    A B D C  (bueno)\
    A D C E  (malo)\
Los nombres de los nodos del grafo deben ser nombrados con maximo un caracterde largo.\
Las heuristicas deben ser entregadas en orden alfabetico.

### Warning
El codigo no es muy elegante :/
EL PARSER NO CONCIDERA ESPACIOS PARA EL INPUT DE LOS COSTOS -> <nodo>,<nodo>,<costo>
